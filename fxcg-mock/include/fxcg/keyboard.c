#include <emscripten.h>
#include <emscripten/html5.h>
#include <stdio.h>

// Listen to EMSCRIPTEN_EVENT_KEYDOWN and EMSCRIPTEN_EVENT_KEYUP
// and print the key code to the console.

unsigned char keysPressed[256] = {0};

int setKeyState(unsigned char key, unsigned char state) {
  switch (key) {
    case 37: // left arrow
      keysPressed[38] = state;
      break;
    case 39: // right arrow
      keysPressed[27] = state;
      break;
    case 88: // x
      keysPressed[78] = state;
      break;
    case 90: // z
      keysPressed[77] = state;
      break;
    case 68: // d
      keysPressed[31] = state;
      break;
  }
  return 0;
}

int keyDownEvent(int eventType, const EmscriptenKeyboardEvent *keyEvent, void *userData) {
  printf("keyDownEvent: %d\n", keyEvent->keyCode);
  setKeyState(keyEvent->keyCode, 1);
  return 0;
}

int keyUpEvent(int eventType, const EmscriptenKeyboardEvent *keyEvent, void *userData) {
  printf("keyUpEvent: %d\n", keyEvent->keyCode);
  setKeyState(keyEvent->keyCode, 0);
  return 0;
}

int keydown(int basic_keycode) {
  return keysPressed[basic_keycode];
}

void setupKeyboard() {
  emscripten_set_keydown_callback("html", 0, 0, keyDownEvent);
  emscripten_set_keyup_callback("html", 0, 0, keyUpEvent);
}
