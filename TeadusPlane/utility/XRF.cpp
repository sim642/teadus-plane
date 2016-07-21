#include "XRF.h"

void XRF::begin()
{
  Serial.begin(9600);
}

void XRF::write(Command command)
{
  Serial.print(command.serialize());
}

Command XRF::read()
{
  while (Serial.peek() != 'a')
    Serial.read();

  char str[Command::LENGTH + 1];
  str[Command::LENGTH] = '\0';
  Serial.readBytes(str, Command::LENGTH);
  return Command::deserialize(String(str));
}

