#include "transform.h"
#include <assert.h>
#include <math.h>

mat3 create2DTranslationMatrix(float xShift, float yShift)
{
	return (mat3){
		1.0, 0.0, xShift,
		0.0, 1.0, yShift,
		0.0, 0.0, 1.0
	};
}

mat3 create2DRotationMatrix(vec2 point, float angle)
{
	float sine = sinf(angle);
	float cosine = cosf(angle);
	
	mat3 m1 = create2DTranslationMatrix(-point.x, -point.y);
	mat3 m2 = (mat3){
		cosine, -sine,  0.0,
		sine,   cosine, 0.0,
		0.0,    0.0,    1.0
	};
	mat3 m3 = create2DTranslationMatrix(point.x, point.y);
	mat3 m4 = mat3MultiplyMat3(&m2, &m1);
	return mat3MultiplyMat3(&m3, &m4);
}

mat4 create3DTranslationMatrix(float xShift, float yShift, float zShift)
{
	return (mat4){
		1.0, 0.0, 0.0, xShift,
		0.0, 1.0, 0.0, yShift,
		0.0, 0.0, 1.0, zShift,
		0.0, 0.0, 0.0, 1.0
	};
}

mat4 create3DRotationMatrix(vec3 point, vec3 axis, float angle)
{
	assert(fabs(vec3Length(axis) - 1.0) < 0.01);

	float sine = sinf(angle);
	float cosine = cosf(angle);
	float x = axis.x;
	float y = axis.y;
	float z = axis.z;

	mat4 m1 = create3DTranslationMatrix(-point.x, -point.y, -point.z);
	mat4 m2 = (mat4){
		cosine + x*x*(1 - cosine),  x*y*(1 - cosine) - z*sine, x*z*(1 - cosine) + y*sine, 0.0,
		y*x*(1 - cosine) + z*sine,  cosine + y*y*(1 - cosine), y*z*(1 - cosine) - x*sine, 0.0,
		z*x*(1 - cosine) - y*sine,  z*y*(1 - cosine) + x*sine, cosine + z*z*(1 - cosine), 0.0,
		0.0,                        0.0,                       0.0,                       1.0
	};
	mat4 m3 = create3DTranslationMatrix(point.x, point.y, point.z);
	mat4 m4 = mat4MultiplyMat4(&m2, &m1);
	return mat4MultiplyMat4(&m3, &m4);
}
