#include <stdio.h>


int keydown(int basic_keycode) {
  if (basic_keycode == 78 || basic_keycode == 27) {
    return 1;
  }
  return 0;
}

void setupKeyboard() {
}
