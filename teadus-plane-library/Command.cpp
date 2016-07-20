#include "Command.h"

#include <stdio.h>

String Command::serialize() const
{
  char str[LENGTH + 1];
  snprintf(str, sizeof(str), "a" "%.2X" "%.2X" "%.2X" "%.2X" "---", x, y, z, w);
  return String(str);
}

Command Command::deserialize(String str)
{
  Command command;

  int pos = 1;
  command.x = hex2int(str.substring(pos, pos + 2));
  pos += 2;
  command.y = hex2int(str.substring(pos, pos + 2));
  pos += 2;
  command.z = hex2int(str.substring(pos, pos + 2));
  pos += 2;
  command.w = hex2int(str.substring(pos, pos + 2));
  pos += 2;

  return command;
}

int Command::hex2int(String str)
{
  return strtol(str.c_str(), nullptr, 16);
}

