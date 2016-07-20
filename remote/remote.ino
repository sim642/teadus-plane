#include <TeadusPlane.h>
#include "Axis.h"

XRF xrf;

Axis x(2), y(1), z(4), w(5);

void setup() {
  xrf.begin();
  
  pinMode(13, OUTPUT);
}

void loop() {
  Command command;
  command.x = x.get();
  command.y = y.get();
  command.z = z.get();
  command.w = w.get();
  xrf.write(command);

  /*digitalWrite(13, HIGH);
  delay(100);
  digitalWrite(13, LOW);
  delay(100);*/

  delay(100);
}
