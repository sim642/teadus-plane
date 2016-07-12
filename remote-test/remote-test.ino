void setup() {
  Serial.begin(9600);
  pinMode(12, INPUT);
}

void loop() {
  Serial.println(analogRead(0));
  /*Serial.print(" ");
  Serial.print(analogRead(1));
  Serial.print(" ");
  Serial.println(!digitalRead(12));*/

  delay(100);
}
