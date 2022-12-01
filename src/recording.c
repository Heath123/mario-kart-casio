#include <stdlib.h>

#include "./buttons.h"
#include "gint/keycodes.h"

/*
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
  bool save;
  bool load;
  bool debug_boost;
} ButtonState;
*/

typedef enum {
  EVENT_WAIT,
  EVENT_PRESS,
} eventType;

typedef enum {
  REC_KEY_LEFT,
  REC_KEY_RIGHT,
  REC_KEY_UP,
  REC_KEY_DOWN,

  REC_KEY_ACCEL,
  REC_KEY_HOP,
  REC_KEY_DEBUG,
  REC_KEY_SAVE,
  REC_KEY_LOAD,
  // REC_KEY_FRAMECAP_TOGGLE,
} keyType;

typedef struct {
  // Event type
  char type;
  // Event data
  char data;
} inputEvent;

typedef struct {
  // Number of events in the recording
  int numEvents;
  // Array of events
  inputEvent *events;
} inputRecording;

// Current recording
inputRecording recording;

#define MAX_RECORDING_LENGTH 4096

void startRecording() {
  // Create a new recording
  recording.numEvents = 0;
  recording.events = malloc(sizeof(inputEvent) * MAX_RECORDING_LENGTH);
}

void addEvent(char type, char data) {
  // Check if we have space for another event
  if (recording.numEvents >= MAX_RECORDING_LENGTH) {
    // TODO: Error
    return;
  }
  recording.events[recording.numEvents].type = type;
  recording.events[recording.numEvents].data = data;
  recording.numEvents++;
}

void updateButtonState(ButtonState *state) {
  if (state->left) {
    addEvent(EVENT_PRESS, REC_KEY_LEFT);
  }
  if (state->right) {
    addEvent(EVENT_PRESS, REC_KEY_RIGHT);
  }
  if (state->up) {
    addEvent(EVENT_PRESS, REC_KEY_UP);
  }
  if (state->down) {
    addEvent(EVENT_PRESS, REC_KEY_DOWN);
  }
  if (state->accel) {
    addEvent(EVENT_PRESS, REC_KEY_ACCEL);
  }
  if (state->hop) {
    addEvent(EVENT_PRESS, REC_KEY_HOP);
  }
  if (state->debug) {
    addEvent(EVENT_PRESS, REC_KEY_DEBUG);
  }
  if (state->save) {
    addEvent(EVENT_PRESS, REC_KEY_SAVE);
  }
  if (state->load) {
    addEvent(EVENT_PRESS, REC_KEY_LOAD);
  }
  // if (state->framecap_toggle) {
  //   addEvent(EVENT_PRESS, REC_KEY_FRAMECAP_TOGGLE);
  // }

  if (recording.events[recording.numEvents - 1].type == EVENT_WAIT) {
    // If the last event was a wait event, increment the counter by 1
    // TODO: Check for overflow
    recording.events[recording.numEvents - 1].data++;
  } else {
    // Otherwise, add a new wait event
    addEvent(EVENT_WAIT, 1);
  }
}
