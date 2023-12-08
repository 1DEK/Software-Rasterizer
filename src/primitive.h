#ifndef PRIMITIVE_H
#define PRIMITIVE_H

#include <stdlib.h>

#include "render.h"
#include "vector.h"
#include "color.h"

typedef struct Polygon
{
	vec2 *points;
	int pointCount;
} polygon_t;

void drawLine(vec2 p1, vec2 p2, uint32_t color);
void drawTriangleFrame(vec2 p1, vec2 p2, vec2 p3, uint32_t color);
void drawTriangleFlat(vec2 p1, vec2 p2, vec2 p3, uint32_t color);
void drawTriangleShaded(vec2 p1, uint32_t color1, vec2 p2, uint32_t color2, vec2 p3, uint32_t color3);

polygon_t *newPolygon(int pointCount);
void deletePolygon(polygon_t *polygon);
void drawPolygonFrame(const polygon_t *polygon, color_t color);
void drawPolygonMeshConvex(const polygon_t *polygon, color_t color); // optimized for convex polygons
void drawPolygonMesh(const polygon_t *polygon, color_t color); // for general polygons
void drawPolygonFlatConvex(const polygon_t *polygon, color_t color); // optimized for convex polygons
void drawPolygonFlat(const polygon_t *polygon, color_t color); // for general polygons

#endif // PRIMITIVE_H
