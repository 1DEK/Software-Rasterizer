#ifndef TRANSFORM_H
#define TRANSFORM_H

#include "matrix.h"

mat3 create2DTranslationMatrix(float xShift, float yShift);
mat3 create2DRotationMatrix(vec2 point, float angle);

mat4 create3DTranslationMatrix(float xShift, float yShift, float zShift);
mat4 create3DRotationMatrix(vec3 point, vec3 axis, float angle); // axis must be unit vector

#endif // TRANSFORM_H
