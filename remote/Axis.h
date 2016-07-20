#ifndef TEADUS_AXIS
#define TEADUS_AXIS

#include "Arduino.h"

class Axis
{
  public:
    Axis(int pin, int center = 512, int threshold = 3);

    int getRaw();
    int get();

  private:
    int _pin;
    int _center;
    int _threshold;
};

#endif // TEADUS_AXIS
