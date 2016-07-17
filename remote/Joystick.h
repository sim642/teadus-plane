#ifndef TEADUS_JOYSTICK
#define TEADUS_JOYSTICK

#include "Arduino.h"

class Joystick
{
  public:
    Joystick(int xPin, int yPin);

    int getRawX();
    int getRawY();

    int getX();
    int getY();

  private:
    int _xPin, _yPin;
};

#endif // TEADUS_JOYSTICK
