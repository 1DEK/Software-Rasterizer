#ifndef VECTOR_H
#define VECTOR_H

typedef struct Vec2
{
	float x, y;
} vec2;

typedef struct Vec3
{
	float x, y, z;
} vec3;

vec2 vec2Add(vec2 v1, vec2 v2);
vec2 vec2Subtract(vec2 v1, vec2 v2);
vec2 vec2Scale(vec2 v, float s);
float vec2Dot(vec2 v1, vec2 v2);
vec3 vec2Cross(vec2 v1, vec2 v2);
float vec2Length(vec2 v);
vec2 vec2Normalized(vec2 v);

vec3 vec3Add(vec3 v1, vec3 v2);
vec3 vec3Subtract(vec3 v1, vec3 v2);
vec3 vec3Scale(vec3 v, float s);
float vec3Dot(vec3 v1, vec3 v2);
vec3 vec3Cross(vec3 v1, vec3 v2);
float vec3Length(vec3 v);
vec3 vec3Normalized(vec3 v);

#endif // VECTOR_H
