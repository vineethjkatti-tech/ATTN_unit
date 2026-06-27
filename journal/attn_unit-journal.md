# ATTN_unit — Journal Export

- Exported at: 2026-06-19T10:40:41Z
- Project ID: 2838
- Entries: 20

## Entry 1
- ID: 5100
- Author: vivacious_eye
- Created At: 2026-05-02T11:52:36Z

### Content

**day_1**
### Editing my README and Getting started with the pcb
This is my second project.. lessgooo!!
I first uploaded my code into my repo. **Sadly I didn't record myself coding cause I thought I could use hackatime. So, I lost about 2 hours of work** But, More hours for me anyways.
I started adding a description in my repo which took me about 13 mins.
I added info on how it works and what _sensors_ it uses and also what makes my project _different_ from _others'_

![image.png](https://github.com/vineethjkatti-tech/ATTN_unit/blob/main/journal/journal-images/Screenshot%202026-06-27%20110646.png)

Next I began designing my _PCB_. 
I added the footprints of - **MPU6050**, **KY038**, I couldn't find the footprint for ESP32(more on that later) and also I didn't find the exact footprint for the display so I added a _ 4 pin socket for it._

But as I was looking for the footprint of the esp32 I needed I couldn't find it. To be specific I wanted the **ESP - 32 - NodeMCU full dev board. I couldn't find the footprint anywhere so I got stuck there and thought I will continue tomorrow. 

That's it for today byeee!!



*Time recorded: 1h 2m*

### Recording Links

- [timelapse (34).mp4](https://github.com/vineethjkatti-tech/ATTN_unit/blob/main/journal/timelapses/timelapse%20%2834%29.mp4)
- [timelapse (35).mp4](https://github.com/vineethjkatti-tech/ATTN_unit/blob/main/journal/timelapses/timelapse%20%2835%29.mp4)

## Entry 2
- ID: 5243
- Author: vivacious_eye
- Created At: 2026-05-03T08:10:59Z

### Content

**day_2**
### Creating and Refining the PCB design
As I didn't find the footprint for the _esp_ **anywhere** I thought I'll just add _pin sockets for the esp_ it would be like **19 pins** on each side soo.
I started by naming the pins one by one. How did I know the pins you ask - I had a board at my home so it was easy for me.
![image.png](https://github.com/vineethjkatti-tech/ATTN_unit/blob/main/journal/journal-images/Screenshot%202026-06-27%20110633.png)

_I did a fatal mistake here which cost me a lot of time (more on that later)._

Next, I assigned the footprints for all of the components and I thought it was ready to update now

![image.png](https://github.com/vineethjkatti-tech/ATTN_unit/blob/main/journal/journal-images/Screenshot%202026-06-27%20110622.png)

So, when I clicked **update pcb** in the _pcb editor_ it was like - ** Some footprints don't have their pin numbers** in the error list.
OMG I had to rewrite all pin numbers and it took me like **30 MINSSS!!**. 

Then after all the work again when I clicked Update pcb IT DIDNT DO ANYTHING!!.
There was nothing I could place......(┬┬﹏┬┬)..

When I checked to see what was wrong I hadn't saved the assigned footprints...
So, I felt a bit happy and assigned them and saved the footprints ☆*: .｡. o(≧▽≦)o .｡.:*☆

Next was the wiring the most time consuming part of this session =.= 
As the board I had had different **pin names** so I had to refer a datasheet for wiring:
![image.png](https://github.com/vineethjkatti-tech/ATTN_unit/blob/main/journal/journal-images/Screenshot%202026-06-27%20110609.png)
Here is the link for it : [Click here](https://documentation.espressif.com/esp32-wroom-32_datasheet_en.pdf)

So, I _carefully wired everything up _pin - by - pin_.
The finished product looks like this:
![image.png](https://github.com/vineethjkatti-tech/ATTN_unit/blob/main/journal/journal-images/Screenshot%202026-06-27%20110559.png)

So, after that I did some wiring (copper tracks) in the pcb editor and used **Filled Zone** for the **GND**. and at last everything was ready-
![image.png](https://github.com/vineethjkatti-tech/ATTN_unit/blob/main/journal/journal-images/Screenshot%202026-06-27%20110547.png)
![image.png](https://github.com/vineethjkatti-tech/ATTN_unit/blob/main/journal/journal-images/Screenshot%202026-06-27%20110539.png)


*Time recorded: 1h 18m*

### Recording Links

- [timelapse (36).mp4](https://github.com/vineethjkatti-tech/ATTN_unit/blob/main/journal/timelapses/timelapse%20%2836%29.mp4)

## Entry 3
- ID: 5386
- Author: vivacious_eye
- Created At: 2026-05-04T06:18:18Z

### Content

**day_3**
### Creating Footprints and Trying new code
I tried to make a **cat** for the display today yk like a _mascot_.
I created a small bitmap using piskel
![image.png](https://github.com/vineethjkatti-tech/ATTN_unit/blob/main/journal/journal-images/Screenshot%202026-06-27%20110531.png)

I used a converter to convert _image_ to _bitmap_ and converted it a to an array and pasted it in my code according to the tutorial. 
But, sadly it didn't work /_ \ . 

So, next i went on to make my own footprint instead of using pin headers cause the reviewers suggested that.
I had to watch a tutorial to make one and I first started with the **MPU6050**. I started with the dimensions and started making the symbol. As I made it I thought I had to put in through holes. But, no I had to make pins for it in the symbol and the through holes should be in the footprint instead.

it took a lot of time for the footprint mainly cause there was an issue with the **size**. Because I had put the dimensions perfectly but only _7 holes_ fit there. So, I did some surfing on google but didn't find anything so I ended up extending it to fit another hole. 
![image.png](https://github.com/vineethjkatti-tech/ATTN_unit/blob/main/journal/journal-images/Screenshot%202026-06-27%20110521.png)

After that I had finished with that footprint and symbol yayyy!! ヾ(≧▽≦*)o.

*Time recorded: 1h 45m*

### Recording Links

- [timelapse (37).mp4](https://github.com/vineethjkatti-tech/ATTN_unit/blob/main/journal/timelapses/timelapse%20%2837%29.mp4)
- [timelapse (38).mp4](https://github.com/vineethjkatti-tech/ATTN_unit/blob/main/journal/timelapses/timelapse%20%2838%29.mp4)

## Entry 4
- ID: 5604
- Author: vivacious_eye
- Created At: 2026-05-05T16:08:36Z

### Content

**day_4**
### Finishing the PCB and editing some code
I wanted to finish designing the pcb today. So, I imported the symbol and footprint of the _version_ of _ESP32_ and started working with it.
![image.png](https://github.com/vineethjkatti-tech/ATTN_unit/blob/main/journal/journal-images/Screenshot%202026-06-27%20110503.png)

But, I had an issue - I couldn't get the _.pretty_ from _GradCAD_ which is needed for the footprint. Instead I got two files with extensions - _.sym_ and _.mod_. Later when I saw a video on youtube I gtk the _right way_ to add a footprint was to go tp the editor - click on _Add New Library_ and select the _.mod_ file.
![image.png](https://github.com/vineethjkatti-tech/ATTN_unit/blob/main/journal/journal-images/Screenshot%202026-06-27%20110452.png)
_the files had these extensions_

After that I got started with making the footprint and symbol of _KY038_. I started by collecting data like - _dimensions_, _pin pitch_ etc. It took me like 10 to 15 minutes to make it and I inserted it into the schematic. Only when I inserted the symbols that I had made, I got to know that the pin directions were all _wrong_. 
(┬┬﹏┬┬). _Although it took me just 5 mins to change._

After that I imported the OLED footprints and inserted it too!!
And then at last I assigned all footprints to their respective symbols and hit _update pcb.
_







*Time recorded: 1h 14m*

### Recording Links

- [timelapse (39).mp4](https://github.com/vineethjkatti-tech/ATTN_unit/blob/main/journal/timelapses/timelapse%20%2839%29.mp4)

## Entry 5
- ID: 5723
- Author: vivacious_eye
- Created At: 2026-05-06T12:07:42Z

### Content

**day_5**
### Finishing PCB and updating come code
Today I added all the 3d models to their components in _KICAD_. 
![image.png](https://github.com/vineethjkatti-tech/ATTN_unit/blob/main/journal/journal-images/Screenshot%202026-06-27%20110443.png)

I had some issues with some models tho. When I connected the display to its model, the model simply wouldn't show up on the screen. I thought it was a rendering issue and connected and saved it. Then when I took a look at the PCB model I realized that the model was far too right in the window. Hence I didn't see it. 
![image.png](https://github.com/vineethjkatti-tech/ATTN_unit/blob/main/journal/journal-images/Screenshot%202026-06-27%20110428.png)
So, I _readjusted_ its positions and it was good to go. 

The problem was with the _KY038_ sensor - I couldn't find a 3d model of it anywhere _although I had found one but it was unusable_ (cause it SLDPRT extensions).
Then at the end I imported it into fusion and again exported as _.step_ an it _worked!!_

I also had to do some wiring and define _edge cuts_ for it. I also added a _filled zone_ for GND.
At last my PCB was _ready to go_.
![image.png](https://github.com/vineethjkatti-tech/ATTN_unit/blob/main/journal/journal-images/Screenshot%202026-06-27%20110415.png)
------------

While I was working I split into a side proj which is adding a new sensor instead _MPU6050_ - HLK-LD2410 which is a _human detecting sensor_. I changed all the wirings and updated the _schematic_.
-------------

I also had to change code cause I had changed the sensor and I also wanted to add a mascot called - **EYES**. I added new ASCII emojis and **refined** the code _immensly_.

*Time recorded: 1h 37m*

### Recording Links

- [timelapse (40).mp4](https://github.com/vineethjkatti-tech/ATTN_unit/blob/main/journal/timelapses/timelapse%20%2840%29.mp4)
- [timelapse (41).mp4](https://github.com/vineethjkatti-tech/ATTN_unit/blob/main/journal/timelapses/timelapse%20%2841%29.mp4)

## Entry 6
- ID: 5856
- Author: vivacious_eye
- Created At: 2026-05-07T06:52:51Z

### Content

**day_7**
### Getting Started with the _casing_

I started designing the case today. 
I first made some edits to the pcb - like shifting the esp a lil to the edge so the **usb port** was _accessible_ and adding **mounting holes** at the _edge_ of the PCB.
And  I also added the **BUTTON** which I had totally _forgotten_ and then imported the finished pcb into _fusion_ . The finished pcb looks like _this_ -  
![image.png](https://github.com/vineethjkatti-tech/ATTN_unit/blob/main/journal/journal-images/Screenshot%202026-06-27%20110405.png)

I started by making a _sketch_, a little wider and larger in size than the pcb. Then I thin extruded it and I was getting _somewhere_ I thought. Then I Extruded it to be fully enclosed and I had also made holes for the _screen_, _mic_ to peek out. 
![image.png](https://github.com/vineethjkatti-tech/ATTN_unit/blob/main/journal/journal-images/Screenshot%202026-06-27%20110352.png)

After that I used fillet to **round** all the edges. 
Till now I have done only this much..

*Time recorded: 1h 4m*

### Recording Links

- [timelapse (42).mp4](https://github.com/vineethjkatti-tech/ATTN_unit/blob/main/journal/timelapses/timelapse%20%2842%29.mp4)

## Entry 7
- ID: 6282
- Author: vivacious_eye
- Created At: 2026-05-09T15:57:08Z

### Content

**day_8**
### Redesigning the Casing
I deleted the previous design and I tried for a new design idea (_I would say it was successful_). I wanted to use **glass ** as the front cover and **plastic** as the main casing. I started by making the _sketch_ for the case. 
Then I made a thin (about 2mm thick) object _same _as the size of the casing and **filleted** it on only two ** parallel edges.** I then added glass (window) appearance to it. It looked **awwwsomeee** Then next I added **M2 Inserts** and screwed the **casing** and the **glass panel** together with the _PCB_ sandwiched in the middle. And now I'm planning for M3 screws to mount the PCB cause the holes are too big. 
At last I had to carve a hole into the glass for the sensor to poke out.****
![image.png](https://github.com/vineethjkatti-tech/ATTN_unit/blob/main/journal/journal-images/Screenshot%202026-06-27%20110344.png)


*Time recorded: 52 minutes*

### Recording Links

- [timelapse (43).mp4](https://github.com/vineethjkatti-tech/ATTN_unit/blob/main/journal/timelapses/timelapse%20%2843%29.mp4)

## Entry 8
- ID: 6538
- Author: vivacious_eye
- Created At: 2026-05-11T04:56:15Z

### Content

**day_9** 
### Finishing The Casing (Almost) 
I was almost gonna finish the casing today but time didn't permit.
I added M3 Inserts to mount the PCB but the M3 screw head wasn't bigger than the mounting holes on the PCB.  
![image.png](https://github.com/vineethjkatti-tech/ATTN_unit/blob/main/journal/journal-images/Screenshot%202026-06-27%20110335.png)
SO, I needed to find a screws with a bigger head. 
Finally after _15 mins_ of research I finally settled on the **Flat Head* one cause it had the widest head.
![image.png](https://github.com/vineethjkatti-tech/ATTN_unit/blob/main/journal/journal-images/Screenshot%202026-06-27%20110324.png)

Next I made a hole on the sides to plug in the **power supply***.
![image.png](https://github.com/vineethjkatti-tech/ATTN_unit/blob/main/journal/journal-images/Screenshot%202026-06-27%20110316.png)

After that, I had to make a **stand** for it ryt? So, I tried to move the whole body as one ( I wanted to tilt it at 30 degrees). But, I couldn't. Then I found out that you have to make it as a ** rigid body** and then move it. SO, I did that but still it didn't go as per me. So I thought I'll just make the stand tilted. I used M2 Inserts and Screws to mount the stand. I am going to complete the design tomorrow.




*Time recorded: 1h 2m*

### Recording Links

- [timelapse (44).mp4](https://github.com/vineethjkatti-tech/ATTN_unit/blob/main/journal/timelapses/timelapse%20%2844%29.mp4)

## Entry 9
- ID: 6891
- Author: vivacious_eye
- Created At: 2026-05-13T06:20:34Z

### Content

day_9 and 10
# Finishing the Casing and editing the README

I finished the casing today by putting in the last screws to mount the stand to part. 
I first put in the screws then designed the other two faces of the stand which took me about an hours or so. Designing it was tricky cause I had to make holes a lil smaller than the insert and also I had to make the on the opposite side so that it didn't conflict with the opposite part.
![image.png](https://github.com/vineethjkatti-tech/ATTN_unit/blob/main/journal/journal-images/Screenshot%202026-06-27%20110300.png)
_Also after I finished designing the stand I had to shift it a little down cause then the whole thing would rest on it or else it would tip off_

 Next i uploaded everything to my repo and edited the README by adding info about the firmware. I added Assets folder which contained the screenshots of the full assembly and Now I need to upload all the parts as both .step and .stl because my last project got returned for the same reason. 
![image.png](https://github.com/vineethjkatti-tech/ATTN_unit/blob/main/journal/journal-images/Screenshot%202026-06-27%20110250.png)


*Time recorded: 1h 16m*

### Recording Links

- [timelapse (45).mp4](https://github.com/vineethjkatti-tech/ATTN_unit/blob/main/journal/timelapses/timelapse%20%2845%29.mp4)
- [timelapse (46).mp4](https://github.com/vineethjkatti-tech/ATTN_unit/blob/main/journal/timelapses/timelapse%20%2846%29.mp4)

## Entry 10
- ID: 7088
- Author: vivacious_eye
- Created At: 2026-05-14T14:53:54Z

### Content

**day_11**
# Editing README and getting started with the zine page

I started by adding steps to build ATTN_unit in the README. This time I added just screwing and mounting instructions. It was quite shorter than the guide for iplanter. I mentioned which screws are used and also mentioned where the PCB, CAD and program files can be found.
![image.png](https://github.com/vineethjkatti-tech/ATTN_unit/blob/main/journal/journal-images/Screenshot%202026-06-27%20110236.png)

Next I started to design the zine page!!  which is my most favorite part of the project. Initially I wanted to use canva, but, as it didn't allow custom page size I shifted to figma which allowed it. But, in both the editors i noticed that the template given was slightly larger than actual A5 paper on which we had to design on. I started by capturing good quality image of my project, cause that is like the life of the zine. So I found out that you can capture life-like images in the Render Workspace. 
But, as expected.. the workspace crashes and I used the "capture image" tool instead, which also did the job.

Next I started by copying the Image to figma and centering it. then I added heading texts vertically instead of horizontal (cause I was using cosmos for inspiration). which turned out pretty good actually!! I next added the description. I just copy pasted the github desc, cause I had recieved feedback that too much text on zine didn't do justice. At last I added the qr code and also labelled the unit, also did some positioning changes. At last it turned out like this:
![ATTN_unit-zine (1).jpg](https://github.com/vineethjkatti-tech/ATTN_unit/blob/main/journal/journal-images/Screenshot%202026-06-27%20110226.png)


*Time recorded: 2h 19m*

### Recording Links

- [timelapse (47).mp4](https://github.com/vineethjkatti-tech/ATTN_unit/blob/main/journal/timelapses/timelapse%20%2847%29.mp4)
- [timelapse (48).mp4](https://github.com/vineethjkatti-tech/ATTN_unit/blob/main/journal/timelapses/timelapse%20%2848%29.mp4)

## Entry 11
- ID: 8002
- Author: vivacious_eye
- Created At: 2026-05-19T17:59:19Z

### Content

**day_12**
# Making Big Changes to the Project (FIRMWARE)

So, I decided that I would change the following in the project:
1. Changing KY038 with** I2S MEMS MIC Module**
2. Shifting to **2.13 inch WaveShare e - ink display (2 color)**
3. Adding **piezo electric single tune buzzer (not in this rec)
**
I first started by changing the firmware where I had to change:

The old SSD1306 format to the new e ink display.
Made big changes to the ui and I had to do major changes in** void functions**
--- 

I basically changes only the format and all the core code like the 

```
currentStartTime = currentTime;

if (lastStableFocusTime < 60)
message = "LockedIn"

```
So, it was very _productive_ today.
![image.png](https://github.com/vineethjkatti-tech/ATTN_unit/blob/main/journal/journal-images/Screenshot%202026-06-27%20110217.png)


*Time recorded: 1h 12m*

### Recording Links

- [timelapse (49).mp4](https://github.com/vineethjkatti-tech/ATTN_unit/blob/main/journal/timelapses/timelapse%20%2849%29.mp4)
- [timelapse (50).mp4](https://github.com/vineethjkatti-tech/ATTN_unit/blob/main/journal/timelapses/timelapse%20%2850%29.mp4)

## Entry 12
- ID: 8174
- Author: vivacious_eye
- Created At: 2026-05-20T16:08:00Z

### Content

**day_13**
# ReDesigning the PCB and Finishing the Code 

First of all, congrats to me!! I finished the **firmware** todayy!! And _also...._
I **redesigned the pcb** today. It was a lotta.. work like **a lot..**
I first searched up whether the new components have a **symbol** or not and I found out that only the **mic** had a symbol **not the display. **
 Things about the display I found out today:
- The fact that the display has a separate **8-pin JST-XH female connector** and the **20 pins** are just for **mounting**. 
- It is specifically made for a raspberry pi version and fits onto the pi directly with no other connections. 
- I need to make some arrangements to connect it _natively _to my esp32 devboard. 

![image.png](https://github.com/vineethjkatti-tech/ATTN_unit/blob/main/journal/journal-images/Screenshot%202026-06-27%20110157.png)

So, it was easy to wire the I2S MIC for me but it was quite difficult to wrap my head around **how to connect the display to ESP.** After a lot of research I figured that 8 pre crimped cable come with the display which I can use to connect it to my board. 
The plan: 
- I have to connect the **8 cables to a 8 pin header on the board** with tracks to the respective pins on the ESP
- It can be mounted on another **20 pin header** on the board.

![image.png](https://github.com/vineethjkatti-tech/ATTN_unit/blob/main/journal/journal-images/Screenshot%202026-06-27%20110141.png)
_The setup will look somewhat like this_

So, I imported the symbols to the workspace and for the 8 pin Header I changed the pin names to match the ones on the display. Then I wired the 8 pin headers just like how I would wire the 8 pre crimped pins on the display.

![Screenshot 2026-05-20 201744.png](https://github.com/vineethjkatti-tech/ATTN_unit/blob/main/journal/journal-images/Screenshot%202026-06-27%20110126.png)

Next, in the pcb editor, I connected all the pins to the ESP board and then filled zones for VCC and GND.
At last the PCB looks like this:
![image.png](https://github.com/vineethjkatti-tech/ATTN_unit/blob/main/journal/journal-images/Screenshot%202026-06-27%20110114.png)
![image.png](https://github.com/vineethjkatti-tech/ATTN_unit/blob/main/journal/journal-images/Screenshot%202026-06-27%20110106.png)


*Time recorded: 1h 17m*

### Recording Links

- [timelapse (51).mp4](https://github.com/vineethjkatti-tech/ATTN_unit/blob/main/journal/timelapses/timelapse%20%2851%29.mp4)
- [timelapse (52).mp4](https://github.com/vineethjkatti-tech/ATTN_unit/blob/main/journal/timelapses/timelapse%20%2852%29.mp4)

## Entry 13
- ID: 8685
- Author: vivacious_eye
- Created At: 2026-05-23T17:08:09Z

### Content

**day_14**
# Redesigning (almost) the PCB and starting with the CAD Design (Kinda)
So, when I first sat to start the designing the encasing I realised that the screen was **too close** to the **Human Presence Sensor**. So, I had to _almost_ redesign the whole pcb. All I wanted to do was **move** the sensor a little left but when I did that all the wires would **detach** and I had to do the wiring again. I have encountered this same problem like **5 times** in this session (_Although I could use the **(D) Drag** option but it didn't allow **DRC mistakes**_). It was a headache but, **anything for fallout!!**

I also had to **re assign** the **HLK** and **ESP32** their 3d models cause earlier I had changed their **file location** sooo at the end of the first sub sesh this is how it looked(PCB, I hadn't started with the encasing yet):
![image.png](https://github.com/vineethjkatti-tech/ATTN_unit/blob/main/journal/journal-images/Screenshot%202026-06-27%20110051.png)
_I also had to edit the placement of the 8 pin mount for the cable of the display to the upper side cause I realised it was their only when I saw its 3d model hehe. I also had to adjust the spacing so many timesss, but again, anything for fallout!!_

Next, as I wanted to start I figured that the screen was **ill-aligned** (meaning it was not **centered**). So, **agaiiiiinnnn** I opened up KICAD and started to realign it by reducing or increasing either of the horizontal barriers. This time I had a handy trick to move the components with wires!! I used the same **Drag (D)** option but this time I had turned on the option to **ignore DRC mistakes**. Even if I made mistakes it would be **highlighted** and I would manually **fix** it after replacing the component. This really saved a **lot of time** to me!! _pheww... 
_
The final thing after this sesh is like this:
![image.png](https://github.com/vineethjkatti-tech/ATTN_unit/blob/main/journal/journal-images/Screenshot%202026-06-27%20110044.png)

This time I really started to design. When I had the PCB infrnt of me nothing reaaly **popped into my mind**. I sat there thinking for a couple of minutes. I arrived to the conclusion going **ahead with a similiar casing design to the first encasing**. But, something felt off, like it was really **plain** and **bland**. So, I closed it for the day thinking I will continue tomorrow cause today was very **stressful** for me.







*Time recorded: 1h 19m*

### Recording Links

- [timelapse (53).mp4](https://github.com/vineethjkatti-tech/ATTN_unit/blob/main/journal/timelapses/timelapse%20%2853%29.mp4)
- [timelapse (54).mp4](https://github.com/vineethjkatti-tech/ATTN_unit/blob/main/journal/timelapses/timelapse%20%2854%29.mp4)

## Entry 14
- ID: 8912
- Author: vivacious_eye
- Created At: 2026-05-24T16:51:07Z

### Content

**day_14**
# Starting with CAD and coming up with awesome Design Ideas
When I saw the initial design, I was very frustrated. Why? Cause it looked very plain, and zero effort. So, deleted the whole thing and remade everything. I started thinking of a display first design. 
Design Idea:
I was thinking of only having the display on the front and all the other components would be on the board and sandwiched in-between the display and the rear panel.
It was a great idea (atleast better than the last one) cause it had a decluterred and proffesional look.

So, I started by making the Bezel for the screen and Made a sketch matching the outermost border of the display. Then extruded it to form a rounded rectangle frame. On the front of the frame there is a 0.5mm thick panel for the display to sit in. The panel has a hole from which the screen is seen. I still have to design snap-in locks for the screen to actually sit there, gonna do it tomorrow. Now, the bezel was ready!!

![image.png](https://github.com/vineethjkatti-tech/ATTN_unit/blob/main/journal/journal-images/Screenshot%202026-06-27%20110031.png)
_I had to redo it sooo manyy times cause my brain was constantly flooding with new better ideas, I probably undoed and redoed like 5 times._

Next, I designed a new PCB board for the new CAD design! I removed the screen entirely from the board cause it would in a separate bezel. The screen and board would connect with a rear pin header on the board itself, more on this later. I changed the positioning of some components like the 8 pin header and now the board looked compact and concise. 

For the connection of the display with board I introduced the pin header (all of them that are on the board) on the backside of the board (I just turned the 3d model upside down for the footprint) so that they could be connect to the display.

Layout:
/  > display  \
|                      | > board(facing opp side)
|                      |
|                      |                      
|            pins >_ | 
|                    _| 
\                     /

So, the sturcture was somewhat like that ^.

So, after rewiring and making the PCB design I exported it and brought it into fusion to see how it looked. It looked pretty solid.
![Screenshot 2026-05-24 222001.png](https://github.com/vineethjkatti-tech/ATTN_unit/blob/main/journal/journal-images/Screenshot%202026-06-27%20110016.png)

![Screenshot 2026-05-24 221951.png](https://github.com/vineethjkatti-tech/ATTN_unit/blob/main/journal/journal-images/Screenshot%202026-06-27%20110009.png)


*Time recorded: 1h 16m*

### Recording Links

- [timelapse (55).mp4](https://github.com/vineethjkatti-tech/ATTN_unit/blob/main/journal/timelapses/timelapse%20%2855%29.mp4)

## Entry 15
- ID: 9168
- Author: vivacious_eye
- Created At: 2026-05-25T18:15:11Z

### Content

day_15
# Fitting the PCB with the Screen in CAD 
I first made the **snap in locks** for the display to fit into the bezel as I had promised in the previous journal.
I extruded and set the **taper angle as -30** degrees so it make a **triangle shape**. The Triangle only **protruded outwards for 1mm** so it was a **perfect fit**.
![image.png](https://github.com/vineethjkatti-tech/ATTN_unit/blob/main/journal/journal-images/Screenshot%202026-06-27%20110001.png)

Next I wanted to **fit the PCB and the bezel together** somehow, so I started to by first **comparing** the sizes of the PCB and the screen with bezel. The PCB was **way bigger**, but I had a plan to make them fit. I drew a canvas around the border of the PCB and then extruded it out to form a **frame**. I made **standoffs ** for screws at all four corners of the frame. Then I added the screws and inserts with the PCB. 
![image.png](https://github.com/vineethjkatti-tech/ATTN_unit/blob/main/journal/journal-images/Screenshot%202026-06-27%20105951.png)

After that, I made **grills** at the backwards of the PCB for the sensors to work efficiently. It looked kinda good according too me!!
After this I saw that the human presence sensor was **facing backwards**. I searched if it sent out signals in all directions but to my **surprise** it sent out waves only in a **120 degree front facing area**. This was a problem. I am thinking I could just turn the whole PCB around or bring the HLK somewhere near the bezel.



*Time recorded: 1h 27m*

### Recording Links

- [timelapse (56).mp4](https://github.com/vineethjkatti-tech/ATTN_unit/blob/main/journal/timelapses/timelapse%20%2856%29.mp4)
- [timelapse (57).mp4](https://github.com/vineethjkatti-tech/ATTN_unit/blob/main/journal/timelapses/timelapse%20%2857%29.mp4)

## Entry 16
- ID: 9392
- Author: vivacious_eye
- Created At: 2026-05-26T15:50:36Z

### Content

**day_16**
### Finishing (almost) the CAD

I turned the PCB around **180 degree** so that the HLK sensor had more **clearance**. I also had to make some adjustments to the screw holes and positions after turning it around, yk? the _usual_.
![image.png](https://github.com/vineethjkatti-tech/ATTN_unit/blob/main/journal/journal-images/Screenshot%202026-06-27%20105940.png)
_ as you can see all the components are upfront now._

After that I went on to design the **front panel** for the container, yk to **lock in**? _haha get the joke LOCK I.... nvm.._ This part was **very frustrating**, mainly cause when I was drawing the border, because of the shading, I couldn't see the **markings** properly so I tilted the part slightly to trace it. When I went to the original view it was **soo off the line** (but this is kinda skill issue so my bad). Also another thing was that there were too many things too deal with, like if I wanted to select the display(component) and the bezel(body) together I had to select it using window select manually so I had to **hide** all the things and **unhide** them again. But, the design got finished today, and I felt sooo happy about it.
![image.png](https://github.com/vineethjkatti-tech/ATTN_unit/blob/main/journal/journal-images/Screenshot%202026-06-27%20105931.png)

Next I tried to draw grills so that the sensor would get better data but when I actually made them, they kinda looked **ugly** cause the PCB behind them was green and bland. So, on only the top side where the mic was I decided to draw smaller 1mm grills and it looked better. (I didn't draw any on the bottom part).
![image.png](https://github.com/vineethjkatti-tech/ATTN_unit/blob/main/journal/journal-images/Screenshot%202026-06-27%20105919.png)
_ as you can see there are only like two grills on the top and none on the bottom mainly cause it didn't look good_

After that I decided to draw the **snap-in locks** now. I started by drawing the pins first, sketching the small rectangle and then a right angled triangle on it, _my geometry lessons paid off 😳._ After that it looked **rly good honestly**. I didnt think i would be able to pull this off!! Then I decided I will make the holes next time..



*Time recorded: 1h 4m*

### Recording Links

- [timelapse (58).mp4](https://github.com/vineethjkatti-tech/ATTN_unit/blob/main/journal/timelapses/timelapse%20%2858%29.mp4)

## Entry 17
- ID: 9721
- Author: vivacious_eye
- Created At: 2026-05-27T18:16:57Z

### Content

day_17
### Making Snap-In locks and moving ahead with the Design
I had to now make the **holes** for the **pins** of the **snap-in locks** I had alr made (sorry if i didnt mention it in the journal b4!). So, I used **Section Analysis** for this. I cut exactly where the pin was **overlapping** with the PCB holder and drew the sketch of the part which was overlapping. then **extruded** which formed the exact **depression** I was looking for. The I used **Pattern** and **Mirror** tool to copy the feature to all the sides. you might ask the pins may differ in location. But, no I had used the same functions for the pins too!!

![image.png](https://github.com/vineethjkatti-tech/ATTN_unit/blob/main/journal/journal-images/Screenshot%202026-06-27%20105908.png)
_For the mirror I had to use the midplane tool, I really learned the **most** in this session_

After the pins and holes were made, the **major** **part** was done actually. I still had to put the button in and also make a space for power supply.
Next I wanted to connect the front panel to the bezel so that it would be more **convenient**. When I combined them, it said they have to have a **clear overlap** for combining. What I did to solve this was make it more **bigger** then I was able to combine it properly. 

Followed by this was the grouping of all things. The pins were **never a part** of the front panel, mainly because it was easier to edit them if any **complications** showed up (_glad none did_). So, I combined the pins with the front panel (Part A). At the end the whole thing looked like this: 

![image.png](https://github.com/vineethjkatti-tech/ATTN_unit/blob/main/journal/journal-images/Screenshot%202026-06-27%20105854.png)

After this I edited the **positioning** of the **8-pin header** near where the button was cause this way, it was easier to plug in the **JST**. This again came with a lot of complications like removing the old wires and drawing new ones but I also learned about a new tool called interactive delete tool, so a **win win!**
![image.png](https://github.com/vineethjkatti-tech/ATTN_unit/blob/main/journal/journal-images/Screenshot%202026-06-27%20105842.png)

Then i edited some of the **README** like updating the **display choice**, updating the **Structure**. Adding new section called **connection method** and things. I didn't have time to update the repo in itself so I ended the sesh after these small changes.



*Time recorded: 1h 4m*

### Recording Links

- [timelapse (59).mp4](https://github.com/vineethjkatti-tech/ATTN_unit/blob/main/journal/timelapses/timelapse%20%2859%29.mp4)

## Entry 18
- ID: 9864
- Author: vivacious_eye
- Created At: 2026-05-28T08:50:13Z

### Content

**day_18**
# Working with the Color Scheme of my Project and updating my repo.

I still had to put the **switch** and make space for the **power supply**, so I got it done today. I first looked for a nyc s**pherical momentary switch**. I looked for a switch so **longg** - like **15 minutes** cause I thought these switches were too big and stole the spotlight from the real project. I imported like **three switched** to my project before choosing the last one - **8mm momentary switch** which turned out to be perfect!! When I first thought about the placement, I had decided to place it somewhere on the the **front**. But as the button was too big on the front I placed it on the **right panel on the Part B**. I made a hole and fit right through!!

![image.png](https://github.com/vineethjkatti-tech/ATTN_unit/blob/main/journal/journal-images/Screenshot%202026-06-27%20105831.png)
_during one of the images was being uploaded, I also made a cut on the left side of the Part B for a Power Supply!_

Next, I wanted to **color** the whole thing so it looked good. I chose a **matte yellow, matte black** color scheme which was very awsomee!! My project was finally done now!! It was looking so good and it didn't seem **low effort or unprofessional**. **It looked like a real product.
**
![image.png](https://github.com/vineethjkatti-tech/ATTN_unit/blob/main/journal/journal-images/Screenshot%202026-06-27%20105816.png)
_ it looked just as majestic as a queen bee!!_

Next was the more easier job - **updating the GitHub Repo.** I first decided to upload all the CAD files. I exported all the parts separately and the assembly as a whole too! One constant problem I was having was whenever I tried to export anything as .step my fusion would **crashhhh!!** It hapenned to me like a 1000 times!! As I was left with no choice, I exported everything as .stl and then used an **online converter** to convert them into .step. 
![image.png](https://github.com/vineethjkatti-tech/ATTN_unit/blob/main/journal/journal-images/Screenshot%202026-06-27%20105803.png)

I made my job easier by using github desktop as I could delete and insert new files easily now. 

Next I updated my Assets folder with new photos and deleted the old photos.
I took images in the **render workspace in fusion and also ray tracing images in KICAD**. All images were soooo goood. ( _Mainly cause I took ss before hehe!_ ).
I uploaded all the images to the Assets page in my comp and then deleted the assets page in the repo and inserted the assets folder of my comp. 

**All my major work is done so its only 1 -2 journals b4 this proj is over. Im gonna miss designing ATTN_unit (┬┬﹏┬┬)**



*Time recorded: 1h 29m*

### Recording Links

- [timelapse (60).mp4](https://github.com/vineethjkatti-tech/ATTN_unit/blob/main/journal/timelapses/timelapse%20%2860%29.mp4)
- [timelapse (61).mp4](https://github.com/vineethjkatti-tech/ATTN_unit/blob/main/journal/timelapses/timelapse%20%2861%29.mp4)

## Entry 19
- ID: 10071
- Author: vivacious_eye
- Created At: 2026-05-29T05:32:53Z

### Content

**day_19**
# Editing the Zine and Updating the README

I edited the zine first. I wanted to remove replace the previous image with the new one, but I couldn't find it in the assets page. So, I opened up fusion to take another image of it. After I took it as  imported it I saw that it wasn't PNG, It had a grey bg. I gtk that I couldn't capture transp. images in render. So, I just used capture image to take another image and it turned out transparent. I put it in the zine but the color didn't match the "_unit" text. I changed the color of that text to yellow. (fyi ATTN_unit was matte black and matte yellow). After editing everything, it turned out like this:

![image.png](https://github.com/vineethjkatti-tech/ATTN_unit/blob/main/journal/journal-images/Screenshot%202026-06-27%20105751.png)

Next I moved on to edit the README. I changed the images inside the README and also updated the component list. I changed the build instructions and added new ones. I also added new sections about the structure and mainly about display, explaining how to connect the display to the PCB inside. 


*Time recorded: 1h 6m*

### Recording Links

- [timelapse (62).mp4](https://github.com/vineethjkatti-tech/ATTN_unit/blob/main/journal/timelapses/timelapse%20%2862%29.mp4)

## Entry 20
- ID: 13682
- Author: vivacious_eye
- Created At: 2026-06-13T09:21:19Z

### Content

**day_21** 
#Fixing some Issues with the USB Port
My project was returned at the last review for an issue with the alignment of USB port. It was too inside, it should have been more at the edge of the PCB.

I made changes with the KICAD file, and yes I had to re route the tracks agaiinn!!. After that I also replaced the 3d model in the Assembly (of the PCB).

I had to re align the inserts and the screws with the holes cause I noticed they were a bit off, not sure why cause I hadn't touched the holes.

----------------------

**day_20**
#Editing the BOM

Today was mostly editing the BOM. Finding links of the product, scouting for the lowest prices and converting them to INR was the highlight of the day.

At last after the BOM was ready I uploaded it to my repo. After this I edited some things in the README.

![image.png](https://github.com/vineethjkatti-tech/ATTN_unit/blob/main/journal/journal-images/Screenshot%202026-06-27%20105738.png)

The grand total was **22.4** which was kinda high to me.



*Time recorded: 1h 13m*

### Recording Links

- [timelapse (63).mp4](https://github.com/vineethjkatti-tech/ATTN_unit/blob/main/journal/timelapses/timelapse%20%2863%29.mp4)
- [timelapse (64).mp4](https://github.com/vineethjkatti-tech/ATTN_unit/blob/main/journal/timelapses/timelapse%20%2864%29.mp4)
