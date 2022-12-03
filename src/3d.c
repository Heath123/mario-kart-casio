#include "./3d.h"

#include "./platform.h"
#include "./main.h"
#include "./tilemap.h"
#include "./maths.h"

#include <stdio.h>
#include <limits.h>

#include "../data-headers/generated_lut.h"
#include "platforms/gint.h"
// #include "./3d-bg-dat.h"

// #ifdef PROFILING_ENABLED
// #include "libprof.h"
// #endif

#define lowResCutoff (LCD_HEIGHT_PX * 3 / 4) - 30

inline void setPixel(int x, int y, color_t color) {
  VRAM[y * LCD_WIDTH_PX + x] = color;
}

int hFovModifier = 1 << 12;

// void __attribute__ ((noinline, hot)) normalFov() {
//   int angleCos = fpcos(angle);
//   int angleSin = fpsin(angle);
//   for (unsigned short y = horizon + 2; y < /*LCD_HEIGHT_PX*/lowResCutoff; y++) {
//     int dist = newLut[y - horizon];
//     int wx = -(LCD_WIDTH_PX / 2) / 2 * dist;
//     for (unsigned short x = 0; x < LCD_WIDTH_PX / 2; x++) {
//       int x2 = wx >> 6;
//       int y2 = dist;

//       // Rotate by angle
//       int newX = ((x2 * angleCos) >> 15) + ((y2 * angleSin) >> 15);
//       int newY = ((y2 * angleCos) >> 15) - ((x2 * angleSin) >> 15);

//       color_t col = samplePixel(newX >> 1, newY >> 1);
//       // if (col == 0) {
//       //   color_t* img_data = (color_t*) data_3d_bg + 4;
//       //   col = img_data[(LCD_WIDTH_PX * (y - (horizon + 2))) + (x << 1)];
//       // }
//       // setPixel(x * 2, y, col);
//       // setPixel(x * 2 + 1, y, col);
//       // Cast to an unsigned int array so two pixels are stored at once.
//       ((unsigned int *)VRAM)[y * (LCD_WIDTH_PX / 2) + x] = (col << 16 | col);

//       wx += dist;
//     }
//   }
//   // Fill in the low resolution area at half vertical resolution.
//   // TODO: remove duplicate code
//   for (unsigned short y = lowResCutoff; y < LCD_HEIGHT_PX; y += 2) {
//     int dist = newLut[y - horizon];
//     int wx = -(LCD_WIDTH_PX / 2) / 2 * dist;
//     for (unsigned short x = 0; x < LCD_WIDTH_PX / 2; x++) {
//       int x2 = wx >> 6;
//       int y2 = dist;

//       // Rotate by angle
//       int newX = ((x2 * angleCos) >> 15) + ((y2 * angleSin) >> 15);
//       int newY = ((y2 * angleCos) >> 15) - ((x2 * angleSin) >> 15);

//       color_t col = samplePixel(newX >> 1, newY >> 1);
//       // if (col == 0) {
//       //   color_t* img_data = (color_t*) data_3d_bg + 4;
//       //   col = img_data[(LCD_WIDTH_PX * (y - (horizon + 2))) + (x << 1)];
//       // }
//       // setPixel(x * 2, y, col);
//       // setPixel(x * 2 + 1, y, col);
//       // Cast to an unsigned int array so two pixels are stored at once.
//       ((unsigned int *)VRAM)[y * (LCD_WIDTH_PX / 2) + x] = (col << 16 | col);
//       ((unsigned int *)VRAM)[(y + 1) * (LCD_WIDTH_PX / 2) + x] = (col << 16 | col);

//       wx += dist;
//     }
//   }
// }

// void normalFov() {
//   for (unsigned short y = horizon + 2; y < LCD_HEIGHT_PX; y++) {
//     for (unsigned short x = 0; x < LCD_WIDTH_PX / 2; x++) {
//       int wx;
//       int wy;
//       screenToWorldSpace(x, y, &wx, &wy);
//       color_t col = samplePixel(wx, wy);
//       ((unsigned int *)VRAM)[y * (LCD_WIDTH_PX / 2) + x] = (col << 16 | col);
//     }
//   }
// }

void screenToWorldSpace(int x, int y, int* worldX, int* worldY) {
  int angleCos = fpcos(angle);
  int angleSin = fpsin(angle);

  x /= 2;

  int dist = newLut[y - horizon];
  int wx = -(LCD_WIDTH_PX / 2) / 2 * dist;
  wx += dist * x;

  int x2 = wx >> 6;
  int y2 = dist;

  // Rotate by angle
  int newX = ((x2 * angleCos) >> 15) + ((y2 * angleSin) >> 15);
  int newY = ((y2 * angleCos) >> 15) - ((x2 * angleSin) >> 15);

  *worldX = newX >> 1;
  *worldY = newY >> 1;
  *worldX += xOffset;
  *worldY += yOffset;
  *worldX >>= 2;
  *worldY >>= 2;
}

#define abs(x) ((x) < 0 ? -(x) : (x))

// void worldToScreenSpace(int worldX, int worldY, int* x, int* y) {
//   // RIDICULOUSLY inefficient way of doing this for testing purposes:
//   // Loop through all the pixels on the screen and find the one that
//   // is closest to the world coordinates.
//   int minDist = INT_MAX;
//   for (int i = 0; i < LCD_WIDTH_PX; i++) {
//     for (int j = horizon + 2; j < LCD_HEIGHT_PX; j++) {
//       int wx;
//       int wy;
//       screenToWorldSpace(i, j, &wx, &wy);
//       int dist = abs(worldX - wx) + abs(worldY - wy);
//       if (dist < minDist) {
//         minDist = dist;
//         *x = i;
//         *y = j;
//       }
//     }
//   }
//   printf("minDist: %d\n", minDist);
// }

// TODO: Take FOV into account
void worldToScreenSpace(int worldX, int worldY, int* x, int* y, int* dist) {
  worldX <<= 2;
  worldY <<= 2;
  worldX -= xOffset;
  worldY -= yOffset;
  worldX <<= 1;
  worldY <<= 1;
  // Undo the rotation
  int angleCos = fpcos(-angle);
  int angleSin = fpsin(-angle);

  int x2 = ((worldX * angleCos) >> 15) + ((worldY * angleSin) >> 15);
  int y2 = ((worldY * angleCos) >> 15) - ((worldX * angleSin) >> 15);

  // Find the closest distance in the lookup table
  int minDist = INT_MAX;
  int minDistIndex = 0;
  for (int i = 0; i < LCD_HEIGHT_PX - horizon - 2; i++) {
    int dist = abs(newLut[i] - y2);
    if (dist < minDist) {
      minDist = dist;
      minDistIndex = i;
    }
  }
  *y = minDistIndex + horizon;
  // int dist2 = newLut[minDistIndex];
  int dist2 = y2;
  *dist = dist2;
  // *x = LCD_WIDTH_PX / 2;
  minDist = INT_MAX;
  minDistIndex = 0;
  // Find the closest x value
  // int wx = -(LCD_WIDTH_PX / 2) / 2 * dist2;
  // for (int i = 0; i < LCD_WIDTH_PX / 2; i++) {
  //   int dist = abs((wx >> 6) - x2);
  //   if (dist < minDist) {
  //     minDist = dist;
  //     minDistIndex = i;
  //   }
  //   wx += dist2;
  // }
  // Better way to do it:
  int wx = -(LCD_WIDTH_PX / 2) / 2 * dist2;
  // We are asking how many dist2s you need to wx add to get to x2 from wx
  // So just directly calculate that instead of doing the loop
  if ((dist2 >> 1) == 0) {
    *x = INT_MAX;
    return;
  }
  // int numDist2s = (x2 - (wx >> 6)) / (dist2 >> 6);
  // Do the division before the shift for increased precision
  // int numDist2s = ((x2 << 6) - wx) / (dist2 >> 6);
  // numDist2s >>= 6;



  // int numDist2s = ((x2 << 6) - wx) / dist2;
  // minDistIndex = numDist2s /*- 1*/;

  // *x = minDistIndex * 2;

  // TODO: Division is slow on the SH4 CPU as there's no hardware divider
  // Can this be optimized? Or is the division just necessary?
  // Or is this done infrequently enough that it doesn't matter?
  *x = ((x2 << 6) - wx) / (dist2 >> 1);
  printf("x: %d\n", *x);
}

// Original
// void __attribute__ ((noinline)) fullRes() {
//   int angleCos = fpcos(angle);
//   int angleSin = fpsin(angle);
//   for (unsigned short y = horizon + 2; y < LCD_HEIGHT_PX; y++) {
//     int dist = newLut[y - horizon];
//     int wx = -(LCD_WIDTH_PX / 2) / 2 * dist;
//     for (unsigned short x = 0; x < LCD_WIDTH_PX / 2; x++) {
//       int x2 = wx >> 6;
//       int y2 = dist;

//       // Rotate by angle
//       int newX = ((x2 * angleCos) >> 15) + ((y2 * angleSin) >> 15);
//       int newY = ((y2 * angleCos) >> 15) - ((x2 * angleSin) >> 15);

//       color_t col = samplePixel(newX >> 1, newY >> 1);
//       // if (col == 0) {
//       //   color_t* img_data = (color_t*) data_3d_bg + 4;
//       //   col = img_data[(LCD_WIDTH_PX * (y - (horizon + 2))) + (x << 1)];
//       // }
//       // setPixel(x * 2, y, col);
//       // setPixel(x * 2 + 1, y, col);
//       // Cast to an unsigned int array so two pixels are stored at once.
//       ((unsigned int *)VRAM)[y * (LCD_WIDTH_PX / 2) + x] = (col << 16 | col);

//       wx += dist;
//     }
//   }
// }

// dx/dy version
// void __attribute__ ((noinline)) fullRes() {
//   int angleCos = fpcos(angle);
//   int angleSin = fpsin(angle);
//   for (unsigned short y = horizon + 2; y < LCD_HEIGHT_PX; y++) {
//     int dist = newLut[y - horizon];
//     int wx = -(LCD_WIDTH_PX / 2) / 2 * dist;
    
//     int y2 = dist;

//     int newX = (wx * (angleCos >> 6)) + (y2 * angleSin);
//     int newY = (y2 * angleCos) - (wx * (angleSin >> 6));

//     int dx =  (dist * (angleCos >> 6));
//     int dy = -(dist * (angleSin >> 6));

//     for (unsigned short x = 0; x < LCD_WIDTH_PX / 2; x++) {
//       color_t col = samplePixel(newX >> 16, newY >> 16);
//       ((unsigned int *)VRAM)[y * (LCD_WIDTH_PX / 2) + x] = (col << 16 | col);

//       newX += dx;
//       newY += dy;
//     }
//   }
// }

// TODO: Put this in fast on-chip memory?
unsigned int* vramLine;

#ifndef USE_ASM
void draw3DLine(int x, int y, int dx, int dy/*, unsigned int* vramLine*/) {
  for (unsigned short x2 = 0; x2 < LCD_WIDTH_PX / 2; x2++) {
    color_t col = samplePixel(x >> 16, y >> 16);
    *vramLine = (col << 16 | col);
    vramLine++;

    x += dx;
    y += dy;
  }
}
#endif

void __attribute__ ((noinline)) fullRes() {
  int angleCos = fpcos(angle);
  int angleSin = fpsin(angle);
  for (unsigned short y = horizon + 2; y < LCD_HEIGHT_PX; y++) {
    int dist = newLut[y - horizon];
    int wx = -(LCD_WIDTH_PX / 2) / 2 * dist;
    
    int y2 = dist;

    int newX = (wx * (angleCos >> 6)) + (y2 * angleSin);
    int newY = (y2 * angleCos) - (wx * (angleSin >> 6));

    int dx =  (dist * (angleCos >> 6));
    int dy = -(dist * (angleSin >> 6));

    vramLine = (unsigned int *)VRAM + y * (LCD_WIDTH_PX / 2);
    draw3DLine(newX, newY, dx, dy/*, vramLine*/);
  }
}

#define normalFov fullRes

void __attribute__ ((noinline)) changedFov() {
  int angleCos = fpcos(angle);
  int angleSin = fpsin(angle);
  for (unsigned short y = horizon + 2; y < /*LCD_HEIGHT_PX*/lowResCutoff; y++) {
    int dist = newLut[y - horizon];
    int dx = (dist * hFovModifier) >> 12;
    int wx = -(LCD_WIDTH_PX / 2) / 2;
    wx *= dx;
    for (unsigned short x = 0; x < LCD_WIDTH_PX / 2; x++) {
      int x2 = wx >> 6;
      int y2 = dist;

      // Rotate by angle
      int newX = ((x2 * angleCos) >> 15) + ((y2 * angleSin) >> 15);
      int newY = ((y2 * angleCos) >> 15) - ((x2 * angleSin) >> 15);

      color_t col = samplePixel(newX >> 1, newY >> 1);
      // if (col == 0) {
      //   color_t* img_data = (color_t*) data_3d_bg + 4;
      //   col = img_data[(LCD_WIDTH_PX * (y - (horizon + 2))) + (x << 1)];
      // }      // setPixel(x * 2, y, col);
      // setPixel(x * 2 + 1, y, col);
      // Cast to an unsigned int array so two pixels are stored at once.
      ((unsigned int *)VRAM)[y * (LCD_WIDTH_PX / 2) + x] = (col << 16 | col);

      wx += dx;
    }
  }
  // Fill in the low resolution area at half vertical resolution.
  // TODO: remove duplicate code
  for (unsigned short y = lowResCutoff; y < LCD_HEIGHT_PX; y += 2) {
    int dist = newLut[y - horizon];
    int dx = (dist * hFovModifier) >> 12;
    int wx = -(LCD_WIDTH_PX / 2) / 2;
    wx *= dx;
    for (unsigned short x = 0; x < LCD_WIDTH_PX / 2; x++) {
      int x2 = wx >> 6;
      int y2 = dist;

      // Rotate by angle
      int newX = ((x2 * angleCos) >> 15) + ((y2 * angleSin) >> 15);
      int newY = ((y2 * angleCos) >> 15) - ((x2 * angleSin) >> 15);

      color_t col = samplePixel(newX >> 1, newY >> 1);
      // if (col == 0) {
      //   color_t* img_data = (color_t*) data_3d_bg + 4;
      //   col = img_data[(LCD_WIDTH_PX * (y - (horizon + 2))) + (x << 1)];
      // }
      // setPixel(x * 2, y, col);
      // setPixel(x * 2 + 1, y, col);
      // Cast to an unsigned int array so two pixels are stored at once.
      ((unsigned int *)VRAM)[y * (LCD_WIDTH_PX / 2) + x] = (col << 16 | col);
      ((unsigned int *)VRAM)[(y + 1) * (LCD_WIDTH_PX / 2) + x] = (col << 16 | col);

      wx += dx;
    }
  }
}

void __attribute__ ((noinline)) draw3D(bool highQuality) {
  if (hFovModifier == 1 << 12) {
    if (highQuality) {
      fullRes();
    } else {
      normalFov();
    }
  } else {
    changedFov();
  }
}
