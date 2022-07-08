#include "./buttons.h"

#include "./platform.h"
#include "./main.h"

ButtonState buttons = {0};
ButtonState lastButtons = {0};

void scanButtons() {
  updateKeys();
  lastButtons = buttons;
  buttons.up = check_key(BUTTON_UP);
  buttons.down = check_key(BUTTON_DOWN);
  buttons.left = check_key(BUTTON_LEFT);
  buttons.right = check_key(BUTTON_RIGHT);
  buttons.accel = check_key(BUTTON_ACCEL);
  buttons.hop = check_key(BUTTON_HOP_1) || check_key(BUTTON_HOP_2);
  buttons.debug = check_key(BUTTON_DEBUG);
  buttons.save = check_key(BUTTON_SAVE);
  buttons.load = check_key(BUTTON_LOAD);
  buttons.debug_boost = check_key(BUTTON_DEBUG_BOOST);
}
