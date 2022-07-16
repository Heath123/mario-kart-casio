#ifndef _MAIN_H
#define _MAIN_H

#include <stdbool.h>

extern short angle;
extern short xOffset;
extern short yOffset;

extern short index2;
extern unsigned short element;

extern int debugType;

int mod(int a, int b);
float sin(int angle);
float cos(int angle);

// TODO: Move into a separate file
void fillSky(unsigned short yMin, unsigned short yMax);

// Profiling
extern int timeUpdate;
extern int time3D;
extern int timeLogic;
extern int timeLogic1;
extern int timeLogic2;
extern int timeLogic3;
extern int timePhysics;
extern int timeSprites;
extern int timeKartSprite;
extern int timeDebugHud;

#endif // _MAIN_H
