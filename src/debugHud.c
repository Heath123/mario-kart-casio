#ifndef FXCG_MOCK

#include "./debugHud.h"

#include <fxcg/display.h>
#include <fxcg/rtc.h>

#include "./main.h"
#include "./buttons.h"

int lastTime = 0;
int debugType = 0;
int fpsCount = 0;
int currentFps = 0;

void handleDebugHud() {
  if (buttons.debug && !lastButtons.debug) {
    debugType++;
    debugType = debugType % 3;
    if (!debugType) {
      // Put the sky back
      fillSky(24, 34);
      Bdisp_PutDisp_DD_stripe(24, 34);
    }
  }

  int currentTime = RTC_GetTicks();

  if (debugType == 1) {
    int x = 8;
    int y = 0;

    char buffer[17] = "FPS: ";
    itoa(currentFps, (unsigned char*)buffer + 5);

    PrintMiniMini(&x, &y, buffer, 0, COLOR_BLACK, 0);
    Bdisp_PutDisp_DD_stripe(24, 34);
  } else if (debugType == 2) {
    int x = 8;
    int y = 0;

    char buffer[17] = "Time: ";
    itoa((totalFrameCount / 38), (unsigned char*)buffer + 6);

    PrintMiniMini(&x, &y, buffer, 0, COLOR_BLACK, 0);
    Bdisp_PutDisp_DD_stripe(24, 34);
  }

  // If 1 second has passed
  if (currentTime - lastTime >= 128) {
    lastTime = currentTime;
    currentFps = fpsCount;
    fpsCount = 0;
  }
  fpsCount++;
}

#endif // FXCG_MOCK
