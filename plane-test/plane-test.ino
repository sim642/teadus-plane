#include <Servo.h>

Servo servo;

void setup() {
  Serial.begin(9600);
  servo.attach(9);
}

void loop() {
  int x = Serial.parseInt();
  /*int y = Serial.parseInt();
  boolean sw = Serial.parseInt();*/

  servo.write(map(x, 0, 1023, 0, 180));
}
