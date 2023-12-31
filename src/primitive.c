#include "primitive.h"
#include <assert.h>

void drawLine(vec2 p1, vec2 p2, uint32_t color)
{
	float dx = p2.x - p1.x;
	float dy = p2.y - p1.y;
	// more vertical line
	if (fabs(dy) > fabs(dx))
	{
		if (dy < 0.0)
		{
			vec2 temp = p1;
			p1 = p2;
			p2 = temp;
		}
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
		if (dx < 0.0)
		{
			vec2 temp = p1;
			p1 = p2;
			p2 = temp;
		}
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
	// sort points by y-coordinate
	if (p2.y < p1.y)
	{
		vec2 temp = p1;
		p1 = p2;
		p2 = temp;
	}
	if (p3.y < p2.y)
	{
		vec2 temp = p2;
		p2 = p3;
		p3 = temp;
	}
	if (p2.y < p1.y)
	{
		vec2 temp = p1;
		p1 = p2;
		p2 = temp;
	}

	// TODO these are floats, need to use a different way to compare probably, but IDK
	// top left rule set up
	if (p1.y == p2.y && p1.x < p2.x)
	{
		vec2 temp = p1;
		p1 = p2;
		p2 = temp;
	}
	else if (p2.y == p3.y && p2.x < p3.x)
	{
		vec2 temp = p2;
		p2 = p3;
		p3 = temp;
	}

	// p2 is on the left side
	if (vec2Cross(vec2Subtract(p2, p1), vec2Subtract(p3, p1)).z < 0.0)
	{
		float x0 = p1.x;
		float x1 = p1.x;
		float m0 = (p2.x - p1.x)/(p2.y - p1.y);
		float m1 = (p3.x - p1.x)/(p3.y - p1.y);
		for (int y = p1.y; y < p2.y; y++)
		{
			for (int x = x0; x < x1; x++)
			{
				putPixel(x, y, color);
			}
			x0 += m0;
			x1 += m1;
		}
		x0 = p2.x;
		m0 = (p3.x - p2.x)/(p3.y - p2.y);
		for (int y = p2.y; y <= p3.y; y++)
		{
			for (int x = x0; x < x1; x++)
			{
				putPixel(x, y, color);
			}
			x0 += m0;
			x1 += m1;
		}
	}
	// p2 is on the right side
	else
	{
		float x0 = p1.x;
		float x1 = p1.x;
		float m0 = (p3.x - p1.x)/(p3.y - p1.y);
		float m1 = (p2.x - p1.x)/(p2.y - p1.y);
		for (int y = p1.y; y < p2.y; y++)
		{
			for (int x = x0; x < x1; x++)
			{
				putPixel(x, y, color);
			}
			x0 += m0;
			x1 += m1;
		}
		x1 = p2.x;
		m1 = (p3.x - p2.x)/(p3.y - p2.y);
		for (int y = p2.y; y <= p3.y; y++)
		{
			for (int x = x0; x < x1; x++)
			{
				putPixel(x, y, color);
			}
			x0 += m0;
			x1 += m1;
		}		
	}
}

void drawTriangleShaded(vec2 p1, uint32_t color1, vec2 p2, uint32_t color2, vec2 p3, uint32_t color3)
{
	// sort points by y-coordinate
	if (p2.y < p1.y)
	{
		vec2 temp = p1;
		p1 = p2;
		p2 = temp;

		color_t tempCol = color1;
		color1 = color2;
		color2 = tempCol;
	}
	if (p3.y < p2.y)
	{
		vec2 temp = p2;
		p2 = p3;
		p3 = temp;

		color_t tempCol = color2;
		color2 = color3;
		color3 = tempCol;
	}
	if (p2.y < p1.y)
	{
		vec2 temp = p1;
		p1 = p2;
		p2 = temp;

		color_t tempCol = color1;
		color1 = color2;
		color2 = tempCol;
	}

	// TODO these are floats, need to use a different way to compare probably, but IDK
	// top left rule set up
	if (p1.y == p2.y && p1.x < p2.x)
	{
		vec2 temp = p1;
		p1 = p2;
		p2 = temp;

		color_t tempCol = color1;
		color1 = color2;
		color2 = tempCol;
	}
	else if (p2.y == p3.y && p2.x < p3.x)
	{
		vec2 temp = p2;
		p2 = p3;
		p3 = temp;

		color_t tempCol = color2;
		color2 = color3;
		color3 = tempCol;
	}

	vec3 cross = vec2Cross(vec2Subtract(p2, p1), vec2Subtract(p3, p1));
	float triangleArea = vec3Length(cross);
	// p2 is on the left side
	if (cross.z < 0.0)
	{
		float x0 = p1.x;
		float x1 = p1.x;
		float m0 = (p2.x - p1.x)/(p2.y - p1.y);
		float m1 = (p3.x - p1.x)/(p3.y - p1.y);
		for (int y = p1.y; y < p2.y; y++)
		{
			for (int x = x0; x < x1; x++)
			{
				vec2 p = (vec2){x, y};
				vec2 p1_p = vec2Subtract(p, p1);
				vec2 p2_p = vec2Subtract(p, p2);
				vec2 p3_p = vec2Subtract(p, p3);
				float alpha = vec3Length(vec2Cross(p2_p, p3_p))/triangleArea;
				float beta = vec3Length(vec2Cross(p1_p, p3_p))/triangleArea;
				float gamma = vec3Length(vec2Cross(p1_p, p2_p))/triangleArea;
				color_t color = colorAdd(colorScale(color1, alpha), colorAdd(colorScale(color2, beta), colorScale(color3, gamma)));
				putPixel(x, y, color);
			}
			x0 += m0;
			x1 += m1;
		}
		x0 = p2.x;
		m0 = (p3.x - p2.x)/(p3.y - p2.y);
		for (int y = p2.y; y <= p3.y; y++)
		{
			for (int x = x0; x < x1; x++)
			{
				vec2 p = (vec2){x, y};
				vec2 p1_p = vec2Subtract(p, p1);
				vec2 p2_p = vec2Subtract(p, p2);
				vec2 p3_p = vec2Subtract(p, p3);
				float alpha = vec3Length(vec2Cross(p2_p, p3_p))/triangleArea;
				float beta = vec3Length(vec2Cross(p1_p, p3_p))/triangleArea;
				float gamma = vec3Length(vec2Cross(p1_p, p2_p))/triangleArea;
				color_t color = colorAdd(colorScale(color1, alpha), colorAdd(colorScale(color2, beta), colorScale(color3, gamma)));
				putPixel(x, y, color);
			}
			x0 += m0;
			x1 += m1;
		}
	}
	// p2 is on the right side
	else
	{
		float x0 = p1.x;
		float x1 = p1.x;
		float m0 = (p3.x - p1.x)/(p3.y - p1.y);
		float m1 = (p2.x - p1.x)/(p2.y - p1.y);
		for (int y = p1.y; y < p2.y; y++)
		{
			for (int x = x0; x < x1; x++)
			{
				vec2 p = (vec2){x, y};
				vec2 p1_p = vec2Subtract(p, p1);
				vec2 p2_p = vec2Subtract(p, p2);
				vec2 p3_p = vec2Subtract(p, p3);
				float alpha = vec3Length(vec2Cross(p2_p, p3_p))/triangleArea;
				float beta = vec3Length(vec2Cross(p1_p, p3_p))/triangleArea;
				float gamma = vec3Length(vec2Cross(p1_p, p2_p))/triangleArea;
				color_t color = colorAdd(colorScale(color1, alpha), colorAdd(colorScale(color2, beta), colorScale(color3, gamma)));
				putPixel(x, y, color);
			}
			x0 += m0;
			x1 += m1;
		}
		x1 = p2.x;
		m1 = (p3.x - p2.x)/(p3.y - p2.y);
		for (int y = p2.y; y <= p3.y; y++)
		{
			for (int x = x0; x < x1; x++)
			{
				vec2 p = (vec2){x, y};
				vec2 p1_p = vec2Subtract(p, p1);
				vec2 p2_p = vec2Subtract(p, p2);
				vec2 p3_p = vec2Subtract(p, p3);
				float alpha = vec3Length(vec2Cross(p2_p, p3_p))/triangleArea;
				float beta = vec3Length(vec2Cross(p1_p, p3_p))/triangleArea;
				float gamma = vec3Length(vec2Cross(p1_p, p2_p))/triangleArea;
				color_t color = colorAdd(colorScale(color1, alpha), colorAdd(colorScale(color2, beta), colorScale(color3, gamma)));
				putPixel(x, y, color);
			}
			x0 += m0;
			x1 += m1;
		}		
	}
}

polygon_t *newPolygon(int pointCount)
{
	assert(pointCount > 2);

	polygon_t *polygon = malloc(sizeof(*polygon));
	if (polygon == NULL)
	{
		return NULL;
	}
	
	polygon->points = malloc(pointCount*sizeof(*polygon->points));
	polygon->pointCount = pointCount;
	if (polygon->points == NULL)
	{
		free(polygon);
		return NULL;
	}
	
	return polygon;
}

void deletePolygon(polygon_t *polygon)
{
	free(polygon->points);
	free(polygon);
}

void drawPolygonFrame(const polygon_t *polygon, color_t color)
{
	for (int i = 0; i < polygon->pointCount - 1; i++)
	{
		drawLine(polygon->points[i], polygon->points[i + 1], color);
	}
	drawLine(polygon->points[polygon->pointCount - 1], polygon->points[0], color);
}

void drawPolygonMeshConvex(const polygon_t *polygon, color_t color)
{
	drawPolygonFrame(polygon, color);
	vec2 pivot = polygon->points[0];
	for (int i = 2; i < polygon->pointCount - 1; i++)
	{
		drawLine(pivot, polygon->points[i], color);
	}
}

void drawPolygonMesh(const polygon_t *polygon, color_t color)
{
	// TODO
	(void)polygon;
	(void)color;
}

void drawPolygonFlatConvex(const polygon_t *polygon, color_t color)
{
	vec2 pivot = polygon->points[0];
	for (int i = 2; i < polygon->pointCount; i++)
	{
		drawTriangleFlat(pivot, polygon->points[i], polygon->points[i - 1], color);
	}
}

void drawPolygonFlat(const polygon_t *polygon, color_t color)
{
	// TODO
	(void)polygon;
	(void)color;
}
