#ifndef _PHYSICS_H
#define _PHYSICS_H

#include <stdbool.h>

#include "./buttons.h"
#include "./data.h"

typedef struct {
  bool isPlayer;

  double x;
  double y;
  double xVelocity;
  double yVelocity;
  double power;
  // double reverse;
  double angle;
  double angularVelocity;

  int kartSteerAnim;
  int hopStage;
  bool drifting;
  int driftDir;
  int driftCharge;
  int boostTime;
  int lapCount;

  bool lastHop;
} Kart;

extern bool applyOffRoadDrag;
extern bool applyBoost;
// extern double turnSpeedModifier;
extern double maxPower;
extern double powerFactor;

void updateWithControls(Kart *car, ButtonState controls);

#endif // _PHYSICS_H
