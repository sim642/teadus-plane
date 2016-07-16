#include "XRF.h"

void XRF::write(Command command)
{
  Serial.print(command.serialize());
}

Command XRF::read()
{
  char str[Command::LENGTH + 1];
  Serial.readBytes(str, sizeof(str));
  return Command::deserialize(String(str));
}

