#include <emscripten.h>
#include <stdio.h>

unsigned short screen[384 * 216];

#define false 0
#define true 0

#define byte unsigned char

void Copy_ToCanvas(uint32_t* ptr, int w, int h) {
  EM_ASM_({
      let data = Module.HEAPU8.slice($0, $0 + $1 * $2 * 4);
      let context = Module['canvas'].getContext('2d');
      let imageData = context.getImageData(0, 0, $1, $2);
      imageData.data.set(data);
      context.putImageData(imageData, 0, 0);
    }, ptr, w, h);
}

/* static void main_loop()
{
  // memset(screen, 0, 320*320*4); // Clear screen
    int screen[320*320],idx=0;
    for (int x=0; x<320*320; x++)
        screen[idx++] = 0xff000000;
  for (int x=0; x<320; x++)
    for (int y=0; y<320; y++)
      screen[320*(x|y) + (x&y)]= 0xffffffff; // set pixel(x or y, x and y) to white... (will draw a serpinsky triangle)
  Copy_ToCanvas(screen, 320, 320);
} */

void* GetVRAMAddress(void) {
  emscripten_set_canvas_size(384, 216);
  return &screen;
}

void PrintXY(int x, int y, const char *string, int mode, int color) {
  printf("%s\n", string + 2);
}

void Bdisp_EnableColor(int n) {}

void Bdisp_PutDisp_DD(void) {
  unsigned int screencopy[384 * 216];
  for (int i = 0; i < (384 * 216); i++) {
    int c = screen[i];
    // https://gist.github.com/companje/11deb82e807f2cf927b3a0da1646e795#file-rgb565-pde-L8
    byte r = (byte)(((c & 0xF800) >> 11) << 3);
    byte g = (byte)(((c & 0x7E0) >> 5) << 2);
    byte b = (byte)(((c & 0x1F)) << 3);
    unsigned int argb = 0xff000000 | ((int)b << 16) | ((int)g << 8) | (int)r;
    screencopy[i] = argb;
  }
  Copy_ToCanvas(screencopy, 384, 216);
}

void Bdisp_PutDisp_DD_stripe(int y1, int y2) {
  Bdisp_PutDisp_DD();
}

void Bdisp_AllClr_VRAM(void) {
  for (int i = 0; i < (384 * 216); i++) {
    screen[i] = 0xffffffff;
  }
}
