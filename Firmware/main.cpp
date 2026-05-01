#include <Arduino.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

//===========Display Config============
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

//===========System Vaiables===========
bool sessionActive = false;
int focusSCORE = 100;
String state = "Ready";
String message = "Press button to start";

//===========Sensor Variables===========
int noiseLevel = 0;
int motionLevel = 0;

int noisePenalty = 0;
int motionPenalty = 0;

int consistencyBonus = 0;

//===========Time Variables===========
unsigned long startTime = 0;
unsigned long currentTime = 0;

unsigned long lastDisplayUpdate = 0;
unsigned long lastFocusStableTime = 0;
unsigned long lastdistractedStartTime = 0;


//===========Function Declarations===========
void updateInputs();
void updateFocus();
void updateState();
void updatePersonality();
void updateDisplay();
void readSensors();

//===========Setup============
void setup() {
  Serial.begin(1150200);
  pinMode(0, INPUT_PULLUP); //Button (GPIO 0)

  Wire.begin();

  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println("OLED Failed");
    while (true); //stops if display fails
  }

  display.clearDisplay();
  display.display();
}
//===========Main Loop===========
void loop() {
  currentTime = millis();

  updateInputs();
  updateFocus();
  updateState();
  updatePersonality();
  updateDisplay();
}

//===========Input System===========
void updateInputs() {
  static bool lastButtonState = HIGH;
  bool buttonState = digitalRead(0);

  if(lastButtonState == HIGH && buttonState == LOW) {
    sessionActive = !sessionActive;
    
    if(sessionActive) {
      startTime = currentTime;
      consistencyBonus = 0;
    }
  }
  lastButtonState = buttonState;
}

//===========Sensor Simulation===========
void readSensors() {
  //Simulated values (replace later with real sensors)
  noiseLevel = random(0, 100);
  motionLevel = random(0, 100);
}

//============Focus Engine===========
void updateFocus() {
  if (!sessionActive) {
    focusSCORE = 0;
    return;
  }

  readSensors();

  //============Noise Penalty===========
  if (noiseLevel < 20) noisePenalty = 0;
  else if (noiseLevel < 50) noisePenalty = 10;
  else if (noiseLevel < 80) noisePenalty = 25;
  else noisePenalty = 40;

  //============Motion Penalty===========
  if (motionLevel < 20) motionPenalty = 0;
  else if (motionLevel < 50) motionPenalty = 10;
  else if (motionLevel < 80) motionPenalty = 25;
  else motionPenalty = 40;

  //------------Consistency Bonus------------
  if (state == "FOCUSED") {
    if (currentTime - lastFocusStableTime > 10000) {
      consistencyBonus++;
      lastFocusStableTime = currentTime;
    }
  } else {
    consistencyBonus = 0;
    lastFocusStableTime = currentTime;
  }

  if (consistencyBonus > 15) consistencyBonus = 15;

  //----Final Score------
  focusSCORE = 100 - noisePenalty - motionPenalty + consistencyBonus;

  if (focusSCORE > 100) focusSCORE = 100;
  if (focusSCORE < 0) focusSCORE = 0;
}

//============State System===========
void updateState() {
  if (!sessionActive) {
    state = "IDLE";
  } else if (focusSCORE > 80) {
    state = "FOCUSED";
  } else if (focusSCORE > 50) {
    state = "DRIFTING";
  } else {
    state = "DISTRACTED";
  }
}

//============Personality Engine============
void updatePersonality() {
  if (state == "FOCUSED") {
    message = "Locked In";
  } else if (state == "DRIFTING") {
    message = "Careful...";
  } else if (state == "DISTRACTED") {
    if (lastdistractedStartTime == 0) {
      lastdistractedStartTime = currentTime;
    }

    if (currentTime - lastdistractedStartTime > 30000) {
      message = "Get it together!";
    } else {
      message = "Focus up!";
    }

  } else {
    message = "Press button to start";
    lastdistractedStartTime = 0;
  }
}

//============Display============
void updateDisplay() {
  if (currentTime - lastDisplayUpdate > 1000) {

    lastDisplayUpdate = currentTime;

    display.clearDisplay();

    display.setTextSize(1);
    display.setTextColor(SSD1306_WHITE);

    // State
    display.setCursor(0, 0);
    display.print("State: ");
    display.print(state);

    //Focus Score
    display.setCursor(0, 10);
    display.print("Focus: ");
    display.print(focusSCORE);

    //Time
    display.setCursor(0, 20);
    display.print("Time: ");
    display.print((currentTime - startTime) / 1000);

    //Message
    display.setCursor(0, 30);
    display.print(message);

    //Focus Bar
    int barWidth = map(focusSCORE, 0, 100, 0, 120);

    display.drawRect(0, 55, 120, 8, SSD1306_WHITE);
    display.fillRect(0, 55, barWidth, 8, SSD1306_WHITE);

    display.display();
  }
}