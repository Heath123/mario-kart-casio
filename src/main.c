#include <fxcg/display.h>
#include <fxcg/keyboard.h>
#ifndef FXCG_MOCK
#include <fxcg/misc.h>
#include <fxcg/rtc.h>
#include <fxcg/system.h>
#else
#include <fxcg/mock.h>
#ifdef EMSCRIPTEN
#include <emscripten.h>
#endif
#endif

#include "./3d.h"
#include "./sprites.h"
#include "../data-headers/images.h"

#define bool unsigned char
#define true 1
#define false 0

#define MIN(X, Y) (((X) < (Y)) ? (X) : (Y))
#define MAX(X, Y) (((X) < (Y)) ? (Y) : (X))

#define LCD_WIDTH_PX 384
#define LCD_HEIGHT_PX 216

// TODO : no duplication with the LUT
#define angleWidth 192
#define horizon 108

#define scale 4

short angle = 0;
short xOffset = 0;
short yOffset = 0;

// https://stackoverflow.com/a/19288271/4012708
int mod(int a, int b) {
  int r = a % b;
  return r < 0 ? r + b : r;
}

// Modulo for floats
float fmod(float a, float b) {
  float r = a - (int)(a / b) * b;
  return r < 0 ? r + b : r;
}

#include "../data-headers/kartsprites.h"

// https://stackoverflow.com/a/3689059/4012708
// TODO: use the symmetry of the sine graph to make this smaller
const float table[1000] = {0.00314159, 0.00628314, 0.00942464, 0.012566, 0.0157073, 0.0188484, 0.0219894, 0.0251301, 0.0282706, 0.0314108, 0.0345506, 0.0376902, 0.0408294, 0.0439681, 0.0471065, 0.0502443, 0.0533817, 0.0565185, 0.0596548, 0.0627905, 0.0659256, 0.06906, 0.0721938, 0.0753268, 0.0784591, 0.0815906, 0.0847213, 0.0878512, 0.0909802, 0.0941083, 0.0972355, 0.100362, 0.103487, 0.106611, 0.109734, 0.112856, 0.115977, 0.119097, 0.122216, 0.125333, 0.128449, 0.131564, 0.134678, 0.13779, 0.140901, 0.144011, 0.147119, 0.150226, 0.153331, 0.156434, 0.159537, 0.162637, 0.165736, 0.168833, 0.171929, 0.175023, 0.178115, 0.181206, 0.184294, 0.187381, 0.190466, 0.193549, 0.196631, 0.19971, 0.202787, 0.205863, 0.208936, 0.212007, 0.215076, 0.218143, 0.221208, 0.224271, 0.227331, 0.230389, 0.233445, 0.236499, 0.23955, 0.242599, 0.245646, 0.24869, 0.251732, 0.254771, 0.257807, 0.260842, 0.263873, 0.266902, 0.269928, 0.272952, 0.275973, 0.278991, 0.282007, 0.285019, 0.288029, 0.291036, 0.29404, 0.297042, 0.30004, 0.303035, 0.306028, 0.309017, 0.312003, 0.314987, 0.317967, 0.320944, 0.323917, 0.326888, 0.329855, 0.33282, 0.33578, 0.338738, 0.341692, 0.344643, 0.34759, 0.350534, 0.353475, 0.356412, 0.359345, 0.362275, 0.365202, 0.368125, 0.371044, 0.373959, 0.376871, 0.379779, 0.382683, 0.385584, 0.388481, 0.391374, 0.394263, 0.397148, 0.400029, 0.402906, 0.40578, 0.408649, 0.411514, 0.414376, 0.417233, 0.420086, 0.422935, 0.425779, 0.42862, 0.431456, 0.434288, 0.437116, 0.439939, 0.442758, 0.445573, 0.448383, 0.451189, 0.45399, 0.456787, 0.45958, 0.462368, 0.465151, 0.46793, 0.470704, 0.473473, 0.476238, 0.478998, 0.481754, 0.484504, 0.48725, 0.489991, 0.492727, 0.495459, 0.498185, 0.500907, 0.503623, 0.506335, 0.509041, 0.511743, 0.51444, 0.517131, 0.519817, 0.522499, 0.525175, 0.527846, 0.530511, 0.533172, 0.535827, 0.538477, 0.541121, 0.54376, 0.546394, 0.549023, 0.551646, 0.554263, 0.556876, 0.559482, 0.562083, 0.564679, 0.567269, 0.569853, 0.572432, 0.575005, 0.577573, 0.580134, 0.58269, 0.585241, 0.587785, 0.590324, 0.592857, 0.595384, 0.597905, 0.60042, 0.60293, 0.605433, 0.60793, 0.610422, 0.612907, 0.615386, 0.61786, 0.620327, 0.622788, 0.625243, 0.627691, 0.630134, 0.63257, 0.635, 0.637424, 0.639841, 0.642253, 0.644657, 0.647056, 0.649448, 0.651834, 0.654213, 0.656586, 0.658952, 0.661312, 0.663665, 0.666012, 0.668352, 0.670686, 0.673012, 0.675333, 0.677646, 0.679953, 0.682254, 0.684547, 0.686834, 0.689114, 0.691387, 0.693653, 0.695913, 0.698165, 0.700411, 0.70265, 0.704882, 0.707107, 0.709325, 0.711536, 0.71374, 0.715936, 0.718126, 0.720309, 0.722485, 0.724653, 0.726814, 0.728969, 0.731116, 0.733255, 0.735388, 0.737513, 0.739631, 0.741742, 0.743845, 0.745941, 0.74803, 0.750111, 0.752185, 0.754251, 0.75631, 0.758362, 0.760406, 0.762443, 0.764472, 0.766493, 0.768507, 0.770513, 0.772512, 0.774503, 0.776487, 0.778462, 0.78043, 0.782391, 0.784343, 0.786288, 0.788226, 0.790155, 0.792077, 0.79399, 0.795896, 0.797794, 0.799685, 0.801567, 0.803441, 0.805308, 0.807166, 0.809017, 0.81086, 0.812694, 0.814521, 0.816339, 0.81815, 0.819952, 0.821746, 0.823533, 0.825311, 0.827081, 0.828842, 0.830596, 0.832341, 0.834078, 0.835807, 0.837528, 0.83924, 0.840945, 0.84264, 0.844328, 0.846007, 0.847678, 0.84934, 0.850994, 0.85264, 0.854277, 0.855906, 0.857527, 0.859139, 0.860742, 0.862337, 0.863923, 0.865501, 0.867071, 0.868632, 0.870184, 0.871727, 0.873262, 0.874789, 0.876307, 0.877816, 0.879316, 0.880808, 0.882291, 0.883766, 0.885231, 0.886688, 0.888136, 0.889576, 0.891007, 0.892428, 0.893841, 0.895246, 0.896641, 0.898028, 0.899405, 0.900774, 0.902134, 0.903485, 0.904827, 0.90616, 0.907484, 0.9088, 0.910106, 0.911403, 0.912692, 0.913971, 0.915241, 0.916502, 0.917755, 0.918998, 0.920232, 0.921457, 0.922673, 0.92388, 0.925077, 0.926266, 0.927445, 0.928615, 0.929776, 0.930928, 0.932071, 0.933205, 0.934329, 0.935444, 0.93655, 0.937647, 0.938734, 0.939812, 0.940881, 0.94194, 0.942991, 0.944031, 0.945063, 0.946085, 0.947098, 0.948102, 0.949096, 0.950081, 0.951057, 0.952023, 0.952979, 0.953927, 0.954865, 0.955793, 0.956712, 0.957622, 0.958522, 0.959412, 0.960294, 0.961165, 0.962028, 0.96288, 0.963724, 0.964557, 0.965382, 0.966196, 0.967001, 0.967797, 0.968583, 0.96936, 0.970127, 0.970884, 0.971632, 0.97237, 0.973099, 0.973817, 0.974527, 0.975227, 0.975917, 0.976597, 0.977268, 0.977929, 0.978581, 0.979223, 0.979855, 0.980478, 0.981091, 0.981694, 0.982287, 0.982871, 0.983445, 0.98401, 0.984564, 0.985109, 0.985645, 0.98617, 0.986686, 0.987192, 0.987688, 0.988175, 0.988652, 0.989119, 0.989576, 0.990024, 0.990461, 0.990889, 0.991308, 0.991716, 0.992115, 0.992504, 0.992883, 0.993252, 0.993611, 0.993961, 0.994301, 0.994631, 0.994951, 0.995261, 0.995562, 0.995853, 0.996134, 0.996405, 0.996666, 0.996917, 0.997159, 0.997391, 0.997613, 0.997825, 0.998027, 0.998219, 0.998402, 0.998574, 0.998737, 0.99889, 0.999033, 0.999166, 0.999289, 0.999403, 0.999507, 0.9996, 0.999684, 0.999758, 0.999822, 0.999877, 0.999921, 0.999956, 0.99998, 0.999995, 1, 0.999995, 0.99998, 0.999956, 0.999921, 0.999877, 0.999822, 0.999758, 0.999684, 0.9996, 0.999507, 0.999403, 0.999289, 0.999166, 0.999033, 0.99889, 0.998737, 0.998574, 0.998402, 0.998219, 0.998027, 0.997825, 0.997613, 0.997391, 0.997159, 0.996917, 0.996666, 0.996405, 0.996134, 0.995853, 0.995562, 0.995261, 0.994951, 0.994631, 0.994301, 0.993961, 0.993611, 0.993252, 0.992883, 0.992504, 0.992115, 0.991716, 0.991308, 0.990889, 0.990461, 0.990024, 0.989576, 0.989119, 0.988652, 0.988175, 0.987688, 0.987192, 0.986686, 0.98617, 0.985645, 0.985109, 0.984564, 0.98401, 0.983445, 0.982871, 0.982287, 0.981694, 0.981091, 0.980478, 0.979855, 0.979223, 0.978581, 0.977929, 0.977268, 0.976597, 0.975917, 0.975227, 0.974527, 0.973817, 0.973099, 0.97237, 0.971632, 0.970884, 0.970127, 0.96936, 0.968583, 0.967797, 0.967001, 0.966196, 0.965382, 0.964557, 0.963724, 0.96288, 0.962028, 0.961165, 0.960294, 0.959412, 0.958522, 0.957622, 0.956712, 0.955793, 0.954865, 0.953927, 0.952979, 0.952023, 0.951057, 0.950081, 0.949096, 0.948102, 0.947098, 0.946085, 0.945063, 0.944031, 0.942991, 0.94194, 0.940881, 0.939812, 0.938734, 0.937647, 0.93655, 0.935444, 0.934329, 0.933205, 0.932071, 0.930928, 0.929776, 0.928615, 0.927445, 0.926266, 0.925077, 0.92388, 0.922673, 0.921457, 0.920232, 0.918998, 0.917755, 0.916502, 0.915241, 0.913971, 0.912692, 0.911403, 0.910106, 0.9088, 0.907484, 0.90616, 0.904827, 0.903485, 0.902134, 0.900774, 0.899405, 0.898028, 0.896641, 0.895246, 0.893841, 0.892428, 0.891007, 0.889576, 0.888136, 0.886688, 0.885231, 0.883766, 0.882291, 0.880808, 0.879316, 0.877816, 0.876307, 0.874789, 0.873262, 0.871727, 0.870184, 0.868632, 0.867071, 0.865501, 0.863923, 0.862337, 0.860742, 0.859139, 0.857527, 0.855906, 0.854277, 0.85264, 0.850994, 0.84934, 0.847678, 0.846007, 0.844328, 0.84264, 0.840945, 0.83924, 0.837528, 0.835807, 0.834078, 0.832341, 0.830596, 0.828842, 0.827081, 0.825311, 0.823533, 0.821746, 0.819952, 0.81815, 0.816339, 0.814521, 0.812694, 0.81086, 0.809017, 0.807166, 0.805308, 0.803441, 0.801567, 0.799685, 0.797794, 0.795896, 0.79399, 0.792077, 0.790155, 0.788226, 0.786288, 0.784343, 0.782391, 0.78043, 0.778462, 0.776487, 0.774503, 0.772512, 0.770513, 0.768507, 0.766493, 0.764472, 0.762443, 0.760406, 0.758362, 0.75631, 0.754251, 0.752185, 0.750111, 0.74803, 0.745941, 0.743845, 0.741742, 0.739631, 0.737513, 0.735388, 0.733255, 0.731116, 0.728969, 0.726814, 0.724653, 0.722485, 0.720309, 0.718126, 0.715936, 0.71374, 0.711536, 0.709325, 0.707107, 0.704882, 0.70265, 0.700411, 0.698165, 0.695913, 0.693653, 0.691387, 0.689114, 0.686834, 0.684547, 0.682254, 0.679953, 0.677646, 0.675333, 0.673012, 0.670686, 0.668352, 0.666012, 0.663665, 0.661312, 0.658952, 0.656586, 0.654213, 0.651834, 0.649448, 0.647056, 0.644657, 0.642253, 0.639841, 0.637424, 0.635, 0.63257, 0.630134, 0.627691, 0.625243, 0.622788, 0.620327, 0.61786, 0.615386, 0.612907, 0.610422, 0.60793, 0.605433, 0.60293, 0.60042, 0.597905, 0.595384, 0.592857, 0.590324, 0.587785, 0.585241, 0.58269, 0.580134, 0.577573, 0.575005, 0.572432, 0.569853, 0.567269, 0.564679, 0.562083, 0.559482, 0.556876, 0.554263, 0.551646, 0.549023, 0.546394, 0.54376, 0.541121, 0.538477, 0.535827, 0.533172, 0.530511, 0.527846, 0.525175, 0.522499, 0.519817, 0.517131, 0.51444, 0.511743, 0.509041, 0.506335, 0.503623, 0.500907, 0.498185, 0.495459, 0.492727, 0.489991, 0.48725, 0.484504, 0.481754, 0.478998, 0.476238, 0.473473, 0.470704, 0.46793, 0.465151, 0.462368, 0.45958, 0.456787, 0.45399, 0.451189, 0.448383, 0.445573, 0.442758, 0.439939, 0.437116, 0.434288, 0.431456, 0.42862, 0.425779, 0.422935, 0.420086, 0.417233, 0.414376, 0.411514, 0.408649, 0.40578, 0.402906, 0.400029, 0.397148, 0.394263, 0.391374, 0.388481, 0.385584, 0.382683, 0.379779, 0.376871, 0.373959, 0.371044, 0.368125, 0.365202, 0.362275, 0.359345, 0.356412, 0.353475, 0.350534, 0.34759, 0.344643, 0.341692, 0.338738, 0.33578, 0.33282, 0.329855, 0.326888, 0.323917, 0.320944, 0.317967, 0.314987, 0.312003, 0.309017, 0.306028, 0.303035, 0.30004, 0.297042, 0.29404, 0.291036, 0.288029, 0.285019, 0.282007, 0.278991, 0.275973, 0.272952, 0.269928, 0.266902, 0.263873, 0.260842, 0.257807, 0.254771, 0.251732, 0.24869, 0.245646, 0.242599, 0.23955, 0.236499, 0.233445, 0.230389, 0.227331, 0.224271, 0.221208, 0.218143, 0.215076, 0.212007, 0.208936, 0.205863, 0.202787, 0.19971, 0.196631, 0.193549, 0.190466, 0.187381, 0.184294, 0.181206, 0.178115, 0.175023, 0.171929, 0.168833, 0.165736, 0.162637, 0.159537, 0.156434, 0.153331, 0.150226, 0.147119, 0.144011, 0.140901, 0.13779, 0.134678, 0.131564, 0.128449, 0.125333, 0.122216, 0.119097, 0.115977, 0.112856, 0.109734, 0.106611, 0.103487, 0.100362, 0.0972355, 0.0941083, 0.0909802, 0.0878512, 0.0847213, 0.0815906, 0.0784591, 0.0753268, 0.0721938, 0.06906, 0.0659256, 0.0627905, 0.0596548, 0.0565185, 0.0533817, 0.0502443, 0.0471065, 0.0439681, 0.0408294, 0.0376902, 0.0345506, 0.0314108, 0.0282706, 0.0251301, 0.0219894, 0.0188484, 0.0157073, 0.012566, 0.00942464, 0.00628314, 0.00314159, 1.22465e-16};

float sin(int angle) {
  if (angle == 0) return 0.0;
  int newAngle = mod(angle, 180);
  int sign = 1;
  if (mod(angle, 360) > 180) {
    sign *= -1;
  }
  return sign * table[(int)(newAngle / 0.18) - 1];
}

float cos(int angle) {
  return sin(angle + 90);
}

short index2;
unsigned short element;

color_t* VRAM;

void setPixel(int x, int y, color_t color) {
  VRAM[y * LCD_WIDTH_PX + x] = color;
}

// https://prizm.cemetech.net/index.php?title=PRGM_GetKey
int PRGM_GetKey(void) {
  unsigned char buffer[12];
  PRGM_GetKey_OS(buffer);
  return (buffer[1] & 0x0F) * 10 + ((buffer[2] & 0xF0) >> 4);
}

#define PI 3.14159265358979323846

// https://www.cemetech.net/forum/viewtopic.php?p=173836&sid=9eabb0dbeddeeb6507c19c8a65dbe249
#ifndef FXCG_MOCK
int keydown(int basic_keycode) {
  const unsigned short* keyboard_register = (unsigned short*)0xA44B0000;
  int row, col, word, bit;
  row = basic_keycode % 10;
  col = basic_keycode / 10 - 1;
  word = row >> 1;
  bit = col + 8 * (row & 1);
  return (0 != (keyboard_register[word] & 1 << bit));
}
#endif

void cameraBehind(short x, short y, short objectAngle, short distance) {
  // objectAngle = 90 - objectAngle;
  yOffset = y - sin(-objectAngle) * distance;
  xOffset = x - cos(-objectAngle) * distance;
}

void fillSky(unsigned short yMin, unsigned short yMax) {
  /* for (unsigned short x = 0; x < LCD_WIDTH_PX; x++) {
    for (unsigned short y = yMin; y < yMax; y++) {
      setPixel(x, y, 0x867D);
    }
  } */
  draw(img_bg, 0, 0);
  Bdisp_PutDisp_DD();
}

// https://prizm.cemetech.net/index.php?title=Useful_Routines
void drawLine(int x1, int y1, int x2, int y2, unsigned short color) {
  signed char ix;
  signed char iy;

  // if x1 == x2 or y1 == y2, then it does not matter what we set here
  int delta_x = (x2 > x1 ? (ix = 1, x2 - x1) : (ix = -1, x1 - x2)) << 1;
  int delta_y = (y2 > y1 ? (iy = 1, y2 - y1) : (iy = -1, y1 - y2)) << 1;

  setPixel(x1, y1, color);
  if (delta_x >= delta_y) {
    int error = delta_y - (delta_x >> 1);  // error may go below zero
    while (x1 != x2) {
      if (error >= 0) {
        if (error || (ix > 0)) {
          y1 += iy;
          error -= delta_x;
        }  // else do nothing
      }    // else do nothing
      x1 += ix;
      error += delta_y;
      setPixel(x1, y1, color);
    }
  } else {
    int error = delta_x - (delta_y >> 1);  // error may go below zero
    while (y1 != y2) {
      if (error >= 0) {
        if (error || (iy > 0)) {
          x1 += ix;
          error -= delta_y;
        }  // else do nothing
      }    // else do nothing
      y1 += iy;
      error += delta_x;
      setPixel(x1, y1, color);
    }
  }
}

unsigned short kartX = 3730;
unsigned short kartY = 2300;
signed char kartSteerAnim = 0;
float kartVel = 0;
float kartAngle = 90;
#define kartSpeed 2

int debugType = 0;
bool exeWasPressed = false;

// For framerate counter
int lastTime;
int frameCount = 0;
int totalFrameCount = 0;

void main_loop() {
  // Main game loop
  #ifndef FXCG_MOCK
  int currentTime = RTC_GetTicks();
  totalFrameCount += 1;
  // If 1 second has passed, print framerate
  if (currentTime - lastTime >= 128) {
    lastTime = currentTime;

    if (debugType == 1) {
      int x = 8;
      int y = 0;

      char buffer[17] = "FPS: ";
      itoa(frameCount, (unsigned char*)buffer + 5);

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
    frameCount = 0;
  }
  #endif

  // Grass or sand = more friction
  unsigned char currentTile = getTileType(kartX / scale, kartY / scale);
  if (currentTile == 0 || currentTile == 7 || currentTile == 9 || currentTile == 12 || currentTile == 14 || currentTile == 15 || currentTile == 50 || currentTile == 52) {
    kartVel *= 0.8;
  } else {
    kartVel *= 0.9;
  }
  if (kartVel < 1.42) {
    kartVel = 0;
  }
  float oldKartX = kartX;
  float oldKartY = kartY;
  kartY += kartVel * sin(-kartAngle);
  kartX += kartVel * cos(-kartAngle);
  unsigned char newTile = getTileType(kartX / scale, kartY / scale);
  if (newTile >= 240 && newTile <= 243) {  // Barrier
    kartX = oldKartX;
    kartY = oldKartY;
  }
  cameraBehind(kartX, kartY, kartAngle, 150);  // TODO: calculate this rather than guessing

  // kartVel += kartSpeed;

  // int key = PRGM_GetKey();
  bool leftPressed = keydown(KEY_PRGM_LEFT);
  bool rightPressed = keydown(KEY_PRGM_RIGHT);
  bool shiftPressed = keydown(KEY_PRGM_SHIFT);

  if (shiftPressed) {
    kartVel += kartSpeed;
  }

  if (leftPressed && !rightPressed && kartVel > 3) {
    kartAngle -= kartVel / 10;

    kartSteerAnim++;
    if (kartSteerAnim > 10) {
      kartSteerAnim = 10;
    }
  } else if (rightPressed && !leftPressed && kartVel > 3) {
    kartAngle += kartVel / 10;

    kartSteerAnim--;
    if (kartSteerAnim < -10) {
      kartSteerAnim = -10;
    }
  } else {
    if (kartSteerAnim > 0) {
      kartSteerAnim--;
      if (kartSteerAnim < 0) {
        kartSteerAnim = 0;
      }
    } else {
      kartSteerAnim++;
      if (kartSteerAnim > 0) {
        kartSteerAnim = 0;
      }
    }
  }

  // Control the distance
  /* if (keydown(KEY_PRGM_UP)) {
    distance += 2;
  }
  if (keydown(KEY_PRGM_DOWN)) {
    distance -= 2;
  } */

  bool exePressed = keydown(31);
  if (exePressed && !exeWasPressed) {
    debugType++;
    debugType = debugType % 3;
    if (!debugType) {
      // Put the sky back
      fillSky(24, 34);
      Bdisp_PutDisp_DD_stripe(24, 34);
    }
  }
  exeWasPressed = exePressed;

  #ifndef FXCG_MOCK
  if (keydown(KEY_PRGM_MENU)) {
    // Allow the OS to handle exiting to the menu
    int key;
    GetKey(&key);
    Bdisp_EnableColor(1);
    fillSky(0, LCD_HEIGHT_PX);
  }
  #endif

  if (keydown(KEY_PRGM_ACON)) {
    #ifndef FXCG_MOCK
    PowerOff(1);
    #endif
    fillSky(0, LCD_HEIGHT_PX);
  }

  kartAngle = fmod(kartAngle, 360);

  angle = fmod(kartAngle + 45, 360) * angleWidth / 90;

  // for (unsigned short x = 0; x < LCD_WIDTH_PX / 8; x += 2) {
  //   index2 = x + angle;
  //   index2 = mod(index2, (angleWidth * 4));
  //   element = mod(index2, angleWidth);
  //   // TODO: Plus 2?
  //   for (unsigned short y = horizon + 2; y < LCD_HEIGHT_PX; y += 2) {
  //     unsigned short thing = getScreenPixel(x, y);
  //     setPixel(x * 2, y, thing);
  //     setPixel(x * 2 + 1, y, thing);
  //     setPixel(x * 2 + 2, y, thing);
  //     setPixel(x * 2 + 3, y, thing);

  //     setPixel(x * 2, y + 1, thing);
  //     setPixel(x * 2 + 1, y + 1, thing);
  //     setPixel(x * 2 + 2, y + 1, thing);
  //     setPixel(x * 2 + 3, y + 1, thing);
  //   }
  // }
  // for (unsigned short x = LCD_WIDTH_PX / 8; x < (LCD_WIDTH_PX / 8) * 3; x += 1) {
  //   index2 = x + angle;
  //   index2 = mod(index2, (angleWidth * 4));
  //   element = mod(index2, angleWidth);
  //   // TODO: Plus 2?
  //   for (unsigned short y = horizon + 2; y < (LCD_HEIGHT_PX + horizon + 2) / 2; y += 1) {
  //     unsigned short thing = getScreenPixel(x, y);
  //     setPixel(x * 2, y, thing);
  //     setPixel(x * 2 + 1, y, thing);
  //   }

  //   for (unsigned short y = (LCD_HEIGHT_PX + horizon + 2) / 2; y < LCD_HEIGHT_PX; y += 2) {
  //     unsigned short thing = getScreenPixel(x, y);
  //     setPixel(x * 2, y, thing);
  //     setPixel(x * 2 + 1, y, thing);

  //     setPixel(x * 2, y + 1, thing);
  //     setPixel(x * 2 + 1, y + 1, thing);
  //   }
  // }
  // for (unsigned short x = (LCD_WIDTH_PX / 8) * 3; x < LCD_WIDTH_PX / 2; x += 2) {
  //   index2 = x + angle;
  //   index2 = mod(index2, (angleWidth * 4));
  //   element = mod(index2, angleWidth);
  //   // TODO: Plus 2?
  //   for (unsigned short y = horizon + 2; y < LCD_HEIGHT_PX; y += 2) {
  //     unsigned short thing = getScreenPixel(x, y);
  //     setPixel(x * 2, y, thing);
  //     setPixel(x * 2 + 1, y, thing);
  //     setPixel(x * 2 + 2, y, thing);
  //     setPixel(x * 2 + 3, y, thing);

  //     setPixel(x * 2, y + 1, thing);
  //     setPixel(x * 2 + 1, y + 1, thing);
  //     setPixel(x * 2 + 2, y + 1, thing);
  //     setPixel(x * 2 + 3, y + 1, thing);
  //   }
  // }

  for (unsigned short x = 0; x < LCD_WIDTH_PX / 2; x++) {
    index2 = x + angle;
    index2 = mod(index2, (angleWidth * 4));
    element = mod(index2, angleWidth);
    // TODO: Plus 2?
    for (unsigned short y = horizon + 2; y < LCD_HEIGHT_PX; y += 1) {
      unsigned short thing = getScreenPixel(x, y);
      setPixel(x * 2, y, thing);
      setPixel(x * 2 + 1, y, thing);
    }
  }

  if (kartSteerAnim >= 0) {
    CopySpriteMasked(mksprites[kartSteerAnim / 2], (LCD_WIDTH_PX / 2) - 36, 128, 72, 80, 0x4fe0);
    // CopySpriteMasked(/*mksprites[kartSteerAnim / 2]*/sprite, (LCD_WIDTH_PX / 2) - 39, 128, 78, 81, 0x07e0);
  } else {
    CopySpriteMaskedFlipped(mksprites[-kartSteerAnim / 2], (LCD_WIDTH_PX / 2) - 36, 128, 72, 80, 0x4fe0);
    // CopySpriteMaskedFlipped(/*mksprites[-kartSteerAnim / 2]*/sprite, (LCD_WIDTH_PX / 2) - 39, 128, 78, 81, 0x07e0);
  }

  Bdisp_PutDisp_DD_stripe(horizon + 2, LCD_HEIGHT_PX);

  frameCount++;
}

int main() {
  #ifdef FXCG_MOCK
  initMock();
  #endif

  VRAM = (color_t*)GetVRAMAddress();

  Bdisp_EnableColor(1);
  fillSky(0, LCD_HEIGHT_PX);
  #ifndef FXCG_MOCK
  lastTime = RTC_GetTicks();
  #endif

  #ifdef FXCG_MOCK
  #ifdef EMSCRIPTEN
  emscripten_set_main_loop(main_loop, 30, 1);
  #else
  set_main_loop(main_loop);
  #endif
  #else
  while (1) {
    main_loop();
  }
  #endif

  /* color_t* VRAM = (color_t*)0xA8000000; // emu address of VRAM
  VRAM += (LCD_WIDTH_PX*y + x);
  short j;
  for (j=y; j<y+height; j++) {
    for (int i = x; i< x + width;  i++) {
      *(VRAM++) = 0x07E0;
    }
    VRAM += LCD_WIDTH_PX - width;
  } */

  return 0;
}
