#pragma once

namespace detail {}

namespace glm
{
#if GLM_HAS_EXTENDED_INTEGER_TYPE
	typedef std::int8_t				int8;
	typedef std::int16_t			int16;
	typedef std::int32_t			int32;
	typedef std::int64_t			int64;

	typedef std::uint8_t			uint8;
	typedef std::uint16_t			uint16;
	typedef std::uint32_t			uint32;
	typedef std::uint64_t			uint64;
#else
	typedef signed char				int8;
	typedef signed short			int16;
	typedef signed int				int32;
	typedef detail::int64			int64;

	typedef unsigned char			uint8;
	typedef unsigned short			uint16;
	typedef unsigned int			uint32;
	typedef detail::uint64			uint64;
#endif

	// Scalar int
	typedef int8					i8;
	typedef int8					int8_t;
	typedef int16					i16;
	typedef int16					int16_t;
	typedef int32					i32;
	typedef int32					int32_t;
	typedef int64					i64;
	typedef int64					int64_t;

	// Scalar uint

	typedef uint8					u8;


	typedef uint8					uint8_t;
	typedef uint16					u16;
	typedef uint16					uint16_t;

	typedef uint32					u32;

	typedef uint32					uint32_t;
	typedef uint64					u64;

	typedef uint64					uint64_t;

	// Scalar float

	typedef float					f32;
	typedef float					float32;

	typedef float					float32_t;

	typedef double					f64;

	typedef double					float64;

	typedef double					float64_t;

	// Vector bool

	typedef vec<2, bool>	bvec2;
	typedef vec<3, bool>	bvec3;
	typedef vec<4, bool>	bvec4;

	// Vector int

	typedef vec<2, i32>	ivec2;
	typedef vec<3, i32>	ivec3;
	typedef vec<4, i32>	ivec4;

	typedef vec<2, i8>	i8vec2;
	typedef vec<3, i8>	i8vec3;
	typedef vec<4, i8>	i8vec4;

	typedef vec<2, i16>	i16vec2;
	typedef vec<3, i16>	i16vec3;
	typedef vec<4, i16>	i16vec4;

	typedef vec<2, i32>	i32vec2;
	typedef vec<3, i32>	i32vec3;
	typedef vec<4, i32>	i32vec4;

	typedef vec<2, i64>	i64vec2;
	typedef vec<3, i64>	i64vec3;
	typedef vec<4, i64>	i64vec4;

	// Vector uint

	typedef vec<2, u32>	uvec2;
	typedef vec<3, u32>	uvec3;
	typedef vec<4, u32>	uvec4;

	typedef vec<2, u8>	u8vec2;
	typedef vec<3, u8>	u8vec3;
	typedef vec<4, u8>	u8vec4;

	typedef vec<2, u16>	u16vec2;
	typedef vec<3, u16>	u16vec3;
	typedef vec<4, u16>	u16vec4;

	typedef vec<2, u32>	u32vec2;
	typedef vec<3, u32>	u32vec3;
	typedef vec<4, u32>	u32vec4;

	typedef vec<2, u64>	u64vec2;
	typedef vec<3, u64>	u64vec3;
	typedef vec<4, u64>	u64vec4;

	// Vector float

	typedef vec<2, float>		vec2;
	typedef vec<3, float>		vec3;
	typedef vec<4, float>		vec4;

	typedef vec<2, f32>		fvec2;
	typedef vec<3, f32>		fvec3;
	typedef vec<4, f32>		fvec4;

	typedef vec<2, f32>		f32vec2;
	typedef vec<3, f32>		f32vec3;
	typedef vec<4, f32>		f32vec4;

	typedef vec<2, f64>		dvec2;
	typedef vec<3, f64>		dvec3;
	typedef vec<4, f64>		dvec4;

	typedef vec<2, f64>		f64vec2;
	typedef vec<3, f64>		f64vec3;
	typedef vec<4, f64>		f64vec4;

	// Matrix NxN

	typedef mat<2, 2, f32>	mat2;
	typedef mat<3, 3, f32>	mat3;
	typedef mat<4, 4, f32>	mat4;

	typedef mat<2, 2, f32>	fmat2;
	typedef mat<3, 3, f32>	fmat3;
	typedef mat<4, 4, f32>	fmat4;

	typedef mat<2, 2, f32>	f32mat2;
	typedef mat<3, 3, f32>	f32mat3;
	typedef mat<4, 4, f32>	f32mat4;

	typedef mat<2, 2, f64>	dmat2;
	typedef mat<3, 3, f64>	dmat3;
	typedef mat<4, 4, f64>	dmat4;

	typedef mat<2, 2, f64>	f64mat2;
	typedef mat<3, 3, f64>	f64mat3;
	typedef mat<4, 4, f64>	f64mat4;

	// Matrix MxN

	typedef mat<2, 2, f32>	mat2x2;
	typedef mat<3, 2, f32>	mat3x2;
	typedef mat<4, 2, f32>	mat4x2;
	typedef mat<2, 3, f32>	mat2x3;
	typedef mat<3, 3, f32>	mat3x3;
	typedef mat<4, 3, f32>	mat4x3;
	typedef mat<2, 4, f32>	mat2x4;
	typedef mat<3, 4, f32>	mat3x4;
	typedef mat<4, 4, f32>	mat4x4;

	typedef mat<2, 2, f32>	fmat2x2;
	typedef mat<3, 2, f32>	fmat3x2;
	typedef mat<4, 2, f32>	fmat4x2;
	typedef mat<2, 3, f32>	fmat2x3;
	typedef mat<3, 3, f32>	fmat3x3;
	typedef mat<4, 3, f32>	fmat4x3;
	typedef mat<2, 4, f32>	fmat2x4;
	typedef mat<3, 4, f32>	fmat3x4;
	typedef mat<4, 4, f32>	fmat4x4;

	typedef mat<2, 2, f32>	f32mat2x2;
	typedef mat<3, 2, f32>	f32mat3x2;
	typedef mat<4, 2, f32>	f32mat4x2;
	typedef mat<2, 3, f32>	f32mat2x3;
	typedef mat<3, 3, f32>	f32mat3x3;
	typedef mat<4, 3, f32>	f32mat4x3;
	typedef mat<2, 4, f32>	f32mat2x4;
	typedef mat<3, 4, f32>	f32mat3x4;
	typedef mat<4, 4, f32>	f32mat4x4;

	typedef mat<2, 2, double>	dmat2x2;
	typedef mat<3, 2, double>	dmat3x2;
	typedef mat<4, 2, double>	dmat4x2;
	typedef mat<2, 3, double>	dmat2x3;
	typedef mat<3, 3, double>	dmat3x3;
	typedef mat<4, 3, double>	dmat4x3;
	typedef mat<2, 4, double>	dmat2x4;
	typedef mat<3, 4, double>	dmat3x4;
	typedef mat<4, 4, double>	dmat4x4;

	typedef mat<2, 2, f64>	f64mat2x2;
	typedef mat<3, 2, f64>	f64mat3x2;
	typedef mat<4, 2, f64>	f64mat4x2;
	typedef mat<2, 3, f64>	f64mat2x3;
	typedef mat<3, 3, f64>	f64mat3x3;
	typedef mat<4, 3, f64>	f64mat4x3;
	typedef mat<2, 4, f64>	f64mat2x4;
	typedef mat<3, 4, f64>	f64mat3x4;
	typedef mat<4, 4, f64>	f64mat4x4;

	// Quaternion

	typedef qua<float>		quat;
	typedef qua<float>		fquat;
	typedef qua<f32>			f32quat;

	typedef qua<double>		dquat;
	typedef qua<f64>			f64quat;
}//namespace glm


