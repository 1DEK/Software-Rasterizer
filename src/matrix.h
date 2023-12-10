#ifndef MATRIX_H
#define MATRIX_H

#include "vector.h"

typedef struct Mat2
{
	float a11, a12;
	float a21, a22;
} mat2;

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

typedef struct Vec4
{
	float x, y, z, w;
} vec4;

vec2 mat2MultiplyVec2(const mat2 *m, vec2 v);
vec3 mat3MultiplyVec3(const mat3 *m, vec3 v);
vec4 mat4MultiplyVec4(const mat4 *m, vec4 v);

mat2 mat2MultiplyMat2(const mat2 *m1, const mat2 *m2);
mat3 mat3MultiplyMat3(const mat3 *m1, const mat3 *m2);
mat4 mat4MultiplyMat4(const mat4 *m1, const mat4 *m2);

#endif // MATRIX_H
