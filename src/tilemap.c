#include "./main.h"

#include "../data-headers/track.h"

#define precision 8

unsigned char getTileType(short xPos, short yPos) {
  // __builtin_expect(xPos < 0 || xPos >= trackImageWidth || yPos < 0 || yPos >= trackImageHeight, 0);
  if (xPos < 0 || xPos >= trackImageWidth || yPos < 0 || yPos >= trackImageHeight) {
    return 0;  // Grass
  } else {
    // Divide by 8
    int xPixel = xPos >> 3;
    int yPixel = yPos >> 3;

    return trackData[((yPixel * (trackImageWidth / precision)) + xPixel)];
  }
}

unsigned short samplePixel(short xPos, short yPos) {
  xPos += xOffset;
  yPos += yOffset;

  // Divide by 4
  xPos = xPos >> 2;
  yPos = yPos >> 2;

  // Get the position of the pixel in the tile
  int xPixelInTile = xPos & (precision - 1);
  int yPixelInTile = yPos & (precision - 1);

  // Get the colour of the pixel in the tile
  return tileData[getTileType(xPos, yPos)][(yPixelInTile * precision) + xPixelInTile];
}
