#include "Command.h"

#include <stdio.h>

Command::Command() : x(127), y(127), z(127), w(127)
{

}

String Command::serialize() const
{
  char str[LENGTH + 1];
  snprintf(str, sizeof(str), "a" "%.2X" "%.2X" "%.2X" "%.2X" "%.1X" "%.1X" "-", x, y, z, w, left, right);
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
  command.left = hex2int(str.substring(pos, pos + 1));
  pos += 1;
  command.right = hex2int(str.substring(pos, pos + 1));
  pos += 1;

  return command;
}

int Command::hex2int(String str)
{
  return strtol(str.c_str(), nullptr, 16);
}

