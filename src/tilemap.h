#ifndef _TILEMAP_H
#define _TILEMAP_H

#include <stdbool.h>

unsigned char getTileID(short xPos, short yPos);
unsigned short samplePixel(short xPos, short yPos);

#endif // _TILEMAP_H
