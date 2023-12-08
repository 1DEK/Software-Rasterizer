#include "primitive.h"

void drawLine(vec2 p1, vec2 p2, uint32_t color)
{
	float dx = p2.x - p1.x;
	float dy = p2.y - p1.y;
	// more vertical line
	if (fabs(dy) > fabs(dx))
	{
		float m = dx/dy;
		float x = p1.x;
		for (int y = p1.y; y <= p2.y; y++)
		{
			putPixel(x, y, color);
			x += m;
		}
	}
	// more horizantal line
	else
	{
		float m = dy/dx;
		float y = p1.y;
		for (int x = p1.x; x <= p2.x; x++)
		{
			putPixel(x, y, color);
			y += m;
		}
	}
}

void drawTriangleFrame(vec2 p1, vec2 p2, vec2 p3, uint32_t color)
{
	drawLine(p1, p2, color);
	drawLine(p2, p3, color);
	drawLine(p3, p1, color);
}

void drawTriangleFlat(vec2 p1, vec2 p2, vec2 p3, uint32_t color)
{
	// TODO
	(void)p1;
	(void)p2;
	(void)p3;
	(void)color;
}

void drawTriangleShaded(vec2 p1, uint32_t color1, vec2 p2, uint32_t color2, vec2 p3, uint32_t color3)
{
	// TODO
	(void)p1;
	(void)color1;
	(void)p2;
	(void)color2;
	(void)p3;
	(void)color3;
}
