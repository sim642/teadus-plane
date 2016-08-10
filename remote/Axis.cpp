#include "Axis.h"

Axis::Axis(int pin, int center, bool inverted, int threshold) : _pin(pin), _center(center), _inverted(inverted), _threshold(threshold)
{

}

int Axis::getRaw()
{
  int raw = analogRead(_pin);
  return _inverted ? 1023 - raw : raw;
}

int Axis::getCentered()
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

float map(float x, float in_min, float in_max, float out_min, float out_max)
{
  return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}

int sgn(float val)
{
  return val < 0 ? -1 : (val > 0 ? 1 : 0);
}

int Axis::get()
{
  float mapped = map(getCentered(), 0, 255, -1.f, 1.f);
  float powered = pow(mapped, 2);
  return map(abs(powered) * sgn(mapped), -1.f, 1.f, 0, 255);
}

