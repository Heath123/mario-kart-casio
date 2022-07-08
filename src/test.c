// Calculate the total time in mm:ss:xx format
int minutes = state.totalFrameCount / 60 / 60;
int seconds = (state.totalFrameCount / 60) % 60;
int milliseconds = ((state.totalFrameCount % 60) * 16667) / 1000;
if (milliseconds >= 1000) {
  milliseconds = 999
}