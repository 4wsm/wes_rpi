#include <Arduino.h>

unsigned int oTime = 0;
unsigned int cTime = 0;
unsigned int time = 0;

void yell() {
  cTime = millis();
  time = cTime - oTime;
  oTime = cTime;
}

void setup() {
  Serial.begin(9600);
  pinMode(2, INPUT);
  attachInterrupt(digitalPinToInterrupt(2),yell,RISING);
}

void loop() {
  Serial.println(time);
}