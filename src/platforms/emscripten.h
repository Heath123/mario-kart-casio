#ifndef _PLATFORM_H
#define _PLATFORM_H

#define LCD_WIDTH_PX 396
#define LCD_HEIGHT_PX 224

// #define VRAM gint_vram
typedef unsigned short color_t;
extern color_t VRAM[LCD_HEIGHT_PX * LCD_WIDTH_PX];

#define BUTTON_UP 38
#define BUTTON_DOWN 40
#define BUTTON_LEFT 37
#define BUTTON_RIGHT 39
#define BUTTON_ACCEL 88
#define BUTTON_HOP_1 90
#define BUTTON_HOP_2 90
#define BUTTON_DEBUG 13
#define BUTTON_SAVE 113
#define BUTTON_LOAD 119
#define BUTTON_DEBUG_BOOST 66

void platformInit(void);
void runMainLoop(void (*loop)(), int fps);
void updateKeys(void);
void displayUpdate(int minY, int maxY);
void drawText(int x, int y, const char *text);
int getTimeMS(void);
int check_key(int key);

#endif // _PLATFORM_H
