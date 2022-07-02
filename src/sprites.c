#include "./sprites.h"

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

void CopySpriteMaskedAlpha(const void*datar, int x, int y, int width, int height, color_t maskcolor, int alpha) { 
  color_t*data = (color_t*) datar; 
  color_t* VRAM = (color_t*)GetVRAMAddress(); 
  VRAM += LCD_WIDTH_PX*y + x; 
  alpha %= 32; 
  for(int j=y; j<y+height; j++) { 
    for(int i=x; i<x+width;  i++) { 
      if (*(data) != maskcolor) { 
      *(VRAM) = (color_t)((((int)(*data & 0xf81f) * alpha + (int)(*VRAM & 0xf81f) * (32-alpha) + 0x8010) >> 5) & 0xf81f) | 
            (color_t)((((int)(*data & 0x07e0) * alpha + (int)(*VRAM & 0x07e0) * (32-alpha) + 0x0400) >> 6) & 0x07e0); 
        VRAM++; data++; 
      } else { VRAM++; data++; } 
    } 
    VRAM += LCD_WIDTH_PX-width; 
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

// Copy a sprite that loops around with an X offset
void CopySpriteLoopX(const void* datar, int x, int y, int width, int height, int xOffset, int drawWidth, int maskcolor) {
  color_t* data = (color_t*)datar;
  // color_t* VRAM2 = (color_t*)VRAM;
  // Loop over all the y positions
  for (int j = 0; j < height; j++) {
    // Loop over all the x positions
    for (int i = 0; i < drawWidth; i++) {
      // Get the pixel at the current position
      color_t pixel = data[(j * width) + ((i + xOffset) % width)];
      // Draw the pixel
      if (pixel != maskcolor) {
        VRAM[(j + y) * LCD_WIDTH_PX + (i + x)] = pixel;
      }
    }
  }
}


void draw(const unsigned short* data, int x, int y) {
  // The height and width of the sprite are the first two elements in the data array
  int width = data[0];
  int height = data[1];
  // The offsets of the x and y positions are the third and fourth elements in the data array
  int xOffset = data[2];
  int yOffset = data[3];
  // The data array starts at index 4
  const unsigned short* data2 = data + 4;
  // Now draw the sprite
  CopySpriteMasked(data2, x + xOffset, y + yOffset, width, height, 0x4fe0);
}

void draw_alpha(const unsigned short* data, int x, int y, int alpha) {
  // The height and width of the sprite are the first two elements in the data array
  int width = data[0];
  int height = data[1];
  // The offsets of the x and y positions are the third and fourth elements in the data array
  int xOffset = data[2];
  int yOffset = data[3];
  // The data array starts at index 4
  const unsigned short* data2 = data + 4;
  // Now draw the sprite
  CopySpriteMaskedAlpha(data2, x + xOffset, y + yOffset, width, height, 0x4fe0, alpha);
}

void draw_flipped(const unsigned short* data, int x, int y) {
  // The height and width of the sprite are the first two elements in the data array
  int width = data[0];
  int height = data[1];
  // The offsets of the x and y positions are the third and fourth elements in the data array
  int xOffset = data[2];
  int yOffset = data[3];
  // The data array starts at index 4
  const unsigned short* data2 = data + 4;
  // Now draw the sprite
  CopySpriteMaskedFlipped(data2, x + xOffset, y + yOffset, width, height, 0x4fe0);
}

void draw_loop_x(const unsigned short* data, int x, int y, int xOffset, int drawWidth) {
  // The height and width of the sprite are the first two elements in the data array
  int width = data[0];
  int height = data[1];
  // The offsets of the x and y positions are the third and fourth elements in the data array
  int xOffset2 = data[2];
  int yOffset = data[3];
  // The data array starts at index 4
  const unsigned short* data2 = data + 4;
  // Now draw the sprite
  CopySpriteLoopX(data2, x + xOffset2, y + yOffset, width, height, xOffset, drawWidth, 0x4fe0);
}
