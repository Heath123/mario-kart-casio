#include "./physics.h"

#include "./configurableConstants.h"
#include "./main.h"
#include "./maths.h"
#include "./buttons.h"
#include "./state.h"
#include "./data.h"
#include "./particles.h"
#include "./tilemap.h"

#include <stdbool.h>

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

#define MIN(X, Y) (((X) < (Y)) ? (X) : (Y))
#define MAX(X, Y) (((X) < (Y)) ? (Y) : (X))

// #define maxSteerNormal 1
// #define minSteerDrift 0.2 * (1.7 / 2.2)
// #define neutralSteerDrift (1.7 / 2.2)
// #define maxSteerDrift 1.7
extern double maxSteerNormal;
extern double minSteerDrift;
extern double neutralSteerDrift;
extern double maxSteerDrift;

void boostKart(Kart *kart, int amount) {
  kart->boostTime = MAX(kart->boostTime, amount);
  if (!kart->isPlayer) return;
  if (amount >= 100) {
    addParticle(2, LCD_WIDTH_PX / 2 - 28, LCD_HEIGHT_PX - 70, 0, 0);
  } else if (amount >= 50) {
    addParticle(1, LCD_WIDTH_PX / 2 - 28, LCD_HEIGHT_PX - 70, 0, 0);
  } else {
    addParticle(3, LCD_WIDTH_PX / 2 - 28, LCD_HEIGHT_PX - 70, 0, 0);
  }
}

// TODO: Remove this somehow or make it more clear
#define scale 4

void updateWithControls(Kart *kart, ButtonState controls) {
  // Save the previous position, to restore if we hit a wall
  double oldKartY = kart->y;
  double oldKartX = kart->x;

  // Get the tile the kart is on, and its type.
  // TODO: Use all the tiles the kart is touching?
  unsigned char currentTile = getTileID(kart->x / scale, kart->y / scale);
  enum TileType tileType = getTileType(currentTile);

  bool isOffRoad = tileType == Offroad || tileType == Grass || tileType == ShallowWater;

  if (tileType == BoostPad) {
    boostKart(kart, 100);
  } else if (tileType == JumpBar) {
    controls.hop = true;
  }

  // If the kart is still drifting...
  if (kart->drifting && !isOffRoad) {
    if ((controls.left && kart->driftDir == -1) || (controls.right && kart->driftDir == 1)) {
      // Drift charge builds faster when holding the same direction as the drift
      kart->driftCharge += 2;
    } else {
      kart->driftCharge++;
    }
  } else {
    // If the kart is not drifting, or is off road, reset the drift charge to 0
    kart->driftCharge = 0;
  }

  if (!controls.hop) {
    // When the player lets go of the drift button...
    if (kart->drifting && kart->driftCharge >= 60) {
      // apply the relevant boost...
      if (kart->driftCharge > 360) {
        boostKart(kart, 100);
      } else if (kart->driftCharge >= 180) {
        boostKart(kart, 50);
      } else {
        boostKart(kart, 20);
      }
    }
    // ...and cancel the drift
    kart->drifting = false;
  }

  // If the hop button was pressed, and the kart is not currently hopping...
  if (controls.hop && !kart->lastHop && kart->hopStage == 0) {
    // ...start the hop animation.
    kart->hopStage = 1;
    if (controls.left || controls.right) {
      // If a direction is held, start a drift (this can also be done when the hop finishes)
      kart->drifting = true;
      kart->driftDir = controls.left ? -1 : 1;
    }
  }

  // If a hop is in progress...
  if (kart->hopStage != 0) {
    // ...continue the hop animation.
    kart->hopStage++;
    if (kart->hopStage >= 15) {
      kart->hopStage = 0;
      if (!kart->drifting && (controls.left || controls.right)) {
        // If a direction is held, start a drift
        kart->drifting = true;
        kart->driftDir = controls.left ? -1 : 1;
      }
    }
  }

  bool boosting = false;
  if (kart->boostTime >= 0) {
    // If we are boosting, set a flag and decrement the remaining time
    kart->boostTime--;
    boosting = true;
  }
  
  if (boosting) {
    // TODO: Remove this seemingly duplicate variable
    applyBoost = true;
    kart->power = maxPower;
    controls.accel = true;
  } else {
    applyBoost = false;
  }

  if (!boosting && isOffRoad) {
    applyOffRoadDrag = true;
  } else {
    applyOffRoadDrag = false;
  }

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

  kart->x += kart->xVelocity * 12;
  kart->y -= kart->yVelocity * 12;
  double calcDrag = applyOffRoadDrag ? offRoadDrag : drag;
  kart->xVelocity *= calcDrag;
  kart->yVelocity *= calcDrag;
  kart->angle += kart->angularVelocity;
  kart->angle = dmod(kart->angle, 3.1415926 * 2);
  kart->angularVelocity *= angularDrag;

  unsigned char newTile = getTileID(kart->x / scale, kart->y / scale);

  if (getTileType(newTile) == SolidBlock) {
    kart->x = oldKartX;
    kart->y = oldKartY;
  }

  // Finish line is tile 254
  if (newTile == 254 && currentTile != 254) {
    kart->lapCount++;
  }

  kart->lastHop = controls.hop;
}
