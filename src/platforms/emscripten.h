// #define PROFILING_ENABLED 0

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
#define BUTTON_SAVE 81
#define BUTTON_LOAD 87
#define BUTTON_FRAMECAP_TOGGLE 70

void platformInit(void);
void runMainLoop(void (*loop)(), int fps);
void updateKeys(void);
void displayUpdateBox(int x, int y, int w, int h);
void displayUpdate(int minY, int maxY);
void drawText(int x, int y, const char *text);
int getTimeMS(void);
int check_key(int key);

#define profile(code) ({ code; 0; })

struct image;

void draw(const struct image *img, int x, int y);
void draw_partial(const struct image *img, int x, int y, int sx, int sy, int w, int h);
void draw_flipped(const struct image *img, int x, int y);
void draw_partial_flipped(const struct image *img, int x, int y, int sx, int sy, int w, int h);
void draw_scaled(const struct image *img, int x, int y, float scaleX, float scaleY);

int get_width(const struct image* img);
int get_height(const struct image* img);

#endif // _PLATFORM_H
