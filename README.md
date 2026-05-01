# ATTN_unit
A smart desk companion that tracks your focus using sound, motion, and time. It gives real-time feedback, builds study streaks, and adapts to your habits to help you stay locked in. Stay focused. It’s watching.


# How it works
This project has four key elements:

**1. Memory**
>It uses an ESP32 so basically in - built memory that stays even after restart. It uses memory data for long term analysis.

**2. Personality:**
>Yes! it has a personality you can influence its personality. Foer example, if you are distracted a lot of the times it is more stricter on you and if your more focused on the other hand, it is more kind..

**3. Sensor Reading:**
>It reads data from various sensors on the esp namely - microphone(noise level), motion sensor(for your movment sensation) and also a push button(to start or end session).

**4. Reward Logic**
>This the highlight of my project. There is one core factor - consistency score which is affected by many factors such as your focus, the noise level in your environment, your movment - how much you fidget around and its state (which is affected by noise level, focus and motion).
