#ifndef _MAIN_H
#define _MAIN_H

#include <stdbool.h>

extern short angle;
extern short xOffset;
extern short yOffset;

extern short index2;
extern unsigned short element;

extern int debugType;

extern unsigned short* VRAM;

int mod(int a, int b);
float sin(int angle);
float cos(int angle);

#endif // _MAIN_H
