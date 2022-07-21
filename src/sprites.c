#include "./sprites.h"

#define MAX(a, b) ((a) > (b) ? (a) : (b))

void draw_loop_x(const struct image* img, int x, int y, int xOffset, int drawWidth) {
  // Split into multiple partial draws.
  xOffset %= get_width(img);
  int currentX = -xOffset;
  // Keep drawing until currentX >= drawWidth.
  while (currentX < drawWidth) {
    int sx = 0;
    if (currentX < 0) {
      sx = -currentX;
    }
    int w = get_width(img);
    if (currentX + w > drawWidth) {
      w = drawWidth - currentX;
    }
    draw_partial(img, x + currentX, y, sx, 0, w, get_height(img));
    currentX += w;
  }
}
