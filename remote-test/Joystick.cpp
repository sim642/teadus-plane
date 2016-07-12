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
  return getRawX() - 512;
}

int Joystick::getY()
{
  return getRawY() - 512;
}

