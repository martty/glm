/// @ref core
/// @file glm/glm.cpp

#ifndef GLM_ENABLE_EXPERIMENTAL
#define GLM_ENABLE_EXPERIMENTAL
#endif
#include <glm/gtx/dual_quaternion.hpp>
#include <glm/gtc/quaternion.hpp>
#include <glm/ext/scalar_int_sized.hpp>
#include <glm/ext/scalar_uint_sized.hpp>
#include <glm/glm.hpp>

namespace glm
{

// tvec2 type explicit instantiation
template struct vec<2, uint8>;
template struct vec<2, uint16>;
template struct vec<2, uint32>;
template struct vec<2, uint64>;
template struct vec<2, int8>;
template struct vec<2, int16>;
template struct vec<2, int32>;
template struct vec<2, int64>;
template struct vec<2, float32>;
template struct vec<2, float64>;

// tvec3 type explicit instantiation
template struct vec<3, uint8>;
template struct vec<3, uint16>;
template struct vec<3, uint32>;
template struct vec<3, uint64>;
template struct vec<3, int8>;
template struct vec<3, int16>;
template struct vec<3, int32>;
template struct vec<3, int64>;
template struct vec<3, float32>;
template struct vec<3, float64>;

// tvec4 type explicit instantiation
template struct vec<4, uint8>;
template struct vec<4, uint16>;
template struct vec<4, uint32>;
template struct vec<4, uint64>;
template struct vec<4, int8>;
template struct vec<4, int16>;
template struct vec<4, int32>;
template struct vec<4, int64>;
template struct vec<4, float32>;
template struct vec<4, float64>;

// tmat2x2 type explicit instantiation
template struct mat<2, 2, float32>;
template struct mat<2, 2, float64>;

// tmat2x3 type explicit instantiation
template struct mat<2, 3, float32>;
template struct mat<2, 3, float64>;

// tmat2x4 type explicit instantiation
template struct mat<2, 4, float32>;
template struct mat<2, 4, float64>;

// tmat3x2 type explicit instantiation
template struct mat<3, 2, float32>;
template struct mat<3, 2, float64>;

// tmat3x3 type explicit instantiation
template struct mat<3, 3, float32>;
template struct mat<3, 3, float64>;

// tmat3x4 type explicit instantiation
template struct mat<3, 4, float32>;
template struct mat<3, 4, float64>;

// tmat4x2 type explicit instantiation
template struct mat<4, 2, float32>;
template struct mat<4, 2, float64>;

// tmat4x3 type explicit instantiation
template struct mat<4, 3, float32>;
template struct mat<4, 3, float64>;

// tmat4x4 type explicit instantiation
template struct mat<4, 4, float32>;
template struct mat<4, 4, float64>;

// tquat type explicit instantiation
template struct qua<float32>;
template struct qua<float64>;

//tdualquat type explicit instantiation
template struct tdualquat<float32>;
template struct tdualquat<float64>;

}//namespace glm

