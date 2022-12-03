#ifndef _TILEMAP_H
#define _TILEMAP_H

#include <stdbool.h>

// unsigned char getTileID(short xPos, short yPos);
unsigned char getTileID(int xPos, int yPos);
enum TileType getTileType(int tileID);
unsigned short samplePixel(int xPos, int yPos);

#endif // _TILEMAP_H
