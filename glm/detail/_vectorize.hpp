#pragma once

#include "type_vec2.hpp"
#include "type_vec3.hpp"
#include "type_vec4.hpp"

namespace glm{
namespace detail
{
	template<template<length_t L, typename T> class vec, length_t L, typename R, typename T>
	struct functor1{};

	template<template<length_t L, typename T> class vec, typename R, typename T>
	struct functor1<vec, 2, R, T>
	{
		GLM_FUNC_QUALIFIER GLM_CONSTEXPR static vec<2, R> call(R (*Func) (T x), vec<2, T> const& v)
		{
			return vec<2, R>(Func(v.x), Func(v.y));
		}
	};

	template<template<length_t L, typename T> class vec, typename R, typename T>
	struct functor1<vec, 3, R, T>
	{
		GLM_FUNC_QUALIFIER GLM_CONSTEXPR static vec<3, R> call(R (*Func) (T x), vec<3, T> const& v)
		{
			return vec<3, R>(Func(v.x), Func(v.y), Func(v.z));
		}
	};

	template<template<length_t L, typename T> class vec, typename R, typename T>
	struct functor1<vec, 4, R, T>
	{
		GLM_FUNC_QUALIFIER GLM_CONSTEXPR static vec<4, R> call(R (*Func) (T x), vec<4, T> const& v)
		{
			return vec<4, R>(Func(v.x), Func(v.y), Func(v.z), Func(v.w));
		}
	};

	template<template<length_t L, typename T> class vec, length_t L, typename T>
	struct functor2{};


	template<template<length_t L, typename T> class vec, typename T>
	struct functor2<vec, 2, T>
	{
		GLM_FUNC_QUALIFIER static vec<2, T> call(T (*Func) (T x, T y), vec<2, T> const& a, vec<2, T> const& b)
		{
			return vec<2, T>(Func(a.x, b.x), Func(a.y, b.y));
		}
	};

	template<template<length_t L, typename T> class vec, typename T>
	struct functor2<vec, 3, T>
	{
		GLM_FUNC_QUALIFIER static vec<3, T> call(T (*Func) (T x, T y), vec<3, T> const& a, vec<3, T> const& b)
		{
			return vec<3, T>(Func(a.x, b.x), Func(a.y, b.y), Func(a.z, b.z));
		}
	};

	template<template<length_t L, typename T> class vec, typename T>
	struct functor2<vec, 4, T>
	{
		GLM_FUNC_QUALIFIER static vec<4, T> call(T (*Func) (T x, T y), vec<4, T> const& a, vec<4, T> const& b)
		{
			return vec<4, T>(Func(a.x, b.x), Func(a.y, b.y), Func(a.z, b.z), Func(a.w, b.w));
		}
	};

	template<template<length_t L, typename T> class vec, length_t L, typename T>
	struct functor2_vec_sca{};

	template<template<length_t L, typename T> class vec, typename T>
	struct functor2_vec_sca<vec, 1, T>
	{
		GLM_FUNC_QUALIFIER static vec<1, T> call(T (*Func) (T x, T y), vec<1, T> const& a, T b)
		{
			return vec<1, T>(Func(a.x, b));
		}
	};

	template<template<length_t L, typename T> class vec, typename T>
	struct functor2_vec_sca<vec, 2, T>
	{
		GLM_FUNC_QUALIFIER static vec<2, T> call(T (*Func) (T x, T y), vec<2, T> const& a, T b)
		{
			return vec<2, T>(Func(a.x, b), Func(a.y, b));
		}
	};

	template<template<length_t L, typename T> class vec, typename T>
	struct functor2_vec_sca<vec, 3, T>
	{
		GLM_FUNC_QUALIFIER static vec<3, T> call(T (*Func) (T x, T y), vec<3, T> const& a, T b)
		{
			return vec<3, T>(Func(a.x, b), Func(a.y, b), Func(a.z, b));
		}
	};

	template<template<length_t L, typename T> class vec, typename T>
	struct functor2_vec_sca<vec, 4, T>
	{
		GLM_FUNC_QUALIFIER static vec<4, T> call(T (*Func) (T x, T y), vec<4, T> const& a, T b)
		{
			return vec<4, T>(Func(a.x, b), Func(a.y, b), Func(a.z, b), Func(a.w, b));
		}
	};

	template<length_t L, typename T>
	struct functor2_vec_int {};

	template<typename T>
	struct functor2_vec_int<2, T>
	{
		GLM_FUNC_QUALIFIER static vec<2, int> call(int (*Func) (T x, int y), vec<2, T> const& a, vec<2, int> const& b)
		{
			return vec<2, int>(Func(a.x, b.x), Func(a.y, b.y));
		}
	};

	template<typename T>
	struct functor2_vec_int<3, T>
	{
		GLM_FUNC_QUALIFIER static vec<3, int> call(int (*Func) (T x, int y), vec<3, T> const& a, vec<3, int> const& b)
		{
			return vec<3, int>(Func(a.x, b.x), Func(a.y, b.y), Func(a.z, b.z));
		}
	};

	template<typename T>
	struct functor2_vec_int<4, T>
	{
		GLM_FUNC_QUALIFIER static vec<4, int> call(int (*Func) (T x, int y), vec<4, T> const& a, vec<4, int> const& b)
		{
			return vec<4, int>(Func(a.x, b.x), Func(a.y, b.y), Func(a.z, b.z), Func(a.w, b.w));
		}
	};
}//namespace detail
}//namespace glm
