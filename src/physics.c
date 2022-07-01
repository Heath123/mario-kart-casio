#include "./physics.h"

#include "./maths.h"

#define angleWidth 192

// #define maxPower 0.075
#define maxPower 0.125
#define maxReverse 0.0375
#define powerFactor 0.001
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

void updateCar (Car *car) {
  if (car->isThrottling) {
    car->power += powerFactor * car->isThrottling;
  } else {
    car->power -= powerFactor;
  }
  if (car->isReversing) {
    car->reverse += reverseFactor;
  } else {
    car->reverse -= reverseFactor;
  }

  car->power = fmax(0, fmin(maxPower, car->power));
  car->reverse = fmax(0, fmin(maxReverse, car->reverse));

  double direction = car->power > car->reverse ? 1 : -1;

  if (car->isTurningLeft) {
    car->angularVelocity -= direction * turnSpeed * car->isTurningLeft;
  }
  if (car->isTurningRight) {
    car->angularVelocity += direction * turnSpeed * car->isTurningRight;
  }

  car->xVelocity += sin2(car->angle) * (car->power - car->reverse);
  car->yVelocity += cos2(car->angle) * (car->power - car->reverse);

  car->x += car->xVelocity;
  car->y -= car->yVelocity;
  car->xVelocity *= drag;
  car->yVelocity *= drag;
  car->angle += car->angularVelocity;
  car->angularVelocity *= angularDrag;
}

//   Car localCar = {
//     x: WIDTH / 2,
//     y: HEIGHT / 2,
//     xVelocity: 0,
//     yVelocity: 0,
//     power: 0,
//     reverse: 0,
//     angle: 0,
//     angularVelocity: 0,
//     isThrottling: false,
//     isReversing: false,
//     isShooting: false,
//     isTurningLeft: false,
//     isTurningRight: false,
//   };

void updateWithControls(Car *car, ControlState controls) {
  bool changed;

  bool canTurn = car->power > 0.0025 || car->reverse;

  double throttle = controls.up ? 1 : 0;
  double reverse = controls.down ? 1 : 0;

  if (car->isThrottling != throttle || car->isReversing != reverse) {
    changed = true;
    car->isThrottling = throttle;
    car->isReversing = reverse;
  }
  bool turnLeft = canTurn && controls.left;
  bool turnRight = canTurn && controls.right;

  if (car->isTurningLeft != turnLeft) {
    changed = true;
    car->isTurningLeft = turnLeft;
  }
  if (car->isTurningRight != turnRight) {
    changed = true;
    car->isTurningRight = turnRight;
  }

  updateCar(car);
}
