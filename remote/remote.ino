#include <TeadusPlane.h>
#include "Axis.h"

XRF xrf;

Axis x(2, 498);
Axis y(1, 535);
Axis z(4, 1023 - 522, true);
Axis w(5, 1023 - 517, true);

void setup() {
  xrf.begin();
  
  pinMode(13, OUTPUT);
}

void loopDebugRaw() {
  Serial.print(x.getRaw());
  Serial.print("\t");
  Serial.print(y.getRaw());
  Serial.print("\t");
  Serial.print(z.getRaw());
  Serial.print("\t");
  Serial.println(w.getRaw());

  delay(100);
}

void loopDebug() {
  Serial.print(x.get());
  Serial.print("\t");
  Serial.print(y.get());
  Serial.print("\t");
  Serial.print(z.get());
  Serial.print("\t");
  Serial.println(w.get());

  delay(100);
}

void loopMain() {
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

  delay(50);
}

void loop() {
  loopMain();
}
