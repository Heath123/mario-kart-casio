#ifndef _PHYSICS_H
#define _PHYSICS_H

#include <stdbool.h>

typedef struct {
  bool up;
  bool left;
  bool right;
  bool down;
} ControlState;

typedef struct {
  double x;
  double y;
  double xVelocity;
  double yVelocity;
  double power;
  double reverse;
  double angle;
  double angularVelocity;
  bool isThrottling;
  bool isReversing;
  bool isShooting;
  bool isTurningLeft;
  bool isTurningRight;
} Car;

extern double drag;
extern double turnSpeed;

void updateWithControls(Car *car, ControlState controls);

#endif // _PHYSICS_H
