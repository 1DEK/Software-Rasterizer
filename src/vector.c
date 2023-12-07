#include "vector.h"
#include <math.h>

vec2 vec2Add(vec2 v1, vec2 v2)
{
	return (vec2){v1.x + v2.x, v1.y + v2.y};
}

vec2 vec2Subtract(vec2 v1, vec2 v2)
{
	return (vec2){v1.x - v2.x, v1.y - v2.y};
}

vec2 vec2Scale(vec2 v, float s)
{
	return (vec2){s*v.x, s*v.y};
}

float vec2Dot(vec2 v1, vec2 v2)
{
	return v1.x*v2.x + v1.y*v2.y;
}

vec3 vec2Cross(vec2 v1, vec2 v2)
{
	return vec3Cross((vec3){v1.x, v1.y, 0.0}, (vec3){v2.x, v2.y, 0.0});
}

float vec2Length(vec2 v)
{
	return sqrtf(vec2Dot(v, v));
}

vec2 vec2Normalized(vec2 v)
{
	float mag = vec2Length(v);
	v.x /= mag;
	v.y /= mag;
	return v;
}

vec3 vec3Add(vec3 v1, vec3 v2)
{
	return (vec3){v1.x + v2.x, v1.y + v2.y, v1.z + v2.z};
}

vec3 vec3Subtract(vec3 v1, vec3 v2)
{
	return (vec3){v1.x - v2.x, v1.y - v2.y, v1.z - v2.z};
}

vec3 vec3Scale(vec3 v, float s)
{
	return (vec3){s*v.x, s*v.y, s*v.z};
}

float vec3Dot(vec3 v1, vec3 v2)
{
	return v1.x*v2.x + v1.y*v2.y + v1.z*v2.z;
}

vec3 vec3Cross(vec3 v1, vec3 v2)
{
	return (vec3) {
		v1.y*v2.z - v1.z*v2.y,
		v1.z*v2.x - v1.x*v2.z,
		v1.x*v2.y - v1.y*v2.x
	};
}

float vec3Length(vec3 v)
{
	return sqrtf(vec3Dot(v, v));
}

vec3 vec3Normalized(vec3 v)
{
	float mag = vec3Length(v);
	v.x /= mag;
	v.y /= mag;
	v.z /= mag;
	return v;
}
