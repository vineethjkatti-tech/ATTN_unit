# ATTN_unit
A smart desk companion that tracks your focus using sound, motion, and time. It gives real-time feedback, builds study streaks, and adapts to your habits to help you stay locked in. Stay focused. It’s watching.
It is a device that helps you focus while studying, working etc. The main purpose of this device is to gameify maintaining focus and helps us achieve concentration.

# Overview
Fitted with the **Esp32 Dev Board**, ATTN_unit uses **I2S MEMS Breakout Board** and **HLK-LD2410** sensors to read the noise levels and movment of the user and gives out the **Focus Score** of the user and also displays corresponding emotions on the **2.13 Inch E-Ink Display**. It includes an **8mm momentary switch** to start or stop a study session.

<img width="1920" height="832" alt="ATTN_unit (revised)" src="https://github.com/user-attachments/assets/72a3dec0-157c-4f44-84e3-f15502b3c370" />

## Zine Page
<img width="421" height="643" alt="ATTN_unit-zine (2)" src="https://github.com/user-attachments/assets/3726ded5-dd08-4c62-8b0e-cf96a01cff12" />

_Check out my zine page_ [here!!](https://github.com/vineethjkatti-tech/ATTN_unit/blob/main/Production/ATTN_unit-zine.pdf)


# How it works
This project has four key elements:

**1. Memory**
>It uses an ESP32 so basically in - built memory that stays even after restart. It uses memory data for long term analysis.

**2. Personality:**
>Yes! it has a personality, and you can slightly influence it too! For example, if you are distracted a lot of the times it is more stricter on you, and if your more focused on the other hand, it is more lenient..

**3. Sensor Reading:**
>It reads data from various sensors on the board, namely - **I2S MEMS Mic** (noise level), **HLK-LD2410C** (to sense your movement) and also a **Push Button** (to start or end session).

**4. Reward Logic**
>This is the highlight of my project. There is one core factor - **consistency score** which is affected by many factors such as your **focus**, the **noise level** in your environment, your **movement** - how much you fidget around and the device's **state**_(which is affected by noise level, focus and motion)._

## Firmware Logic
The firmware contains a series of **variables** and custom **functions**. It uses a **Scoring System** as you know. The UI of the display contains an ASCII emoji that changes based on your focus level. So, stay focused and don't dissapoint **EYES**! (the name of the emoji apparently).

<img width="800" height="448" alt="hero_shot" src="https://github.com/user-attachments/assets/11ec5889-8c2a-47e0-abaf-7221a2a96796" />


### Structure
When we come to the hardware side, ATTN_unit contains two parts:
1. **Part A:** The Front Panel with the screen bezel and the screen itself.
2. **Part B:** The main container that holds the PCB and to which the Part A is snapped onto

**Connection Methods:**
There are two types of connection methods used in this project
1. **Snap-in Locks-**
  - It is used to fit Part A and B together.
  - It is used to fit the display onto its bezel.

2. **M3 Heat Inserts-**
  - They are used to connect the PCB with Part B.

**Display:**
As the **2.13 Inch 2 color E-Ink display** fits easily onto the raspberry pi, you have to keep in mind some things while connecting it to an ESP32.
The JST on the display accomodates **8-sockets** as you may know. I have provided an **8-pin header** on my PCB which has the same pin designations as the JST on the the display. The JST can be connected to the headers on the PCB using jumper wires. 

**Note: the 3D Model used in the CAD is the 3-color model because I was unable to find the 2-color one. But, it is intended that the 2-color model is to be used.**


# Steps to Build ATTN_unit
**All the required materials to make the project can be found in the BOM file!!**

1. Start by printing all the required plastic material. (All CAD files can be found [here](https://github.com/vineethjkatti-tech/ATTN_unit/tree/main/CAD))

2. Next, mount the PCB (it doesnt matter if you solder one, you can find all the schematics [here](https://github.com/vineethjkatti-tech/ATTN_unit/tree/main/KICAD)) to the standoffs in **Part B** using **M3 Inserts and Screws**.

3. After that put the display into Part A by just pressing it in ( the Part has snap-in locks in the bezel space ). Connect the JST (8-pin) of the Display to the 8-pin header on the PCB using **Jumper Wires**.

4. Then screw an **8mm momentary switch** through the hole in the **right side** of **Part B**. Solder the two pins to their resepctive pins on ESP32 using wores (One to **GND** and another one to any free **GPIO pin**).

5. After this connect the **Front Panel** and **Part B** by pressing them into each other cause they have **snap-in locks**.

6. Last step is to connect the ESP32 to a USB Port for Power Supply and your done!!

**_If you followed all the steps, then congrats!! Your ATTN_unit is ready. Enjoy your fulfilling and focus-filled study sessions!!_**

Note:
_Do not connect any two wires to the same GPIO as it may shot the board and burn components_

_Refer the Gallery If you don't understand anything_

# Why this Project?
In a world with thousands of distractions around us, it is hard for students to focus and concentrate on studying. These study sessions are often plain and lack something **fun**. This lack of _fun_ is satisfied by our **ATTN_unit**. It makes studying feel like a game by introducing **Focus Score** and others such elements that **encourage** students to study.

# Gallery

**Pinout Schematic:**
<img width="3508" height="2480" alt="image" src="https://github.com/user-attachments/assets/d1683796-7e5c-473e-8bd0-194e3717b94a" />

**Display to Board Connection:**
<img width="1280" height="720" alt="ATTN_unit (revised)" src="https://github.com/user-attachments/assets/6f691a1f-06a3-4669-99d4-20506fcd566a" />


