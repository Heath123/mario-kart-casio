#ifndef _PARTICLES_H_
#define _PARTICLES_H_

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
  const unsigned short** animFrames;
} ParticleType;

void initParticles();
void tickParticles();
void addParticle(int type, int x, int y, int xVel, int yVel);

#endif // _PARTICLES_H_
