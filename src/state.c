#include "./state.h"

#include "./data.h"

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
  int driftCharge;
  int boostTime;
  int lapCount;

  if (state.totalFrameCoun
  int totalFrameCount;
} State;
*/

State state;

void initState() {
  state = (State) {
    .player = (Kart) {
      .x = ((float) track.startX) / 12,
      .y = ((float) track.startY) / 12,
      .xVelocity = 0,
      .yVelocity = 0,
      .power = 0,
      .angle = 0,
      .angularVelocity = 0,
    },
    .kartSteerAnim = 0,
    .hopStage = 0,
    .drifting = false,
    .driftDir = 0,
    .driftCharge = 0,
    .boostTime = -1,
    .totalFrameCount = 0,
    .lapCount = 0,
  };
}
