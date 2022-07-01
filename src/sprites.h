#ifndef _SPRITES_H
#define _SPRITES_H

#include <stdbool.h>

void CopySpriteMasked(const void* datar, int x, int y, int width, int height, int maskcolor);
void CopySpriteMaskedFlipped(const void* datar, int x, int y, int width, int height, int maskcolor);
void draw(const unsigned short* data, int x, int y);
void draw_alpha(const unsigned short* data, int x, int y, int alpha);
void draw_flipped(const unsigned short* data, int x, int y);
void draw_loop_x(const unsigned short* data, int x, int y, int xOffset, int drawWidth);

#endif // _SPRITES_H
