#ifndef TEADUS_COMMAND
#define TEADUS_COMMAND

#include "Arduino.h"

class Command
{
  public:
    static constexpr int LENGTH = 12;

    Command();

    String serialize() const;
    static Command deserialize(String str);

    int x, y, z, w;
    bool left, right;

  private:
    static int hex2int(String str);
};

#endif // TEADUS_COMMAND
