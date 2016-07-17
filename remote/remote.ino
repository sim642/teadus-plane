#include <XRF.h>
#include "Joystick.h"

XRF xrf;

Joystick right(2, 1);
Joystick left(4, 5);

void setup() {
  Serial.begin(9600);
  
  pinMode(13, OUTPUT);
}

void loop() {
  Command command;
  command.x = right.getX();
  command.y = right.getY();
  command.z = left.getX();
  command.w = left.getY();
  xrf.write(command);
  //Serial.print("abc");

  /*digitalWrite(13, HIGH);
  delay(100);
  digitalWrite(13, LOW);
  delay(100);*/

  delay(100);
}
