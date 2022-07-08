#ifndef _PHYSICS_H
#define _PHYSICS_H

#include <stdbool.h>

#include "./buttons.h"

typedef struct {
  double x;
  double y;
  double xVelocity;
  double yVelocity;
  double power;
  // double reverse;
  double angle;
  double angularVelocity;
} Kart;

extern double drag;
extern double turnSpeed;
extern double maxPower;
extern double powerFactor;

void updateWithControls(Kart *car, ButtonState controls);

#endif // _PHYSICS_H
