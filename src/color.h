#ifndef COLOR_H
#define COLOR_H

#include <stdint.h>

#define CLAMP(val, min, max) (((val) < (min)) ? (min) : (((val) > (max)) ? (max) : (val)))

#define RED_SHIFT 16
#define GREEN_SHIFT 8
#define BLUE_SHIFT 0
#define RED_MASK 0x00FF0000
#define GREEN_MASK 0x0000FF00
#define BLUE_MASK 0x000000FF

typedef uint32_t color_t;

color_t color(int r, int g, int b);
color_t colorAdd(color_t color1, color_t color2);
color_t colorSubtract(color_t color1, color_t color2);
color_t colorScale(color_t color, float scale);
// color_t colorAverage(color_t color1, float weight1, color_t color2, float weight2, color_t color2, float weight2);

#endif // COLOR_H
