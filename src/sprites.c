#include <fxcg/display.h>

#include "./main.h"

// From https://www.cemetech.net/forum/viewtopic.php?t=6114&postdays=0&postorder=asc&start=100
void CopySpriteMasked(const void* datar, int x, int y, int width, int height, int maskcolor) {
  color_t* data = (color_t*)datar;
  color_t* VRAM2 = (color_t*)VRAM;
  VRAM2 += LCD_WIDTH_PX * y + x;
  for (int j = y; j < y + height; j++) {
    for (int i = x; i < x + width; i++) {
      if (*(data) != maskcolor) {
        *(VRAM2++) = *(data++);
      } else {
        VRAM2++;
        data++;
      }
    }
    VRAM2 += LCD_WIDTH_PX - width;
  }
}

// Version of the function above that draws the sprite flipped horizontally
void CopySpriteMaskedFlipped(const void* datar, int x, int y, int width, int height, int maskcolor) {
  color_t* data = (color_t*)datar;
  color_t* VRAM2 = (color_t*)VRAM;
  VRAM2 += LCD_WIDTH_PX * y + x;
  for (int j = y; j < y + height; j++) {
    // Start at the end of the line and work backwards
    data += width - 1;
    for (int i = x; i < x + width; i++) {
      if (*(data) != maskcolor) {
        *(VRAM2++) = *(data--);
      } else {
        VRAM2++;
        data--;
      }
    }
    data += width + 1;
    VRAM2 += LCD_WIDTH_PX - width;
  }
}

void draw(const unsigned short* data, int x, int y) {
  // The height and width of the sprite are the first two elements in the data array
  int width = data[0];
  int height = data[1];
  // The data array starts at index 2
  const unsigned short* data2 = data + 2;
  // Now draw the sprite
  CopySpriteMasked(data2, x, y, width, height, 0x4fe0);
}
