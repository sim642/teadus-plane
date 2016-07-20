#include "Axis.h"

Axis::Axis(int pin, int center, int threshold) : _pin(pin), _center(center), _threshold(threshold)
{

}

int Axis::getRaw()
{
  return analogRead(_pin);
}

int Axis::get()
{
  int left = _center - _threshold;
  int right = _center + _threshold;

  int raw = getRaw();
  if (raw < left)
    return map(raw, 0, left, 0, 127);
  else if (raw > right)
    return map(raw, right, 1023, 127, 255);
  else
    return 127;
}

