#include "./3d.h"

#include "./platform.h"
#include "./main.h"
#include "./tilemap.h"
#include "./maths.h"

#include "../data-headers/generated_lut.h"

inline void setPixel(int x, int y, color_t color) {
  VRAM[y * LCD_WIDTH_PX + x] = color;
}

int hFovModifier = 1 << 12;

void changedFov() {
  int angleCos = fpcos(angle);
  int angleSin = fpsin(angle);
  for (unsigned short y = horizon + 2; y < LCD_HEIGHT_PX; y++) {
    int dist = newLut[y - horizon];
    int dx = (dist * hFovModifier) >> 12;
    int wx = -(LCD_WIDTH_PX / 2) / 2;
    wx *= dx;
    for (unsigned short x = 0; x < LCD_WIDTH_PX / 2; x++) {
      wx += dx;

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

void normalFov() {
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

void draw3D() {
  if (hFovModifier == 1 << 12) {
    normalFov();
  } else {
    changedFov();
  }
}
