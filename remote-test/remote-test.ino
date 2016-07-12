#include "Joystick.h"

Joystick joy(0, 1);

void setup() {
  Serial.begin(9600);
  pinMode(12, INPUT);
}

void loop() {
  Serial.println(joy.getRawX());
  /*Serial.print(" ");
  Serial.print(analogRead(1));
  Serial.print(" ");
  Serial.println(!digitalRead(12));*/

  delay(100);
}
