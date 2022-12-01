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

// unsigned char getTileID(short l0, short l1) {
//   unsigned int si0, si1, si2;
//   si0 = l0;
//   si1 = l1;
//   si0 |= si1;
//   si1 = 2047u;
//   si0 = si0 <= si1;
//   if (si0) {
//     si0 = l1;
//     si1 = 65528u;
//     si0 &= si1;
//     si1 = 5u;
//     si0 <<= (si1 & 31);
//     si1 = l0;
//     si2 = 65528u;
//     si1 &= si2;
//     si2 = 3u;
//     si1 >>= (si2 & 31);
//     si0 += si1;
//     // si1 = 1024u;
//     // si0 += si1;
//     // si0 = load(si0);
//     si0 = tilemap[si0];
//   } else {
//     si0 = 0u;
//   }
//   return si0;
// }

enum TileType getTileType(int tileID) {
  return (enum TileType) track.tileTypes[tileID];
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
