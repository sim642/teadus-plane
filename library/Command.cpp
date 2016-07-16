#include "Command.h"

#include <stdio.h>

String Command::serialize() const
{
  char str[LENGTH + 1];
  snprintf(str, sizeof(str), "a%.3X%.3X-----", x, y);
  return String(str);
}

Command Command::deserialize(String str)
{
  Command command;
  command.x = hex2int(str.substring(1, 1 + 3));
  command.y = hex2int(str.substring(1 + 3, 1 + 3 + 3));
  return command;
}

int Command::hex2int(String str)
{
  return strtol(str.c_str(), nullptr, 16);
}

