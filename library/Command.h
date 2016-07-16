#ifndef TEADUS_COMMAND
#define TEADUS_COMMAND

#include "Arduino.h"

class Command
{
  public:
    static constexpr int LENGTH = 12;

    String serialize() const;
    static Command deserialize(String str);

    int x, y;

  private:
    static int hex2int(String str);
};

#endif // TEADUS_COMMAND
