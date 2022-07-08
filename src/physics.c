#include "./physics.h"

#include "./main.h"
#include "./maths.h"
#include "./buttons.h"
#include "./state.h"

#define angleWidth 192

// #define maxPower 0.075
// #define maxPower 0.125
// #define maxPower 0.1
double maxPower = 0.1;
#define maxReverse 0.0375
// #define powerFactor 0.001
double powerFactor = 0.001;
#define reverseFactor 0.0005

// #define drag 0.9
double drag = 0.9;
#define angularDrag 0.9
// #define turnSpeed 0.002
double turnSpeed = 0.002;

#define WIDTH 500
#define HEIGHT 500

double sin2(double x) {
  return (double)fpsin(x / 3.1415926 * 2 * angleWidth) / 32768;
}

double cos2(double x) {
  return sin2(x + (3.1415926 / 2));
}

double fmin(double a, double b) {
  return a < b ? a : b;
}

double fmax(double a, double b) {
  return a > b ? a : b;
}

double dmod(double a, double b) {
  return a - (int)(a / b) * b;
}

void updateWithControls(Kart *kart, ButtonState controls) {
  bool canTurn = kart->power > 0.0025/* || car->reverse*/;

  // Controls are reversed for now
  bool isTurningLeft = canTurn && /*controls.left*/ controls.right;
  bool isTurningRight = canTurn && /*controls.right*/ controls.left;

  if (controls.accel) {
    kart->power += powerFactor;
  } else {
    kart->power -= powerFactor;
  }
  /* if (car->isReversing) {
    car->reverse += reverseFactor;
  } else {
    car->reverse -= reverseFactor;
  } */

  kart->power = fmax(0, fmin(maxPower, kart->power));
  // car->reverse = fmax(0, fmin(maxReverse, car->reverse));

  // double direction = car->power > car->reverse ? 1 : -1;
  int direction = 1;

  double change = isTurningLeft ? -1 : isTurningRight ? 1 : 0;
  if (state.drifting) {
    if (state.driftDir == -1) {
      change += 0.7;
    } else {
      change -= 0.7;
    }
  }
  change *= direction * turnSpeed;
  kart->angularVelocity += change;

  kart->xVelocity += sin2(kart->angle) * (kart->power /* - kart->reverse */);
  kart->yVelocity += cos2(kart->angle) * (kart->power /* - kart->reverse */);

  kart->x += kart->xVelocity;
  kart->y -= kart->yVelocity;
  kart->xVelocity *= drag;
  kart->yVelocity *= drag;
  kart->angle += kart->angularVelocity;
  kart->angle = dmod(kart->angle, 3.1415926 * 2);
  kart->angularVelocity *= angularDrag;
}
