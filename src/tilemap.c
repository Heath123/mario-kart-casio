#include "./tilemap.h"

#include "./main.h"
#include "./data.h"

// #include "../data-headers/track.h"

#define tileSize 8
#define trackImageWidth 256 * tileSize
#define trackImageHeight 256 * tileSize

unsigned char getTileID(short xPos, short yPos) {
  // __builtin_expect(xPos < 0 || xPos >= trackImageWidth || yPos < 0 || yPos >= trackImageHeight, 0);
  if((unsigned short) xPos >= trackImageWidth || (unsigned short) yPos >= trackImageHeight) {
    return 0;  // Grass
  } else {
    // Divide by 8
    int xPixel = xPos >> 3;
    int yPixel = yPos >> 3;

    return /*track.*/tilemap[((yPixel * (trackImageWidth / tileSize)) + xPixel)];
  }
}

unsigned short samplePixel(short xPos, short yPos) {
  xPos += xOffset;
  yPos += yOffset;

  // Divide by 4
  xPos = xPos >> 2;
  yPos = yPos >> 2;

  // Get the position of the pixel in the tile
  int xPixelInTile = xPos & (tileSize - 1);
  int yPixelInTile = yPos & (tileSize - 1);

  // Get the colour of the pixel in the tile
  unsigned char index = /*track.*/tileset[getTileID(xPos, yPos)][(yPixelInTile * tileSize) + xPixelInTile];
  return /*track.*/palette[index];
  // return index;
}

// unsigned short samplePixelFast(short xPos, short yPos) {
//   xPos += xOffset;
//   yPos += yOffset;

//   // Divide by 4
//   xPos = xPos >> 2;
//   yPos = yPos >> 2;

//   // Get the colour of the middle pixel of the tile
//   return *track.tileImageData[getTileID(xPos, yPos)][(4 * tileSize) + 4];
// }
