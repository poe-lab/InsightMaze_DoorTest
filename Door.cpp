#include "Door.h"
#include <Arduino.h>
#include <Servo.h>

Door::Door(int pin, int posOpen, int posClose) { //
  m_pin = pin;
  m_isOpen = true; //
  m_posOpen = posOpen;
  m_posClose = posClose;
}

void Door::doorSetup() { //
  m_servo.attach(m_pin);
  m_servo.write(m_posOpen);
}

void Door::doorOpen() { //
  if (!m_isOpen) {
    if (m_servo.read() > m_posOpen)
    {
      while(m_servo.read() > m_posOpen)
      {
        m_servo.write(m_servo.read()-1);
        delay(10);
      }
    }
    if (m_servo.read() < m_posOpen)
    {
      while(m_servo.read() < m_posOpen)
      {
        m_servo.write(m_servo.read()+1);
        delay(10);
      }
    }
    m_isOpen = true;
  }
}

void Door::doorClose() {
  if (m_isOpen) {
    if(m_servo.read() < m_posClose)
    {
      while(m_servo.read() < m_posClose)
      {
        m_servo.write(m_servo.read()+1);
        delay(10);
      }
    }
    else if(m_servo.read() > m_posClose)
    {
      while(m_servo.read() > m_posClose)
      {
        m_servo.write(m_servo.read()-1);
        delay(10);
      }
    }
    m_isOpen = false;
  }

}

bool Door::isOpen() {
  return m_isOpen;
}
