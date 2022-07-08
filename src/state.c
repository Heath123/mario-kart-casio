#include "./state.h"

/*
typedef struct {
  double x;
  double y;
  double xVelocity;
  double yVelocity;
  double power;
  double angle;
  double angularVelocity;
} Kart;

typedef struct {
  Kart player;

  // TODO: Put these in Kart
  int kartSteerAnim;
  int hopStage;
  bool drifting;
  int driftDir;

  int totalFrameCount;
} State;
*/

State state;

void initState() {
  state.player.x = 3565.0 / 12;
  state.player.y = 2600.0 / 12;
  state.player.xVelocity = 0;
  state.player.yVelocity = 0;
  state.player.power = 0;
  state.player.angle = 0;
  state.player.angularVelocity = 0;
  state.hopStage = 0;
  state.drifting = false;
  state.driftDir = 0;
  state.driftCharge = 0;
  state.boostTime = -1;
  state.totalFrameCount = 0;
}
