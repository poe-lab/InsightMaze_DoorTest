#include "globals.h"
#include "Door.h"

Door d0(PIN_DOOR_0, POS_D0[0], POS_D0[1]); //identify what a door is and position of door?
Door d1(PIN_DOOR_1, POS_D1[0], POS_D1[1]);
Door d2(PIN_DOOR_2, POS_D2[0], POS_D2[1]);
Door d3(PIN_DOOR_3, POS_D3[0], POS_D3[1]);
Door d4(PIN_DOOR_4, POS_D4[0], POS_D4[1]);
Door d5(PIN_DOOR_5, POS_D5[0], POS_D5[1]);

int timedelay = 3000;
void setup() {  // will only run once

  d0.doorSetup();
  d1.doorSetup();
  d2.doorSetup();
  d3.doorSetup();
  d4.doorSetup();
  d5.doorSetup();

  testDoors(500, 500);  // tells doors to open for 1.5s and close for 1.5s
  d0.doorOpen();
  d1.doorOpen();
  d2.doorOpen();
  d3.doorOpen();
  d4.doorOpen();
  d5.doorOpen();
  delay(2000);

  Serial.begin(9600);
}

void loop() {
  d0.doorClose();
  printDoorsStates(); //gives me door states 
  delay(timedelay);    //increasing delay will give me more time to look at serial monitor

  d0.doorOpen();
  printDoorsStates();
  delay(timedelay);

  d1.doorClose();
  printDoorsStates();
  delay(timedelay);

  d1.doorOpen();
  printDoorsStates();
  delay(timedelay);

  d2.doorClose();
  printDoorsStates();
  delay(timedelay);

  d2.doorOpen();
  printDoorsStates();
  delay(timedelay);

  d3.doorClose();
  printDoorsStates();
  delay(timedelay);

  d3.doorOpen();
  printDoorsStates();
  delay(timedelay);

  d4.doorClose();
  printDoorsStates();
  delay(timedelay);

  d4.doorOpen();
  printDoorsStates();
  delay(timedelay);

  d5.doorClose();
  printDoorsStates();
  delay(timedelay);

  d5.doorOpen();
  printDoorsStates();
  delay(timedelay);

}

void testDoors(int openTime, int closeTime){
  d0.doorOpen();
  d1.doorOpen();
  d2.doorOpen();
  d3.doorOpen();
  d4.doorOpen();
  d5.doorOpen();
  delay(openTime);

  d0.doorClose();
  d1.doorClose();
  d2.doorClose();
  d3.doorClose();
 d4.doorClose();
  d5.doorClose();
  delay(closeTime);
}

void printDoorsStates(){
  Serial.print(d0.isOpen()); Serial.print(' ');
  Serial.print(d1.isOpen()); Serial.print(' ');
  Serial.print(d2.isOpen()); Serial.print(' ');
  Serial.print(d3.isOpen()); Serial.print(' ');
  Serial.print(d4.isOpen()); Serial.print(' ');
  Serial.println(d5.isOpen());
}
