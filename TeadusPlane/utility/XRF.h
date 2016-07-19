#ifndef TEADUS_XRF
#define TEADUS_XRF

#include "Arduino.h"

#include "Command.h"

class XRF
{
  public:
    void begin();

    void write(Command command);
    Command read();
};

#endif // TEADUS_XRF
