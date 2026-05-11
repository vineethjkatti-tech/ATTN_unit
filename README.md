# ATTN_unit
A smart desk companion that tracks your focus using sound, motion, and time. It gives real-time feedback, builds study streaks, and adapts to your habits to help you stay locked in. Stay focused. It’s watching.
It is a device that helps you focus while studying, working etc. The main purpose of this device is to gameify maintaining focus and helps us achieve concentration.

# Overview
Fitted with the **Esp32 Dev Board**, **ATTN_unit** uses **KY038** and **HLK-LD2410** sensors to read the noise levels and movment of the user and gives out the **Focus Score** of the user and also displays corresponding emotions the **OLED display**. 
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
The code contains a lot of **variables** and custom **functions**. It has a **Scoring System** and also contains **Memory**. The UI is good and it contains a character called **EYES** who always keeps watch on you and carves for your **attention**.

