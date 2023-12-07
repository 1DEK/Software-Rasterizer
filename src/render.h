#ifndef RENDER_H
#define RENDER_H

#include <SDL2/SDL.h>

#include <stdbool.h>
#include <stdint.h>

/*
	TODO

	Remove canvas and fit everything into this file and make it mostly handled by SDL.
	For example, won't need a color struct anymore and will just use uint32_t for that.
*/

#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 600

bool createWindow(void);
void destroyWindow(void);
bool windowShouldClose(void);
void processEvents(void);
void swapBuffer(void);
void clearBuffer(uint32_t color);
void putPixel(int x, int y, uint32_t color);

#endif // RENDER_H
