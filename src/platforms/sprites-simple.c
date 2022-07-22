struct image {
  const unsigned short *data;
};

void draw(const struct image* img, int x, int y) {
  const unsigned short* data = img->data;
  // The height and width of the sprite are the first two elements in the data array
  int width = data[0];
  int height = data[1];
  // The offsets of the x and y positions are the third and fourth elements in the data array
  x += data[2];
  y += data[3];
  // Now draw the sprite
  // The data array starts at index 4
  color_t* datac = (color_t*) (data + 4);
  color_t* VRAM2 = (color_t*) VRAM;
  VRAM2 += LCD_WIDTH_PX * y + x;
  for (int j = y; j < y + height; j++) {
    for (int i = x; i < x + width; i++) {
      if (*(datac) != 0x4fe0) {
        *(VRAM2++) = *(datac++);
      } else {
        VRAM2++;
        datac++;
      }
    }
    VRAM2 += LCD_WIDTH_PX - width;
  }
}

void draw_partial(const struct image *img, int x, int y, int sx, int sy, int w, int h) {
  const unsigned short* data = img->data;
  // The height and width of the sprite are the first two elements in the data array
  int width = data[0];
  int height = data[1];
  if (w > width) {
    w = width;
  }
  if (h > height) {
    h = height;
  }
  // The offsets of the x and y positions are the third and fourth elements in the data array
  x += data[2];
  y += data[3];
  // Now draw the sprite
  // The data array starts at index 4
  color_t* datac = (color_t*) (data + 4) + sx + (sy * w);
  color_t* VRAM2 = (color_t*) VRAM;
  VRAM2 += (LCD_WIDTH_PX * (y + sy)) + x + sx;
  for (int j = y + sy; j < y + h; j++) {
    for (int i = x + sx; i < x + w; i++) {
      if (*(datac) != 0x4fe0) {
        *(VRAM2++) = *(datac++);
      } else {
        VRAM2++;
        datac++;
      }
    }
    VRAM2 += LCD_WIDTH_PX - w + sx;
    datac += width - w + sx;
  }
}

void draw_flipped(const struct image* img, int x, int y) {
  const unsigned short* data = img->data;
  // The height and width of the sprite are the first two elements in the data array
  int width = data[0];
  int height = data[1];
  // The offsets of the x and y positions are the third and fourth elements in the data array
  x += data[2];
  y += data[3];
  // Now draw the sprite
  // The data array starts at index 4
  color_t* datac = (color_t*) (data + 4);
  color_t* VRAM2 = (color_t*) VRAM;
  VRAM2 += LCD_WIDTH_PX * y + x;
  for (int j = y; j < y + height; j++) {
    // Start at the end of the line and work backwards
    datac += width - 1;
    for (int i = x; i < x + width; i++) {
      if (*(datac) != 0x4fe0) {
        *(VRAM2++) = *(datac--);
      } else {
        VRAM2++;
        datac--;
      }
    }
    datac += width + 1;
    VRAM2 += LCD_WIDTH_PX - width;
  }
}

void draw_partial_flipped(const struct image *img, int x, int y, int sx, int sy, int w, int h) {
  const unsigned short* data = img->data;
  // The height and width of the sprite are the first two elements in the data array
  int width = data[0];
  int height = data[1];
  if (w > width) {
    w = width;
  }
  if (h > height) {
    h = height;
  }
  // The offsets of the x and y positions are the third and fourth elements in the data array
  x += data[2];
  y += data[3];
  // Now draw the sprite
  // The data array starts at index 4
  color_t* datac = (color_t*) (data + 4) + sx + sy * w;
  color_t* VRAM2 = (color_t*) VRAM;
  VRAM2 += LCD_WIDTH_PX * (y + sy) + x + sx;
  for (int j = y + sy; j < y + h; j++) {
    // Start at the end of the line and work backwards
    datac += width - 1;
    for (int i = x + sx; i < x + w; i++) {
      if (*(datac) != 0x4fe0) {
        *(VRAM2++) = *(datac--);
      } else {
        VRAM2++;
        datac--;
      }
    }
    datac += width + 1;
    VRAM2 += LCD_WIDTH_PX - w + sx;
    datac += width - w;
  }
}

// // Copy a sprite that loops around with an X offset
// void CopySpriteLoopX(const void* datar, int x, int y, int width, int height, int xOffset, int drawWidth, int maskcolor) {
//   color_t* data = (color_t*)datar;
//   // color_t* VRAM2 = (color_t*)VRAM;
//   // Loop over all the y positions
//   for (int j = 0; j < height; j++) {
//     // Loop over all the x positions
//     for (int i = 0; i < drawWidth; i++) {
//       // Get the pixel at the current position
//       color_t pixel = data[(j * width) + ((i + xOffset) % width)];
//       // Draw the pixel
//       if (pixel != maskcolor) {
//         VRAM[(j + y) * LCD_WIDTH_PX + (i + x)] = pixel;
//       }
//     }
//   }
// }

// void draw_loop_x(const struct image* img, int x, int y, int xOffset, int drawWidth) {
//   const unsigned short* data = img->data;
//   // The height and width of the sprite are the first two elements in the data array
//   int width = data[0];
//   int height = data[1];
//   // The offsets of the x and y positions are the third and fourth elements in the data array
//   int xOffset2 = data[2];
//   int yOffset = data[3];
//   // The data array starts at index 4
//   const unsigned short* data2 = data + 4;
//   // Now draw the sprite
//   CopySpriteLoopX(data2, x + xOffset2, y + yOffset, width, height, xOffset, drawWidth, 0x4fe0);
// }

int get_width(const struct image* img) {
  const unsigned short* data = img->data;
  return data[0];
}

int get_height(const struct image* img) {
  const unsigned short* data = img->data;
  return data[1];
}
