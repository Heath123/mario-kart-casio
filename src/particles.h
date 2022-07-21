#ifndef _PARTICLES_H_
#define _PARTICLES_H_

#include <stdbool.h>

#include "./platform.h"

typedef struct {
  short type;
  short age;

  short x;
  short y;

  char xVel;
  char yVel;
} ParticleState;

typedef struct {
  short maxAge;
  short animLength;
  char animDelay;
  const struct image** animFrames;
} ParticleType;

void initParticles();
bool tickParticles();
void addParticle(int type, int x, int y, int xVel, int yVel);

#endif // _PARTICLES_H_
