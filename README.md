# GUA--A-lively-brachiosaurus-robot

## Introduction
A viable monster robot living in the garbage dump of the wasteland era. He may become your friend (or he may not).
There are 27 actions in GUA, which are
dead/sleeping/sweet dreams/hair grooming/stereotyped behavior/vent/shaking head and tail / running and jumping to move body / ecstasy/relaxed/weak/totally relax/play with the ball and big uppercut/anxious walking/roaring/to kiss/Interactively/Train to follow instructions/snuggle and sticky/roll/and act like a baby/wait and see/greet expectation instructions/healing/cooperation/Work Tracking/ambush/culling

- Partition 1 Conditions No sound and no light (a group of lower left corner (dead/sleeping), 2 actions) 7, 1
- Partition 2 Conditions There is sound and no light (a group of upper left corner (sweet dreams/hair grooming), 2 actions) 16, 10
- Partition 3 Conditions There is light and no sound (a set of lower right corner (stereotyped behavior/vent), 2 actions) 4, 13
- Partition 4 Conditions: There is light and no sound (a group of upper right corner (shaking head and tail / running and jumping to move body / ecstasy) 22, 25, 19
- Division 5 Conditions: No light, no sound, no people (two sets of lower left corner (relaxed, weak)) 2 actions 5, 8
- Division 6 Conditions: There is sound but no light, and there are people (two sets of upper left corner (totally relax, play with the ball and big uppercut) 2 actions 20, 11
- Division 7 Conditions: There is light but no sound, there are people (the second set of lower right corner (anxious walking, roaring) 2 actions 2, 23
- Part 8 Conditions There are light, sound and some people (two groups in the upper right corner (to kiss each other/Interactively/Train to follow instructions), 3 actions 14, 17, 26
- Division 9 Conditions Keywords good boy (three groups of upper left corner, snuggle and sticky/roll and act like a baby) 2 actions, 15, 25
- Partition 10 Conditions Keywords look (three groups of left center, wait and see/greet expectation instructions) 2 actions 3, 12
- Part 11 Healing Conditions All meaningless leapmotion behaviors (that is, leapmotion has a hand, but does not produce a key movement / if there is technical difficulty, use the gesture Circle — A single finger tracing a circle) one movement 6
- Division 12 Conditions The palm movement is large. Movement 27 The horizontal axis and the vertical axis move with the movement of the palm
- Division 13 Conditions Keyword "go" Action 21 Work Tracking
- Division 14 Conditions Gesture Swipe — A long, linear movement of a finger. (Ambush/culling) 9, 18]

## Platform
- Arduino Uno R3
- Leap Motion

## Sensors
- Microphone
- Photoresistor
- Ultrasonic transducer
- Leap Motion (gesture detecting)

## How to use it?
Download the code. Plese make sure that your python version is 3.8. 
Arduino: Open Arduino IDE and burn LobotServosController.ino into your Arduino Uno R3 development board and you can find port configurations in the code.
Python: Before you running GestureDetect.py please make sure you have an extra USB to Serial adaptor and you have modified the COM port of your adaptor.

## 27 Actions!
dead/sleeping/sweet dreams/hair grooming/stereotyped behavior/vent/shaking head and tail / running and jumping to move body / ecstasy/relaxed/weak/totally relax/play with the ball and big uppercut/anxious walking/roaring/to kiss/Interactively/Train to follow instructions/snuggle and sticky/roll/and act like a baby/wait and see/greet expectation instructions/healing/cooperation/Work Tracking/ambush/culling
