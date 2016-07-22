#include <TeadusPlane.h>
#include <Servo.h>

XRF xrf;

Servo x, y, z, w;

void setup() {
  xrf.begin();

  x.attach(2);
  y.attach(3);
  z.attach(4);
  w.attach(5);
}

void loop() {
  Command command = xrf.read();
  x.write(map(command.x, 0, 255, 0, 180));
  y.write(map(command.y, 0, 255, 0, 180));
  z.write(map(command.z, 0, 255, 0, 180));
  w.writeMicroseconds(map(command.w, 0, 127, 2000, 700));
  /*Serial.print(command.x);
  Serial.print("\t");
  Serial.print(command.y);
  Serial.print("\t");
  Serial.print(command.z);
  Serial.print("\t");
  Serial.println(command.w);*/
}
