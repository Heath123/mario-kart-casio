#include "./3d.h"

#include <fxcg/display.h>

#include "./main.h"
#include "./tilemap.h"
#include "./maths.h"

#include "../data-headers/generated_lut.h"

#define LCD_WIDTH_PX 384
#define LCD_HEIGHT_PX 216

inline void setPixel(int x, int y, color_t color) {
  VRAM[y * LCD_WIDTH_PX + x] = color;
}

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

void new3D() {
  int angleCos = fpcos(angle);
  int angleSin = fpsin(angle);
  for (unsigned short y = horizon + 2; y < LCD_HEIGHT_PX; y++) {
    int dist = newLut[y - horizon];
    int wx = -(LCD_WIDTH_PX / 2) / 2 * dist;
    for (unsigned short x = 0; x < LCD_WIDTH_PX / 2; x++) {
      wx += dist;

      int x2 = wx >> 6;
      int y2 = dist;

      // Rotate by angle
      int newX = ((x2 * angleCos) >> 15) + ((y2 * angleSin) >> 15);
      int newY = ((y2 * angleCos) >> 15) - ((x2 * angleSin) >> 15);

      color_t col = samplePixel(newX >> 1, newY >> 1);
      // setPixel(x * 2, y, col);
      // setPixel(x * 2 + 1, y, col);
      // Cast to an unsigned int array so two pixels are stored at once.
      ((unsigned int *)VRAM)[y * (LCD_WIDTH_PX / 2) + x] = (col << 16 | col);
    }
  }
}
