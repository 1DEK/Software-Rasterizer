#include "matrix.h"

vec2 mat2MultiplyVec2(const mat2 *m, vec2 v)
{
	return (vec2){
		m->a11*v.x + m->a12*v.y,
		m->a21*v.x + m->a22*v.y
	};
}

vec3 mat3MultiplyVec3(const mat3 *m, vec3 v)
{
	return (vec3){
		m->a11*v.x + m->a12*v.y + m->a13*v.z,
		m->a21*v.x + m->a22*v.y + m->a23*v.z,
		m->a31*v.x + m->a32*v.y + m->a33*v.z
	};
}

vec4 mat4MultiplyVec4(const mat4 *m, vec4 v)
{
	return (vec4){
		m->a11*v.x + m->a12*v.y + m->a13*v.z + m->a14*v.w,
		m->a21*v.x + m->a22*v.y + m->a23*v.z + m->a24*v.w,
		m->a31*v.x + m->a32*v.y + m->a33*v.z + m->a34*v.w,
		m->a41*v.x + m->a42*v.y + m->a43*v.z + m->a44*v.w
	};
}

mat2 mat2MultiplyMat2(const mat2 *m1, const mat2 *m2)
{
	return (mat2){
		m1->a11*m2->a11 + m1->a12*m2->a21, m1->a11*m2->a12 + m1->a12*m2->a22,
		m1->a21*m2->a11 + m1->a22*m2->a21, m1->a21*m2->a12 + m1->a22*m2->a22,
	};
}

mat3 mat3MultiplyMat3(const mat3 *m1, const mat3 *m2)
{
	return (mat3){
		m1->a11*m2->a11 + m1->a12*m2->a21 + m1->a13*m2->a31, m1->a11*m2->a12 + m1->a12*m2->a22 + m1->a13*m2->a32, m1->a11*m2->a13 + m1->a12*m2->a23 + m1->a13*m2->a33,
		m1->a21*m2->a11 + m1->a22*m2->a21 + m1->a23*m2->a31, m1->a21*m2->a12 + m1->a22*m2->a22 + m1->a23*m2->a32, m1->a21*m2->a13 + m1->a22*m2->a23 + m1->a23*m2->a33,
		m1->a31*m2->a11 + m1->a32*m2->a21 + m1->a33*m2->a31, m1->a31*m2->a12 + m1->a32*m2->a22 + m1->a33*m2->a32, m1->a31*m2->a13 + m1->a32*m2->a23 + m1->a33*m2->a33
	};
}

mat4 mat4MultiplyMat4(const mat4 *m1, const mat4 *m2)
{
	return (mat4){
		m1->a11*m2->a11 + m1->a12*m2->a21 + m1->a13*m2->a31 + m1->a14*m2->a41, m1->a11*m2->a12 + m1->a12*m2->a22 + m1->a13*m2->a32 + m1->a14*m2->a42, m1->a11*m2->a13 + m1->a12*m2->a23 + m1->a13*m2->a33 + m1->a14*m2->a43, m1->a11*m2->a14 + m1->a12*m2->a24 + m1->a13*m2->a34 + m1->a14*m2->a44,
		m1->a21*m2->a11 + m1->a22*m2->a21 + m1->a23*m2->a31 + m1->a24*m2->a41, m1->a21*m2->a12 + m1->a22*m2->a22 + m1->a23*m2->a32 + m1->a24*m2->a42, m1->a21*m2->a13 + m1->a22*m2->a23 + m1->a23*m2->a33 + m1->a24*m2->a43, m1->a21*m2->a14 + m1->a22*m2->a24 + m1->a23*m2->a34 + m1->a24*m2->a44,
		m1->a31*m2->a11 + m1->a32*m2->a21 + m1->a33*m2->a31 + m1->a34*m2->a41, m1->a31*m2->a12 + m1->a32*m2->a22 + m1->a33*m2->a32 + m1->a34*m2->a42, m1->a31*m2->a13 + m1->a32*m2->a23 + m1->a33*m2->a33 + m1->a34*m2->a43, m1->a31*m2->a14 + m1->a32*m2->a24 + m1->a33*m2->a34 + m1->a34*m2->a44,
		m1->a41*m2->a11 + m1->a42*m2->a21 + m1->a43*m2->a31 + m1->a44*m2->a41, m1->a41*m2->a12 + m1->a42*m2->a22 + m1->a43*m2->a32 + m1->a44*m2->a42, m1->a41*m2->a13 + m1->a42*m2->a23 + m1->a43*m2->a33 + m1->a44*m2->a43, m1->a41*m2->a14 + m1->a42*m2->a24 + m1->a43*m2->a34 + m1->a44*m2->a44
	};
}
