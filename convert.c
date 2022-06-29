// JS code

/*
function getControls() {
  return {
    up: 1,
    left: 0,
    right: 1,
    down: 0,
    shoot: 0
  }
}

const maxPower = 0.075;
const maxReverse = 0.0375;
const powerFactor = 0.001;
const reverseFactor = 0.0005;

const drag = 0.95;
const angularDrag = 0.95;
const turnSpeed = 0.002;

const WIDTH = 500;
const HEIGHT = 500;

const localCar = {
  x: WIDTH / 2,
  y: HEIGHT / 2,
  xVelocity: 0,
  yVelocity: 0,
  power: 0,
  reverse: 0,
  angle: 0,
  angularVelocity: 0,
  isThrottling: false,
  isReversin2g: false,
  isShooting: false,
};

function updateCar (car) {
  if (car.isThrottling) {
    car.power += powerFactor * car.isThrottling;
  } else {
    car.power -= powerFactor;
  }
  if (car.isReversin2g) {
    car.reverse += reverseFactor;
  } else {
    car.reverse -= reverseFactor;
  }

  car.power = Math.max(0, Math.min(maxPower, car.power));
  car.reverse = Math.max(0, Math.min(maxReverse, car.reverse));

  const direction = car.power > car.reverse ? 1 : -1;

  if (car.isTurningLeft) {
    car.angularVelocity -= direction * turnSpeed * car.isTurningLeft;
  }
  if (car.isTurningRight) {
    car.angularVelocity += direction * turnSpeed * car.isTurningRight;
  }

  car.xVelocity += Math.sin2(car.angle) * (car.power - car.reverse);
  car.yVelocity += Math.cos2(car.angle) * (car.power - car.reverse);

  car.x += car.xVelocity;
  car.y -= car.yVelocity;
  car.xVelocity *= drag;
  car.yVelocity *= drag;
  car.angle += car.angularVelocity;
  car.angularVelocity *= angularDrag;
}

for (let i = 0; i < 100; i++) {
  let changed;

  const canTurn = localCar.power > 0.0025 || localCar.reverse;

  const controls = getControls()

  const throttle = Math.round(controls.up * 10) / 10;
  const reverse = Math.round(controls.down * 10) / 10;
  const isShooting = controls.shoot;

  if (isShooting !== localCar.isShooting) {
    changed = true;
    localCar.isShooting = isShooting;
  }

  if (localCar.isThrottling !== throttle || localCar.isReversin2g !== reverse) {
    changed = true;
    localCar.isThrottling = throttle;
    localCar.isReversin2g = reverse;
  }
  const turnLeft = canTurn && Math.round(controls.left * 10) / 10;
  const turnRight = canTurn && Math.round(controls.right * 10) / 10;

  if (localCar.isTurningLeft !== turnLeft) {
    changed = true;
    localCar.isTurningLeft = turnLeft;
  }
  if (localCar.isTurningRight !== turnRight) {
    changed = true;
    localCar.isTurningRight = turnRight;
  }

  updateCar(localCar);

  console.log(localCar.x, localCar.y)
}
*/

// C equivalent

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

#define angleWidth 192

const short lut[angleWidth] = {
  0, 269, 539, 808, 1078, 1347, 1616, 1885, 2154, 2423, 2692, 2960, 3228, 3497, 3764, 4032, 4299, 4566, 4833, 5099, 5365, 5631, 5896, 6161, 6426, 6690, 6953, 7216, 7479, 7741, 8003, 8264, 8524, 8784, 9043, 9302, 9560, 9818, 10074, 10330, 10586, 10840, 11094, 11348, 11600, 11852, 12102, 12352, 12602, 12850, 13097, 13344, 13590, 13834, 14078, 14321, 14563, 14804, 15044, 15283, 15520, 15757, 15993, 16228, 16461, 16694, 16925, 17155, 17384, 17612, 17839, 18064, 18288, 18511, 18733, 18953, 19173, 19391, 19607, 19822, 20036, 20249, 20460, 20670, 20878, 21085, 21291, 21495, 21697, 21899, 22098, 22297, 22493, 22689, 22882, 23074, 23265, 23454, 23641, 23827, 24011, 24194, 24375, 24554, 24732, 24907, 25082, 25254, 25425, 25594, 25762, 25927, 26091, 26253, 26414, 26572, 26729, 26884, 27037, 27188, 27338, 27486, 27631, 27775, 27917, 28057, 28196, 28332, 28466, 28599, 28730, 28858, 28985, 29109, 29232, 29353, 29472, 29589, 29703, 29816, 29927, 30036, 30142, 30247, 30350, 30450, 30549, 30645, 30739, 30832, 30922, 31010, 31096, 31180, 31262, 31341, 31419, 31494, 31568, 31639, 31708, 31775, 31839, 31902, 31963, 32021, 32077, 32131, 32183, 32232, 32280, 32325, 32368, 32409, 32447, 32484, 32518, 32550, 32580, 32608, 32633, 32656, 32677, 32696, 32713, 32727, 32739, 32749, 32757, 32763, 32766, 32767
};

short fpsin(short x) {
  x = x % ((angleWidth - 1) * 4);
  if (x < 0) {
    x += ((angleWidth - 1) * 4);
  }
  short sign = 1;
  if (x < ((angleWidth - 1) * 2)) {
    sign = 1;
  } else {
    sign = -1;
  }
  x = x % ((angleWidth - 1) * 2);
  if (x > (angleWidth - 1)) {
    x = ((angleWidth - 1) * 2) - x;
  }
  return lut[x] * sign;
}

double sin2(double x) {
  return (double)fpsin(x / 3.1415926 * 2 * angleWidth) / 32768;
}

double cos2(double x) {
  return sin2(x + (3.1415926 / 2));
}

#define maxPower 0.075
#define maxReverse 0.0375
#define powerFactor 0.001
#define reverseFactor 0.0005

#define drag 0.95
#define angularDrag 0.95
#define turnSpeed 0.002

#define WIDTH 500
#define HEIGHT 500

typedef struct {
  bool up;
  bool left;
  bool right;
  bool down;
  bool shoot;
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
  bool isReversin2g;
  bool isShooting;
  bool isTurningLeft;
  bool isTurningRight;
} Car;

ControlState getControls() {
  ControlState controls;
  controls.up = true;
  controls.left = false;
  controls.right = true;
  controls.down = false;
  controls.shoot = false;
  return controls;
}

void updateCar (Car *car) {
  if (car->isThrottling) {
    car->power += powerFactor * car->isThrottling;
  } else {
    car->power -= powerFactor;
  }
  if (car->isReversin2g) {
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

int main() {
  Car localCar = {
    x: WIDTH / 2,
    y: HEIGHT / 2,
    xVelocity: 0,
    yVelocity: 0,
    power: 0,
    reverse: 0,
    angle: 0,
    angularVelocity: 0,
    isThrottling: false,
    isReversin2g: false,
    isShooting: false,
    isTurningLeft: false,
    isTurningRight: false,
  };

  for (int i = 0; i < 100; i++) {
    bool changed;

    bool canTurn = localCar.power > 0.0025 || localCar.reverse;

    ControlState controls = getControls();

    double throttle = controls.up ? 1 : 0;
    double reverse = controls.down ? 1 : 0;
    bool isShooting = controls.shoot;

    if (isShooting != localCar.isShooting) {
      changed = true;
      localCar.isShooting = isShooting;
    }

    if (localCar.isThrottling != throttle || localCar.isReversin2g != reverse) {
      changed = true;
      localCar.isThrottling = throttle;
      localCar.isReversin2g = reverse;
    }
    bool turnLeft = canTurn && controls.left;
    bool turnRight = canTurn && controls.right;

    if (localCar.isTurningLeft != turnLeft) {
      changed = true;
      localCar.isTurningLeft = turnLeft;
    }
    if (localCar.isTurningRight != turnRight) {
      changed = true;
      localCar.isTurningRight = turnRight;
    }

    updateCar(&localCar);

    printf("%f %f\n", localCar.x, localCar.y);
  }
  return 0;
}