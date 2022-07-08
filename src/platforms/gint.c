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

void platformInit() {
  // clock_set_speed(CLOCK_SPEED_F5);
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
    while (!newFrameNeeded) sleep();
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

void displayUpdate(int minY, int maxY) {
  minY = alignTo4Down(minY);
  r61524_display(gint_vram, minY, alignTo4Up(maxY - minY), R61524_DMA);
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
