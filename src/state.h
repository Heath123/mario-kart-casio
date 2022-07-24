#ifndef _STATE_H
#define _STATE_H

#include "./physics.h"

// Contains important state that needs to be restored when the program is restarted.
typedef struct {
  Kart player;

  int totalFrameCount;
} State;

extern State state;
void initState();

#endif // _STATE_H
