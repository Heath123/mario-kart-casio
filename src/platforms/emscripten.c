#include <emscripten.h>

#include "./emscripten.h"
#include "gint.h"

color_t VRAM[LCD_HEIGHT_PX * LCD_WIDTH_PX];

EM_JS(void, logInit, (), {
  console.log("platformInit");
});






#include <emscripten/html5.h>
#include <stdio.h>

// Listen to EMSCRIPTEN_EVENT_KEYDOWN and EMSCRIPTEN_EVENT_KEYUP
// and print the key code to the console.

unsigned char keysPressed[256] = {0};

int setKeyState(unsigned char key, unsigned char state) {
  /* switch (key) {
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
  } */
  keysPressed[key] = state;
  return 0;
}

int keyDownEvent(int eventType, const EmscriptenKeyboardEvent *keyEvent, void *userData) {
  // printf("keyDownEvent: %d\n", (int) keyEvent->keyCode);
  setKeyState(keyEvent->keyCode, 1);
  return 0;
}

int keyUpEvent(int eventType, const EmscriptenKeyboardEvent *keyEvent, void *userData) {
  // printf("keyUpEvent: %d\n", (int) keyEvent->keyCode);
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






void platformInit() {
  logInit();
  setupKeyboard();
  emscripten_set_canvas_size(LCD_WIDTH_PX, LCD_HEIGHT_PX);
  EM_ASM_({
    window.canvasContext = Module['canvas'].getContext('2d');
    window.canvasImageData = canvasContext.getImageData(0, 0, 396, 224);
  });
}

void runMainLoop(void (*loop)(), int fps) {
  emscripten_set_main_loop(loop, fps, 1);
}

void updateKeys() {}


void Copy_ToCanvas(uint32_t* ptr) { /*, int w, int h) {*/
  EM_ASM_({
    let data = Module.HEAPU8.slice($0, $0 + 396 * 224 * 4);
    canvasImageData.data.set(data);
    canvasContext.putImageData(canvasImageData, 0, 0);
  }, ptr);
}

void displayUpdate(int minY, int maxY) {
  static unsigned int screencopy[LCD_WIDTH_PX * LCD_HEIGHT_PX];
  for (int i = (minY * LCD_WIDTH_PX); i < (LCD_WIDTH_PX * maxY); i++) {
    int c = VRAM[i];
    // https://gist.github.com/companje/11deb82e807f2cf927b3a0da1646e795#file-rgb565-pde-L8
    unsigned char r = (unsigned char)(((c & 0xF800) >> 11) << 3);
    unsigned char g = (unsigned char)(((c & 0x7E0) >> 5) << 2);
    unsigned char b = (unsigned char)(((c & 0x1F)) << 3);
    unsigned int argb = 0xff000000 | ((int)b << 16) | ((int)g << 8) | (int)r;
    screencopy[i] = argb;
  }
  Copy_ToCanvas(screencopy);
}

void drawText(int x, int y, const char *text) {}

EM_JS(int, getTimeMS, (), {
  return Date.now() - 1657104690407;
});

int check_key(int key) {
  return keysPressed[key];
}
