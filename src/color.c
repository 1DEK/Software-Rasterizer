#include "color.h"

color_t color(int r, int g, int b)
{
	uint32_t red = CLAMP(r, 0, 0xFF);
	uint32_t green = CLAMP(g, 0, 0xFF);
	uint32_t blue = CLAMP(b, 0, 0xFF);
	return (red << RED_SHIFT) | (green << GREEN_SHIFT) | (blue << BLUE_SHIFT);
}

color_t colorAdd(color_t color1, color_t color2)
{
	int r1 = (color1 & RED_MASK) >> RED_SHIFT;
	int r2 = (color2 & RED_MASK) >> RED_SHIFT;
	int g1 = (color1 & GREEN_MASK) >> GREEN_SHIFT;
	int g2 = (color2 & GREEN_MASK) >> GREEN_SHIFT;
	int b1 = (color1 & BLUE_MASK) >> BLUE_SHIFT;
	int b2 = (color2 & BLUE_MASK) >> BLUE_SHIFT;
	uint32_t red = CLAMP(r1 + r2, 0, 0xFF);
	uint32_t green = CLAMP(g1 + g2, 0, 0xFF);
	uint32_t blue = CLAMP(b1 + b2, 0, 0xFF);
	return (red << RED_SHIFT) | (green << GREEN_SHIFT) | (blue << BLUE_SHIFT);
}

color_t colorSubtract(color_t color1, color_t color2)
{
	int r1 = (color1 & RED_MASK) >> RED_SHIFT;
	int r2 = (color2 & RED_MASK) >> RED_SHIFT;
	int g1 = (color1 & GREEN_MASK) >> GREEN_SHIFT;
	int g2 = (color2 & GREEN_MASK) >> GREEN_SHIFT;
	int b1 = (color1 & BLUE_MASK) >> BLUE_SHIFT;
	int b2 = (color2 & BLUE_MASK) >> BLUE_SHIFT;
	uint32_t red = CLAMP(r1 - r2, 0, 0xFF);
	uint32_t green = CLAMP(g1 - g2, 0, 0xFF);
	uint32_t blue = CLAMP(b1 - b2, 0, 0xFF);
	return (red << RED_SHIFT) | (green << GREEN_SHIFT) | (blue << BLUE_SHIFT);
}

color_t colorScale(color_t color, float scale)
{
	float r = (color & RED_MASK) >> RED_SHIFT;
	float g = (color & GREEN_MASK) >> GREEN_SHIFT;
	float b = (color & BLUE_MASK) >> BLUE_SHIFT;
	uint32_t red = CLAMP(scale*r, 0, 0xFF);
	uint32_t green = CLAMP(scale*g, 0, 0xFF);
	uint32_t blue = CLAMP(scale*b, 0, 0xFF);
	return (red << RED_SHIFT) | (green << GREEN_SHIFT) | (blue << BLUE_SHIFT);
}
