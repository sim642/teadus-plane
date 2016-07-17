#include "Joystick.h"

Joystick::Joystick(int xPin, int yPin) : _xPin(xPin), _yPin(yPin)
{
  
}

int Joystick::getRawX()
{
  return analogRead(_xPin);
}

int Joystick::getRawY()
{
  return analogRead(_yPin);
}

int Joystick::getX()
{
  return map(getRawX(), 0, 1024, 0, 256);
}

int Joystick::getY()
{
  return map(getRawY(), 0, 1024, 0, 256);
}

