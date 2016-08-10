#ifndef TEADUS_AXIS
#define TEADUS_AXIS

#include "Arduino.h"

class Axis
{
  public:
    Axis(int pin, int center = 512, bool inverted = false, int threshold = 3);

    int getRaw();
    int getCentered();
    int get();

  private:
    int _pin;
    int _center;
    bool _inverted;
    int _threshold;
};

#endif // TEADUS_AXIS
