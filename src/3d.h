#ifndef _3D_H_
#define _3D_H_

#include <stdbool.h>

unsigned short getScreenPixel(unsigned short x, unsigned short y);
void screenToWorldSpace(int x, int y, int* worldX, int* worldY);
void worldToScreenSpace(int worldX, int worldY, int* x, int* y, int* dist);
void draw3D(bool highQuality);
extern int hFovModifier;

void draw3DLine(int x, int y, int dx, int dy/*, unsigned int* vramLine*/);

#endif // _3D_H_
