#ifndef _BUTTONS_H
#define _BUTTONS_H

#include <stdbool.h>

typedef struct {
  // D-pad
  bool left;
  bool right;
  bool up;
  bool down;

  // Buttons
  bool accel;
  bool hop;
  bool debug;
} buttonState;

extern buttonState buttons;
extern buttonState lastButtons;

void scanButtons();

#endif // _BUTTONS_H
