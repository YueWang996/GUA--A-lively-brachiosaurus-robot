/* 
* For CH232M TX-YELLOW RX-ORANGE
*/

#include "LobotServoController.h"
#include "Actions.h"
#include "SR04.h"
#include "Photoresistor.h"
#include "Microphone.h"

#define TRIGPIN 2
#define ECHOPIN 3
#define PhotoDetectorPin A2
#define MicrophonePin A3
#include <SoftwareSerial.h>

int sr04_data[10];
int i;
int val; //光敏电阻值

Actions* ptr_ac = new Actions;
SR04 sr04(TRIGPIN, ECHOPIN);
Photoresistor pr(PhotoDetectorPin);
Microphone mic(MicrophonePin);
SoftwareSerial mySerial(4, 5); // RX, TX

/* Block 1 */
void (Actions::*functionPtr1[])() = {&Actions::action_group_1, &Actions::action_group_7};                            //没光，没声
void (Actions::*functionPtr2[])() = {&Actions::action_group_16, &Actions::action_group_10};                           //有光，有声
void (Actions::*functionPtr3[])() = {&Actions::action_group_2, &Actions::action_group_23, &Actions::action_group_22, &Actions::action_group_25, &Actions::action_group_19};

/*Block 2*/
void (Actions::*functionPtr4[])() = {&Actions::action_group_5, &Actions::action_group_8};
void (Actions::*functionPtr5[])() = {&Actions::action_group_20, &Actions::action_group_11};
void (Actions::*functionPtr6[])() = {&Actions::action_group_2, &Actions::action_group_23};
void (Actions::*functionPtr7[])() = {&Actions::action_group_14, &Actions::action_group_17, &Actions::action_group_26};

void setup() {
  pinMode(13,OUTPUT);
  Serial.begin(9600);
  mySerial.begin(9600);
  while(!Serial);
  digitalWrite(13,HIGH);
  sr04.sr04_setup();

}
String a;
uint8_t index;
int pitch;
int roll;
bool handIsDetected;

void loop() {
  if(mySerial.available() > 0) {
    if(mySerial.peek() == '\0') handIsDetected = false;
    else handIsDetected = true;
    
    if(mySerial.peek() != '\n') {
      a  +=(char)mySerial.read();
    } else {
      mySerial.read();
      index = a.indexOf('/');
      pitch = a.substring(0, index).toInt();
      roll = a.substring(index+1, a.length()).toInt();
      //Serial.println(a);
      a="";
    }
  }
  Serial.println(pitch);
  Serial.println(roll);
  
  if(mic.isScreaming()) {
    digitalWrite(13,HIGH);
  } else {
    digitalWrite(13,LOW);
  }

  Serial.println(pr.isDark());

  for(i = 0; i < 10; i++) {
    sr04_data[i] = sr04.get_distance();
  }
  sr04.detectPerson(sr04_data);
  delay(100);
  Serial.println(sr04.personIsDetected);

/*Block 1*/
  if(!handIsDetected && !sr04.personIsDetected && !mic.isScreaming() && pr.isDark()) {
    randomSeed(analogRead(5));
    int randNum = (int) random(0, 1);
    (ptr_ac->*functionPtr1[randNum])();
    delay(1000);
  }

  if(!handIsDetected && !sr04.personIsDetected && mic.isScreaming() && pr.isDark()) {
    randomSeed(analogRead(5));
    int randNum = (int) lrint(random(0, 2));
    (ptr_ac->*functionPtr2[randNum])();
    delay(1000);
  }

  if(!handIsDetected && !sr04.personIsDetected && !mic.isScreaming() && !pr.isDark()) {
    randomSeed(analogRead(5));
    int randNum = (int) lrint(random(0, 6));
    (ptr_ac->*functionPtr3[randNum])();
    delay(1000);
  }

/*Block 2*/
  if(!handIsDetected && sr04.personIsDetected && !mic.isScreaming() && pr.isDark()) {
    randomSeed(analogRead(5));
    int randNum = (int) lrint(random(0, 2));
    (ptr_ac->*functionPtr4[randNum])();
    delay(1000);
  }

  if(!handIsDetected && sr04.personIsDetected && mic.isScreaming() && pr.isDark()) {
    randomSeed(analogRead(5));
    int randNum = (int) lrint(random(0, 2));
    (ptr_ac->*functionPtr5[randNum])();
    delay(1000);
  }

  if(!handIsDetected && sr04.personIsDetected && !mic.isScreaming() && !pr.isDark()) {
    randomSeed(analogRead(5));
    int randNum = (int) lrint(random(0, 2));
    (ptr_ac->*functionPtr6[randNum])();
    delay(1000);
  }

  if(!handIsDetected && sr04.personIsDetected && mic.isScreaming() && !pr.isDark()) {
    randomSeed(analogRead(5));
    int randNum = (int) lrint(random(0, 2));
    (ptr_ac->*functionPtr7[randNum])();
    delay(1000);
  }


}
