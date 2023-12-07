#include <SDL2/SDL.h>
#include <stdlib.h>

#include "render.h"

SDL_Window *p_window = NULL;
SDL_Renderer *p_renderer = NULL;
SDL_Texture *p_texture = NULL;
uint32_t *p_framebuffer = NULL;
bool p_shouldclose = false;

bool createWindow(void)
{
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		puts("Error:");
		puts(SDL_GetError());
		return false;
	}

	p_window = SDL_CreateWindow(
		"Software Rasterizer", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
		SCREEN_WIDTH, SCREEN_HEIGHT, 0
	);
	if (p_window == NULL)
	{
		puts("Error:");
		puts(SDL_GetError());
		SDL_Quit();
		return false;
	}

	p_renderer = SDL_CreateRenderer(p_window, -1, SDL_RENDERER_SOFTWARE);
	if (p_renderer == NULL)
	{
		puts("Error:");
		puts(SDL_GetError());
		SDL_DestroyWindow(p_window);
		SDL_Quit();
		return false;
	}

	p_texture = SDL_CreateTexture(
		p_renderer, SDL_PIXELFORMAT_RGB888, SDL_TEXTUREACCESS_STREAMING, 
		SCREEN_WIDTH, SCREEN_HEIGHT
	);
	if (p_texture == NULL)
	{
		puts("Error:");
		puts(SDL_GetError());
		SDL_DestroyRenderer(p_renderer);
		SDL_DestroyWindow(p_window);
		SDL_Quit();
		return false;
	}

	p_framebuffer = malloc(SCREEN_WIDTH*SCREEN_HEIGHT*sizeof(*p_framebuffer));
	if (p_framebuffer == NULL)
	{
		puts("Error:");
		puts(SDL_GetError());
		SDL_DestroyTexture(p_texture);
		SDL_DestroyRenderer(p_renderer);
		SDL_DestroyWindow(p_window);
		SDL_Quit();
		return false;
	}

	return true;
}

void destroyWindow(void)
{
	free(p_framebuffer);
	SDL_DestroyTexture(p_texture);
	SDL_DestroyRenderer(p_renderer);
	SDL_DestroyWindow(p_window);
	SDL_Quit();
}

bool windowShouldClose(void)
{
	return p_shouldclose;
}

void processEvents(void)
{
	SDL_Event event;
	while (SDL_PollEvent(&event))
	{
		switch(event.type)
		{
		case SDL_QUIT:
			p_shouldclose = true;
			break;
		}
	}
}

void swapBuffer(void)
{
	SDL_UpdateTexture(
		p_texture, 
		&(SDL_Rect){
			0, 0, SCREEN_WIDTH, SCREEN_HEIGHT
		},
		p_framebuffer,
		SCREEN_WIDTH*sizeof(*p_framebuffer)
	);
	SDL_RenderCopy(
		p_renderer, 
		p_texture,
		&(SDL_Rect){
			0, 0, SCREEN_WIDTH, SCREEN_HEIGHT
		},
		&(SDL_Rect){
			0, 0, SCREEN_WIDTH, SCREEN_HEIGHT
		}
	);
	SDL_RenderPresent(p_renderer);
}

void clearBuffer(uint32_t color)
{
	for (int i = 0; i < SCREEN_WIDTH*SCREEN_HEIGHT; i++)
	{
		p_framebuffer[i] = color;
	}
}

void putPixel(int x, int y, uint32_t color)
{
	if (x < 0 || x >= SCREEN_WIDTH || y < 0 || y >= SCREEN_HEIGHT)
	{
		return;
	}
	p_framebuffer[y*SCREEN_WIDTH + x] = color;
}
