#include "./particles.h"

#include "./sprites.h"
#include "../data-headers/images.h"

#define MAX_PARTICLES 32

ParticleType types[] = {
  // Smoke
  {
    .maxAge = 12,
    .animLength = 3,
    .animDelay = 4,
    .animFrames = imgs_smoke
  },
  // Boost fire
  {
    .maxAge = 20,
    .animLength = 5,
    .animDelay = 4,
    .animFrames = imgs_boost
  },
};

ParticleState particles[MAX_PARTICLES];

void initParticles() {
  for (int i = 0; i < MAX_PARTICLES; i++) {
    particles[i].age = -1;
  }
}

void tickParticles() {
  for (int i = 0; i < MAX_PARTICLES; i++) {
    ParticleState *particle = &particles[i];
    // Age < 0 means the particle is not active
    if (particle->age >= 0) {
      if (particle->age > types[particle->type].maxAge) {
        // Deactivate the particle
        particle->age = -1;
        continue;
      }
      particle->age++;
      particle->x += particle->xVel;
      particle->y += particle->yVel;
      // Draw the particle
      int frame = (particle->age / types[particle->type].animLength) % types[particle->type].animLength;
      draw(types[particle->type].animFrames[frame], particle->x, particle->y);
    }
  }
}

void addParticle(int type, int x, int y, int xVel, int yVel) {
  // Find the first free particle slot
  int slot = -1;
  for (int i = 0; i < MAX_PARTICLES; i++) {
    if (particles[i].age < 0) {
      slot = i;
      break;
    }
  }
  if (slot < 0) {
    // No free particle slots
    return;
  }
  ParticleState *particle = &particles[slot];
  particle->type = type;
  particle->x = x;
  particle->y = y;
  particle->xVel = xVel;
  particle->yVel = yVel;
  particle->age = 0;
}
