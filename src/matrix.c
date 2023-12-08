#include "matrix.h"

vec2 vec2Transform(const mat3 *transformation, vec2 v)
{
	return (vec2){
		transformation->a11*v.x + transformation->a12*v.y + transformation->a13,
		transformation->a21*v.x + transformation->a22*v.y + transformation->a23,
	};
}

vec3 vec3Transform(const mat4 *transformation, vec3 v)
{
	return (vec3){
		transformation->a11*v.x + transformation->a12*v.y + transformation->a13*v.z + transformation->a14,
		transformation->a21*v.x + transformation->a22*v.y + transformation->a23*v.z + transformation->a24,
		transformation->a31*v.x + transformation->a32*v.y + transformation->a33*v.z + transformation->a34
	};
}
