#ifndef MATRIX_H
#define MATRIX_H

#include "vector.h"

typedef struct Mat3
{
	float a11, a12, a13;
	float a21, a22, a23;
	float a31, a32, a33;
} mat3;

typedef struct Mat4
{
	float a11, a12, a13, a14;
	float a21, a22, a23, a24;
	float a31, a32, a33, a34;
	float a41, a42, a43, a44;
} mat4;

vec2 vec2Transform(const mat3 *transformation, vec2 v);
vec3 vec3Transform(const mat4 *transformation, vec3 v);

#endif // MATRIX_H
