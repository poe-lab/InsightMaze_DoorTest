/*
Note from Vedant:
This is a function for purely testing purposes. This has all the functionality of the doors
But it will work via input of SerialMonitor or PuTTY or whatever y'all choose.
*/

#include "globals.h"
#include "Door.h"

// The module we are testing. 0,1,2,3 being start to end correspondingly
int module = 2;
// Initialise each door
Door d0(PIN_DOOR_0, POS_D0[module][0], POS_D0[module][1]); 
Door d1(PIN_DOOR_1, POS_D1[module][0], POS_D1[module][1]);
Door d2(PIN_DOOR_2, POS_D2[module][0], POS_D2[module][1]);
Door d3(PIN_DOOR_3, POS_D3[module][0], POS_D3[module][1]);
Door d4(PIN_DOOR_4, POS_D4[module][0], POS_D4[module][1]);
Door d5(PIN_DOOR_5, POS_D5[module][0], POS_D5[module][1]);

int timedelay = 3000;
void setup() {  // will only run once
  d0.doorSetup();
  d1.doorSetup();
  d2.doorSetup();
  d3.doorSetup();
  d4.doorSetup();
  d5.doorSetup();
  delay(2000);
  Serial.begin(9600);
}

// Runs repeatedly
void loop() {
  handleSerial();
  Serial.println(d4.m_servo.read(), DEC);
  delay(200);
}

// This raises and lowers all the doors to test functionality
void testDoors(int openTime, int closeTime){

  d0.doorClose();
  d1.doorClose();
  d2.doorClose();
  d3.doorClose();
  d4.doorClose();
  d5.doorClose();
  delay(closeTime);
  
  d0.doorOpen();
  d1.doorOpen();
  d2.doorOpen();
  d3.doorOpen();
  d4.doorOpen();
  d5.doorOpen();
  delay(openTime);
}

// This prints all the states of the doors.
void printDoorsStates(){
  Serial.print(d0.isOpen()); Serial.print(' ');
  Serial.print(d1.isOpen()); Serial.print(' ');
  Serial.print(d2.isOpen()); Serial.print(' ');
  Serial.print(d3.isOpen()); Serial.print(' ');
  Serial.print(d4.isOpen()); Serial.print(' ');
  Serial.println(d5.isOpen());
}

/* 
This is the handler for all incoming serial commands
This is the main code that we are executing here, the functionality to test doors comes from here.
Commands:
'a' Raises door by 1 degree
'z' Lowers door by 1 degree
'u' raises the door to the set up position
'd' lowers the door to the set down position
You can chain several commands together before sending the serial command 
i.e "aaaaaaaaaaa" for 13 degrees raise

You may also set a different door to be a reference door for height adjustments
'q' raises the reference door
'w' lowers the reference door

At the end you can test what you have done,
't' Tests the doors
*/
void handleSerial()
{
  Door d = d4; // door to program
  Door dr = d3; // door to reference (optional for q/w commands)
  while(Serial.available() > 0)
  {
    int deg;
    char incoming = Serial.read();
    switch (incoming)
    {
      case 'a': // Raise door to see by one degree
        d.m_servo.write(d.m_servo.read()+1);
        break;
      case 'z': // Lower door to see by one degree
        d.m_servo.write(d.m_servo.read()-1);
        break;
      case 'u': // Raise to preset up position
        d.m_isOpen = true;
        d.doorClose();
        break;
      case 'd': // Lower to preset down position
        d.m_isOpen = false;
        d.doorOpen();
        break;
      case 'q': // Raise reference door
        dr.m_isOpen = true;
        dr.doorClose();
        break;
      case 'w': // Lower reference door
        dr.m_isOpen = false;
        dr.doorOpen();
        break;
      case 't': // Test all doors
        delay(5000); // Enough to get up and watch the doors
        testDoors(2000,2000);
        break;
    }
  }
}
