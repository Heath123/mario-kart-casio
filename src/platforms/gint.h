#define PROFILING_ENABLED

#ifndef _PLATFORM_H
#define _PLATFORM_H

#include <gint/display-cg.h>
#include <gint/keyboard.h>
#ifdef PROFILING_ENABLED
#include <libprof.h>
#endif

#define LCD_WIDTH_PX /*384*/ 396
#define LCD_HEIGHT_PX /*216*/ 224

#define VRAM gint_vram

#define BUTTON_UP KEY_UP
#define BUTTON_DOWN KEY_DOWN
#define BUTTON_LEFT KEY_LEFT
#define BUTTON_RIGHT KEY_RIGHT
#define BUTTON_ACCEL KEY_SHIFT
#define BUTTON_HOP_1 KEY_ALPHA
#define BUTTON_HOP_2 KEY_7
#define BUTTON_DEBUG KEY_EXE
#define BUTTON_SAVE KEY_F1
#define BUTTON_LOAD KEY_F2
#define BUTTON_FRAMECAP_TOGGLE KEY_F3

void platformInit(void);
void runMainLoop(void (*loop)(), int fps);
void updateKeys(void);
void displayUpdateBox(int x, int y, int w, int h);
void displayUpdate(int minY, int maxY);
void drawText(int x, int y, const char *text);
int getTimeMS(void);
int check_key(int key);

#ifdef PROFILING_ENABLED
#define profile prof_exec
#else
#define profile(code) ({ code; 0; })
#endif

struct image;

void draw(const struct image *img, int x, int y);
void draw_partial(const struct image *img, int x, int y, int sx, int sy, int w, int h);
void draw_flipped(const struct image *img, int x, int y);
void draw_partial_flipped(const struct image *img, int x, int y, int sx, int sy, int w, int h);
void draw_scaled(const struct image *img, int x, int y, float scaleX, float scaleY);

int get_width(const struct image* img);
int get_height(const struct image* img);

#endif // _PLATFORM_H
