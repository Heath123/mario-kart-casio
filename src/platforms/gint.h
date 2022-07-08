#ifndef _PLATFORM_H
#define _PLATFORM_H

#include <gint/display-cg.h>
#include <gint/keyboard.h>

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
#define BUTTON_DEBUG_BOOST -1

void platformInit(void);
void runMainLoop(void (*loop)(), int fps);
void updateKeys(void);
void displayUpdate(int minY, int maxY);
void drawText(int x, int y, const char *text);
int getTimeMS(void);
int check_key(int key);

#endif // _PLATFORM_H
