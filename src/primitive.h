#ifndef PRIMITIVE_H
#define PRIMITIVE_H

#include "render.h"
#include "vector.h"
#include "color.h"

void drawLine(vec2 p1, vec2 p2, uint32_t color);
void drawTriangleFrame(vec2 p1, vec2 p2, vec2 p3, uint32_t color);
void drawTriangleFlat(vec2 p1, vec2 p2, vec2 p3, uint32_t color);
void drawTriangleShaded(vec2 p1, uint32_t color1, vec2 p2, uint32_t color2, vec2 p3, uint32_t color3);

#endif // PRIMITIVE_H
