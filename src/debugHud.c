#include "./debugHud.h"

#include <stdio.h>

#include "./platform.h"
#include "./main.h"
#include "./buttons.h"
#include "./state.h"

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
      fillSky(8, 20);
    }
  }

  int currentTime = getTimeMS();

  char buffer[17];
  if (debugType == 1) {
    char buffer[17];
    snprintf(buffer, 17, "FPS: %d", currentFps);
  } else if (debugType == 2) {
    snprintf(buffer, 17, "Time: %d", (state.totalFrameCount / 60));
  }

  if (debugType) {
    // Draw the text
    drawText(8, 8, buffer);
  }

  // If 1 second has passed
  if (currentTime - lastTime >= 1000) {
    lastTime = currentTime;
    currentFps = fpsCount;
    fpsCount = 0;
  }
  fpsCount++;
}
