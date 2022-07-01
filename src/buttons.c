#include "./buttons.h"

#include <fxcg/keyboard.h>

buttonState buttons = {0};
buttonState lastButtons = {0};

// https://www.cemetech.net/forum/viewtopic.php?p=173836&sid=9eabb0dbeddeeb6507c19c8a65dbe249
#ifndef FXCG_MOCK
int keydown(int basic_keycode) {
  const unsigned short* keyboard_register = (unsigned short*)0xA44B0000;
  int row, col, word, bit;
  row = basic_keycode % 10;
  col = basic_keycode / 10 - 1;
  word = row >> 1;
  bit = col + 8 * (row & 1);
  return (0 != (keyboard_register[word] & 1 << bit));
}
#endif

void scanButtons() {
  lastButtons = buttons;
  buttons.up = keydown(KEY_PRGM_UP);
  buttons.down = keydown(KEY_PRGM_DOWN);
  buttons.left = keydown(KEY_PRGM_LEFT);
  buttons.right = keydown(KEY_PRGM_RIGHT);
  buttons.accel = keydown(KEY_PRGM_SHIFT);
  buttons.hop = keydown(KEY_PRGM_ALPHA);
  buttons.debug = keydown(KEY_PRGM_RETURN);
}
