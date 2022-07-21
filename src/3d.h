#ifndef _3D_H_
#define _3D_H_

#include <stdbool.h>

unsigned short getScreenPixel(unsigned short x, unsigned short y);
void draw3D(bool highQuality);
extern int hFovModifier;

#endif // _3D_H_
