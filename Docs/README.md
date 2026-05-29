# ATTN_unit
A smart desk companion that tracks your focus using sound, motion, and time. It gives real-time feedback, builds study streaks, and adapts to your habits to help you stay locked in. Stay focused. It’s watching.
It is a device that helps you focus while studying, working etc. The main purpose of this device is to gameify maintaining focus and helps us achieve concentration.

# Overview
Fitted with the **Esp32 Dev Board**, **ATTN_unit** uses **I2S MEMS Breakout Board** and **HLK-LD2410** sensors to read the noise levels and movment of the user and gives out the **Focus Score** of the user and also displays corresponding emotions the **2.13 Inch E-Ink Display**. It includes a **2 pin tactile switch** to start or stop a study session.

<img width="520" height="317" alt="hero_shot" src="https://github.com/user-attachments/assets/b29451ed-53b7-4a62-97ad-0336ba9b79fc" />

# How it works
This project has four key elements:

**1. Memory**
>It uses an ESP32 so basically in - built memory that stays even after restart. It uses memory data for long term analysis.

**2. Personality:**
>Yes! it has a personality you can influence its personality. For example, if you are distracted a lot of the times it is more stricter on you and if your more focused on the other hand, it is more kind..

**3. Sensor Reading:**
>It reads data from various sensors on the esp namely - microphone(noise level), motion sensor(for your movment sensation) and also a push button(to start or end session).

**4. Reward Logic**
>This the highlight of my project. There is one core factor - **consistency score** which is affected by many factors such as your **focus**, the **noise level** in your environment, your **movment** - how much you fidget around and its **state **_(which is affected by noise level, focus and motion)._

## Firmware Logic
The code contains a lot of **variables** and custom **functions**. It has a **Scoring System** and also contains **Memory**. The UI is good and it contains a character called **EYES** who always keeps watch on you and craves for your **attention**.

<img width="340" height="280" alt="pcb" src="https://github.com/user-attachments/assets/a6cb59ec-8942-404e-98d0-a8a51e8ef865" />

### Structure
When we come to the hardware side, ATTN_unit contains two parts:
1. **Part A:** The Front Panel with the screen bezel and the screen itself.
2. **Part B:** The main container that holds the PCB and to which the Part A is snapped onto

### Connection Methods
There are two types of connection methods used in this project
1. **Snap-in Locks-**
  - It is used to fit Part A and B together.
  - It is used to fit the display onto its bezel.

2. **M3 Heat Inserts-**
  - They are used to connect the PCB with Part B.


# Steps to Build ATTN_unit
**All the required materials to make the project can be found in the BOM file!!**

1. Start by mounting the **PCB** ( You can find the design files for it [here](https://github.com/vineethjkatti-tech/ATTN_unit/tree/main/KICAD) ) to Part A using  4 **M3 Screws** and **M3 Inserts**. You need **Heat Insert** equipment to do this.
2. Mount the **Glass Pane** to Part A using 4 **M2 Screws** and **M2 Inserts**.
3. Next mount the stand to Part A using 4 **M2 Screws** and **M2 Inserts**.
4. Connect the **USB Port** to a switchboard and then you are done!!.

**All CAD files can be found [here](https://github.com/vineethjkatti-tech/ATTN_unit/tree/main/CAD)**

# Why this Project?
In a world with thousands of distractions around us, it is hard for students to focus and concentrate on studying. These study sessions are often plain and lack something **fun**. This lack of _fun_ is satisfied by our **ATTN_unit**. It makes studying feel like a game by introducing **Focus Score** and others such elements that **encourage** students to study.



