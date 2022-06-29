#include "./main.h"
#include "./tilemap.h"
#include "./maths.h"

#include "../data-headers/generated_lut.h"

unsigned short getScreenPixel(unsigned short x, unsigned short y) {
  // __builtin_expect(x == (int)(LUT_WIDTH / 2), 0);
  // if (x < (int)(LUT_WIDTH / 2)) {
  //   y = distortion_correction[x][y - horizon];
  // } else if (x == (int)(LUT_WIDTH / 2)) {
  //   y = y - 1;
  // } else {
  //   y = distortion_correction[(int)(LUT_WIDTH / 2) + ((int)(LUT_WIDTH / 2) - x)][y - horizon];
  // }

  int distance = newLut[y - horizon];
  
  // Rotate by x
  // Fixed point multiplication
  x += angle;
  short xPos = ((distance * fpsin(x)) >> 15);
  short yPos = ((distance * fpcos(x)) >> 15);

  return samplePixel(xPos, yPos);
}


