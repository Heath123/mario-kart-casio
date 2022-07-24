#include "./physics.h"

#include "./configurableConstants.h"
#include "./main.h"
#include "./maths.h"
#include "./buttons.h"
#include "./state.h"
#include "stdbool.h"

#define angleWidth 192

// #define maxPower 0.075
// #define maxPower 0.125
// #define maxPower 0.1
bool applyBoost = false;

// double maxPower = 0.1;
// double powerFactor = 0.001;

extern double maxPower;
extern double powerFactor;
extern double boostMaxPower;
extern double boostPowerFactor;

#define maxReverse 0.0375
// #define powerFactor 0.001#include "./configurableConstants.h"
#define reverseFactor 0.0005

// #define drag 0.9
bool applyOffRoadDrag = false;

extern double drag;
extern double offRoadDrag;
extern double angularDrag;
extern double turnSpeed;

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

// #define maxSteerNormal 1
// #define minSteerDrift 0.2 * (1.7 / 2.2)
// #define neutralSteerDrift (1.7 / 2.2)
// #define maxSteerDrift 1.7
extern double maxSteerNormal;
extern double minSteerDrift;
extern double neutralSteerDrift;
extern double maxSteerDrift;

void updateWithControls(Kart *kart, ButtonState controls) {
  bool canTurn = kart->power > 0.0025/* || car->reverse*/;

  // Controls are reversed for now
  bool isTurningLeft = canTurn && /*controls.left*/ controls.right;
  bool isTurningRight = canTurn && /*controls.right*/ controls.left;

  if (controls.accel) {
    kart->power += applyBoost ? boostMaxPower : maxPower;
  } else {
    kart->power -= applyBoost ? boostPowerFactor : powerFactor;
  }
  /* if (car->isReversing) {
    car->reverse += reverseFactor;
  } else {
    car->reverse -= reverseFactor;
  } */

  kart->power = fmax(0, fmin(applyBoost ? boostMaxPower: maxPower, kart->power));
  // car->reverse = fmax(0, fmin(maxReverse, car->reverse));

  // double direction = car->power > car->reverse ? 1 : -1;
  int direction = 1;

  // double change = isTurningLeft ? -1 : isTurningRight ? 1 : 0;
  // if (kart->drifting) {
  //   if (kart->driftDir == -1) {
  //     change += 1.2;
  //   } else {
  //     change -= 1.2;
  //   }
  //   change *= 1.7 / 2.2;
  // }
  double change = 0;
  if (!kart->drifting) {
    change = isTurningLeft ? -maxSteerNormal : isTurningRight ? maxSteerNormal : 0;
  } else {
    // This is negated from what you'd expect, hence the - (pretend it's not there if you want to understand this)
    // I need to fix the coordinate system so it's less broken and inconsistent
    if (-kart->driftDir == 1) {
      if (isTurningRight) {
        // Steering matches drift direction - maximum steering angle
        change = maxSteerDrift;
      } else if (isTurningLeft) {
        change = minSteerDrift;
      } else {
        change = neutralSteerDrift;
      }
    } else {
      change = -maxSteerDrift;
      if (isTurningLeft) {
        change = maxSteerDrift;
      } else if (isTurningRight) {
        change = minSteerDrift;
      } else {
        change = neutralSteerDrift;
      }
      change = -change;
    }
  }
  change *= direction * turnSpeed;
  kart->angularVelocity += change;

  kart->xVelocity += sin2(kart->angle) * (kart->power /* - kart->reverse */);
  kart->yVelocity += cos2(kart->angle) * (kart->power /* - kart->reverse */);

  kart->x += kart->xVelocity;
  kart->y -= kart->yVelocity;
  double calcDrag = applyOffRoadDrag ? offRoadDrag : drag;
  kart->xVelocity *= calcDrag;
  kart->yVelocity *= calcDrag;
  kart->angle += kart->angularVelocity;
  kart->angle = dmod(kart->angle, 3.1415926 * 2);
  kart->angularVelocity *= angularDrag;
}
