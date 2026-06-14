#include <Arduino.h>
#include <Wire.h>
#include <driver/i2s.h>
#include <GxEPD2_BW.h>
#include <Fonts/FreeMonoBold9pt7b.h>
#include <Fonts/FreeMonoBold12pt7b.h>

#define BUTTON_PIN 0
#define PRESENCE_PIN 16

#define I2S_WS 27
#define I2S_SD 33
#define I2S_SCK 26
#define I2S_PORT I2S_NUM_0

#define EPD_CS 5
#define EPD_DC 17
#define EPD_RST 16
#define EPD_BUSY 13

GxEPD2_BW<GxEPD2_213_B73, GxEPD2_213_B73::HEIGHT> display(
  GxEPD2_213_B73(EPD_CS, EPD_DC, EPD_RST, EPD_BUSY)
);

enum FocusState { IDLE, FOCUSED, DRIFTING, DISTRACTED };

bool sessionActive = false;
FocusState state = IDLE;
FocusState lastState = IDLE;

int focusScore = 100;
int noisePenalty = 0;
int motionPenalty = 0;
int consistencyBonus = 0;

uint32_t startTime = 0;
uint32_t currentTime = 0;
uint32_t lastDisplayUpdate = 0;
uint32_t lastStateChangeTime = 0;
uint32_t lastFocusStableTime = 0;
uint32_t distractedSince = 0;
uint32_t takeoverStartTime = 0;

bool showFullMessage = false;
bool displayDirty = true;

float audioRmsSmoothed = 0.0f;
int presenceStable = 0;

const int I2S_SAMPLES = 256;
int32_t i2sBuffer[I2S_SAMPLES];

const char* stateText(FocusState s) {
  switch (s) {
    case FOCUSED: return "FOCUSED";
    case DRIFTING: return "DRIFTING";
    case DISTRACTED: return "DISTRACTED";
    default: return "IDLE";
  }
}

const char* emojiText(FocusState s) {
  switch (s) {
    case FOCUSED: return "(^*^)";
    case DRIFTING: return "(-*-)";
    case DISTRACTED: return "(T_T)";
    default: return "(._.)";
  }
}

const char* messageText(FocusState s) {
  switch (s) {
    case FOCUSED: return "Locked In!";
    case DRIFTING: return "Stay With Me Now....";
    case DISTRACTED: return "Focus Up!";
    default: return "Press Button";
  }
}

void setupI2SMic() {
  i2s_config_t i2s_config = {
    .mode = (i2s_mode_t)(I2S_MODE_MASTER | I2S_MODE_RX),
    .sample_rate = 16000,
    .bits_per_sample = I2S_BITS_PER_SAMPLE_32BIT,
    .channel_format = I2S_CHANNEL_FMT_ONLY_LEFT,
    .communication_format = I2S_COMM_FORMAT_I2S,
    .intr_alloc_flags = ESP_INTR_FLAG_LEVEL1,
    .dma_buf_count = 4,
    .dma_buf_len = 256,
    .use_apll = false,
    .tx_desc_auto_clear = false,
    .fixed_mclk = 0,
  };

  i2s_pin_config_t pin_config = {
    .bck_io_num = I2S_SCK,
    .ws_io_num = I2S_WS,
    .data_out_num = I2S_PIN_NO_CHANGE,
    .data_in_num = I2S_SD
  };

  i2s_driver_install(I2S_PORT, &i2s_config, 0, NULL);
  i2s_set_pin(I2S_PORT, &pin_config);
  i2s_zero_dma_buffer(I2S_PORT);
}

float readMicRms() {
  size_t bytesRead = 0;
  float sumSq = 0.0f;

  if (i2s_read(I2S_PORT, i2sBuffer, sizeof(i2sBuffer), &bytesRead, pdMS_TO_TICKS(10)) != ESP_OK || bytesRead == 0) {
    return audioRmsSmoothed;
  }

  int samples = bytesRead / sizeof(int32_t);
  for (int i = 0; i < samples; i++) {
    int32_t sample = i2sBuffer[i] >> 8;
    float v = (float)sample;
    sumSq += v * v;
  }

  return sqrt(sumSq / max(1, samples));
}

int mapNoiseToPenalty(float rms) {
  float normalized = constrain(rms / 3000.0f, 0.0f, 1.0f);
  int level = (int)(normalized * 100.0f);

  if (level < 20) return 0;
  if (level < 50) return 10;
  if (level < 80) return 25;
  return 40;
}

void readSensors() {
  float rms = readMicRms();
  audioRmsSmoothed = (audioRmsSmoothed * 0.85f) + (rms * 0.15f);

  int presence = digitalRead(PRESENCE_PIN);
  if (presence == HIGH) {
    presenceStable = min(presenceStable + 1, 10);
  } else {
    presenceStable = max(presenceStable - 1, 0);
  }
}

void updateFocus() {
  if (!sessionActive) {
    focusScore = 0;
    noisePenalty = 0;
    motionPenalty = 0;
    consistencyBonus = 0;
    return;
  }

  readSensors();

  noisePenalty = mapNoiseToPenalty(audioRmsSmoothed);
  motionPenalty = (presenceStable >= 6) ? 0 : (presenceStable >= 3 ? 15 : 40);

  int provisionalScore = 100 - noisePenalty - motionPenalty + consistencyBonus;
  provisionalScore = constrain(provisionalScore, 0, 100);

  FocusState provisional;
  if (provisionalScore > 80) provisional = FOCUSED;
  else if (provisionalScore > 50) provisional = DRIFTING;
  else provisional = DISTRACTED;

  if (provisional == FOCUSED) {
    if (currentTime - lastFocusStableTime > 10000) {
      consistencyBonus = min(consistencyBonus + 1, 15);
      lastFocusStableTime = currentTime;
    }
  } else {
    consistencyBonus = 0;
    lastFocusStableTime = currentTime;
  }

  focusScore = 100 - noisePenalty - motionPenalty + consistencyBonus;
  focusScore = constrain(focusScore, 0, 100);
}

void updateState() {
  FocusState newState;

  if (!sessionActive) newState = IDLE;
  else if (focusScore > 80) newState = FOCUSED;
  else if (focusScore > 50) newState = DRIFTING;
  else newState = DISTRACTED;

  if (newState != state && (currentTime - lastStateChangeTime > 2000 || state == IDLE)) {
    lastState = state;
    state = newState;
    lastStateChangeTime = currentTime;
    showFullMessage = true;
    takeoverStartTime = currentTime;
    displayDirty = true;
  }
}

void updateSessionLogic() {
  if (!sessionActive) {
    distractedSince = 0;
    return;
  }

  if (state == DISTRACTED) {
    if (distractedSince == 0) distractedSince = currentTime;
  } else {
    distractedSince = 0;
  }
}

void drawMainScreen() {
  display.setFullWindow();
  display.firstPage();
  do {
    display.fillScreen(GxEPD_WHITE);

    display.setFont(&FreeMonoBold9pt7b);
    display.setTextColor(GxEPD_BLACK);

    display.setCursor(0, 14);
    display.print(stateText(state));

    display.setCursor(0, 30);
    display.print("F:");
    display.print(focusScore);

    display.setCursor(0, 46);
    display.print("T:");
    display.print(sessionActive ? (currentTime - startTime) / 1000 : 0);

    display.setCursor(0, 60);
    display.print(messageText(state));

    display.setFont(&FreeMonoBold12pt7b);
    display.setCursor(78, 28);
    display.print(emojiText(state));

    int barWidth = map(focusScore, 0, 100, 0, 120);
    display.drawRect(0, 54, 120, 8, GxEPD_BLACK);
    display.fillRect(0, 54, barWidth, 8, GxEPD_BLACK);
  } while (display.nextPage());
}

void drawTakeoverScreen() {
  display.setFullWindow();
  display.firstPage();
  do {
    display.fillScreen(GxEPD_WHITE);
    display.setFont(&FreeMonoBold12pt7b);
    display.setTextColor(GxEPD_BLACK);
    display.setCursor(0, 28);
    display.print(messageText(state));
    display.setFont(&FreeMonoBold9pt7b);
    display.setCursor(0, 58);
    display.print(stateText(state));
  } while (display.nextPage());
}

void updateDisplay() {
  if (!displayDirty && (currentTime - lastDisplayUpdate < 1000)) return;
  lastDisplayUpdate = currentTime;

  if (showFullMessage && currentTime - takeoverStartTime < 5000) {
    drawTakeoverScreen();
  } else {
    showFullMessage = false;
    drawMainScreen();
  }

  displayDirty = false;
}

void updateInputs() {
  static bool lastButtonState = HIGH;
  static uint32_t lastDebounceTime = 0;
  bool reading = digitalRead(BUTTON_PIN);

  if (reading != lastButtonState) lastDebounceTime = currentTime;

  if ((currentTime - lastDebounceTime) > 50) {
    if (lastButtonState == HIGH && reading == LOW) {
      sessionActive = !sessionActive;

      if (sessionActive) {
        startTime = currentTime;
        consistencyBonus = 0;
        lastFocusStableTime = currentTime;
      }

      displayDirty = true;
    }
  }

  lastButtonState = reading;
}

void setup() {
  Serial.begin(115200);
  pinMode(BUTTON_PIN, INPUT_PULLUP);
  pinMode(PRESENCE_PIN, INPUT);
  Wire.begin();

  setupI2SMic();

  display.init(115200);
  display.setRotation(1);
  display.setTextColor(GxEPD_BLACK);

  display.setFullWindow();
  display.firstPage();
  do {
    display.fillScreen(GxEPD_WHITE);
  } while (display.nextPage());

  displayDirty = true;
}

void loop() {
  currentTime = millis();
  updateInputs();
  updateFocus();
  updateState();
  updateSessionLogic();
  updateDisplay();
}
