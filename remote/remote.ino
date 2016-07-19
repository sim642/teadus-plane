#include <TeadusPlane.h>
#include "Joystick.h"

XRF xrf;

Joystick right(2, 1);
Joystick left(4, 5);

void setup() {
  xrf.begin();
  
  pinMode(13, OUTPUT);
}

void loop() {
  Command command;
  command.x = right.getX();
  command.y = right.getY();
  command.z = left.getX();
  command.w = left.getY();
  xrf.write(command);

  /*digitalWrite(13, HIGH);
  delay(100);
  digitalWrite(13, LOW);
  delay(100);*/

  delay(100);
}
