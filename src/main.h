#ifndef _MAIN_H
#define _MAIN_H

#include <stdbool.h>

extern int totalFrameCount;

extern short angle;
extern short xOffset;
extern short yOffset;

extern bool drifting;
extern int driftDir;

extern short index2;
extern unsigned short element;

extern int debugType;

extern unsigned short* VRAM;

int mod(int a, int b);
float sin(int angle);
float cos(int angle);

// TODO: Move into a separate file
void fillSky(unsigned short yMin, unsigned short yMax);

#endif // _MAIN_H
