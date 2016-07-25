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
  bool success = Serial.find("a");
  if (!success)
    return Command();

  char str[Command::LENGTH + 1];
  str[0] = 'a';
  str[Command::LENGTH] = '\0';
  Serial.readBytes(str + 1, Command::LENGTH - 1);
  return Command::deserialize(String(str));
}

