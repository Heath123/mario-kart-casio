#include "./debugHud.h"

#include <stdio.h>

#include "./platform.h"
#include "./main.h"
#include "./buttons.h"
#include "./state.h"
#include "platforms/emscripten.h"

int lastTime = 0;
int debugType = 0;
int fpsCount = 0;
int currentFps = 0;

#ifdef PROFILING_ENABLED
#define maxDebugType 5
#else
#define maxDebugType 1
#endif

void handleDebugHud() {
  bool shouldUpdate = false;
  if (buttons.debug && !lastButtons.debug) {
    debugType++;
    debugType = debugType % (maxDebugType + 1);
    fillSky(8, 20);
    shouldUpdate = true;
  }

  int currentTime = getTimeMS();

  // If 1 second has passed
  if (currentTime - lastTime >= 1000) {
    shouldUpdate = true;
  }

  if (shouldUpdate) {
    char buffer[60];
    int x = 8;
    if (debugType == 1) {
      char buffer[17];
      snprintf(buffer, 60, "FPS: %d", currentFps);
      // Move it right to get out of the way of the lap counter
      x = 96;
    } else if (debugType == 2) {
      snprintf(buffer, 60, "Logic% 6d 3D% 6d DispUpd% 6d Sprites% 6d ", timeLogic + timePhysics + timeLogic1 + timeLogic2 + timeLogic3, time3D, timeUpdate, timeSprites + timeKartSprite);
    } else if (debugType == 3) {
      snprintf(buffer, 60, "Sprites% 6d KartSprite% 6d ", timeSprites, timeKartSprite);
    } else if (debugType == 4) {
      snprintf(buffer, 60, "Logic% 6d Physics% 6d L1% 6d L2% 6d L3% 6d ", timeLogic, timePhysics, timeLogic1, timeLogic2, timeLogic3);
    } else if (debugType == 5) {
      snprintf(buffer, 60, "DebugHUD% 6d ", timeDebugHud);
    }

    if (debugType) {
      // Draw the text
      drawText(x, 8, buffer);
      displayUpdate(8, 20);
    }
  }

  if (currentTime - lastTime >= 1000) {
    lastTime = currentTime;
    currentFps = fpsCount;
    fpsCount = 0;
  }
  fpsCount++;
}
