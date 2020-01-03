#pragma once

#include "../common.hpp"

namespace glm{
namespace detail
{
	template<typename T>
	GLM_FUNC_QUALIFIER T mod289(T const& x)
	{
		return x - floor(x * (static_cast<T>(1.0) / static_cast<T>(289.0))) * static_cast<T>(289.0);
	}

	template<typename T>
	GLM_FUNC_QUALIFIER T permute(T const& x)
	{
		return mod289(((x * static_cast<T>(34)) + static_cast<T>(1)) * x);
	}

	template<typename T>
	GLM_FUNC_QUALIFIER vec<2, T> permute(vec<2, T> const& x)
	{
		return mod289(((x * static_cast<T>(34)) + static_cast<T>(1)) * x);
	}

	template<typename T>
	GLM_FUNC_QUALIFIER vec<3, T> permute(vec<3, T> const& x)
	{
		return mod289(((x * static_cast<T>(34)) + static_cast<T>(1)) * x);
	}

	template<typename T>
	GLM_FUNC_QUALIFIER vec<4, T> permute(vec<4, T> const& x)
	{
		return mod289(((x * static_cast<T>(34)) + static_cast<T>(1)) * x);
	}

	template<typename T>
	GLM_FUNC_QUALIFIER T taylorInvSqrt(T const& r)
	{
		return static_cast<T>(1.79284291400159) - static_cast<T>(0.85373472095314) * r;
	}

	template<typename T>
	GLM_FUNC_QUALIFIER vec<2, T> taylorInvSqrt(vec<2, T> const& r)
	{
		return static_cast<T>(1.79284291400159) - static_cast<T>(0.85373472095314) * r;
	}

	template<typename T>
	GLM_FUNC_QUALIFIER vec<3, T> taylorInvSqrt(vec<3, T> const& r)
	{
		return static_cast<T>(1.79284291400159) - static_cast<T>(0.85373472095314) * r;
	}

	template<typename T>
	GLM_FUNC_QUALIFIER vec<4, T> taylorInvSqrt(vec<4, T> const& r)
	{
		return static_cast<T>(1.79284291400159) - static_cast<T>(0.85373472095314) * r;
	}

	template<typename T>
	GLM_FUNC_QUALIFIER vec<2, T> fade(vec<2, T> const& t)
	{
		return (t * t * t) * (t * (t * static_cast<T>(6) - static_cast<T>(15)) + static_cast<T>(10));
	}

	template<typename T>
	GLM_FUNC_QUALIFIER vec<3, T> fade(vec<3, T> const& t)
	{
		return (t * t * t) * (t * (t * static_cast<T>(6) - static_cast<T>(15)) + static_cast<T>(10));
	}

	template<typename T>
	GLM_FUNC_QUALIFIER vec<4, T> fade(vec<4, T> const& t)
	{
		return (t * t * t) * (t * (t * static_cast<T>(6) - static_cast<T>(15)) + static_cast<T>(10));
	}
}//namespace detail
}//namespace glm

