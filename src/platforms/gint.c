#include "./gint.h"

#include <gint/keyboard.h>
#include <gint/gint.h>
#include <gint/drivers/r61524.h>
#include <gint/rtc.h>
#include <gint/display.h>
#include <gint/timer.h>
#include <gint/clock.h>
#include <stdbool.h>

#include "../main.h"
#include "gint/display-cg.h"
#include "gint/image.h"

#ifdef PROFILING_ENABLED
#include <libprof.h>
#endif

void platformInit() {
  // clock_set_speed(CLOCK_SPEED_F5);
  #ifdef PROFILING_ENABLED
  prof_init();
  #endif
}

static int callback_tick(volatile int *newFrameNeeded) {
  *newFrameNeeded = 1;
  return TIMER_CONTINUE;
}

void runMainLoop(void (*loop)(), int fps) {
  static volatile int newFrameNeeded = false;
  int t = timer_configure(TIMER_ANY, 1000000 / fps, GINT_CALL(callback_tick, &newFrameNeeded));
  if (t >= 0) timer_start(t);

  while (1) {
    if (frameCapEnabled) {
      while (!newFrameNeeded) sleep();
    }
    newFrameNeeded = 0;
    loop();
  }
}

void updateKeys() {
  clearevents();
  if (keydown(KEY_MENU)) {
    gint_osmenu();
    fillSky(0, LCD_HEIGHT_PX);
  }
}

// Align to a multiple of 4, rounding down.
#define alignTo4Down(n) ((n) & ~3)
// Align to a multiple of 4, rounding up.
#define alignTo4Up(n) (((n) + 3) & ~3)

void displayUpdateBox(int x, int y, int w, int h) {
  r61524_display_rect(gint_vram, x, x + w - 1, y, y + h - 1);
}

void displayUpdate(int minY, int maxY) {
  minY = alignTo4Down(minY);
  #ifdef PROFILING_ENABLED
  #define method R61524_DMA_WAIT
  #else
  #define method R61524_DMA
  #endif
  r61524_display(gint_vram, minY, alignTo4Up(maxY - minY), method);
}

void drawText(int x, int y, const char *text) {
  dtext_opt(x, y, C_BLACK, C_WHITE, DTEXT_LEFT, DTEXT_TOP, text, -1);
  displayUpdate(y, y + 12);
}

int getTimeMS(void) {
  return rtc_ticks() * 1000 / 128;
}

int check_key(int key) {
  if (key == -1) return 0;
  return keydown(key);
}

struct image {
  int xOffset;
  int yOffset;
  const bopti_image_t* data;
};

void draw(const struct image *img, int x, int y) {
  dimage(x + img->xOffset, y + img->yOffset, img->data);
}

void draw_flipped(const struct image *img, int x, int y) {
  // dimage(x + img->xOffset, y + img->yOffset, img->data);
  dimage_p8_effect(x + img->xOffset, y + img->yOffset, img->data, IMAGE_HFLIP);
}
// void draw_loop_x(const struct image* data, int x, int y, int xOffset, int drawWidth);

void draw_partial(const struct image *img, int x, int y, int sx, int sy, int w, int h) {
  dsubimage(x + img->xOffset + sx, y + img->yOffset + sy, img->data, sx, sy, w, h, 0);
}

void draw_partial_flipped(const struct image *img, int x, int y, int sx, int sy, int w, int h) {
  dsubimage_p8_effect(x + img->xOffset + sx, y + img->yOffset + sy, img->data, sx, sy, w, h, IMAGE_HFLIP);
}

int get_width(const struct image* img) {
  return img->data->width;
}

int get_height(const struct image* img) {
  return img->data->height;
}
