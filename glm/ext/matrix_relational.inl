/// @ref ext_vector_relational
/// @file glm/ext/vector_relational.inl

// Dependency:
#include "../ext/vector_relational.hpp"
#include "../common.hpp"

namespace glm
{
	template<length_t C, length_t R, typename T>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<C, bool> equal(mat<C, R, T> const& a, mat<C, R, T> const& b)
	{
		return equal(a, b, static_cast<T>(0));
	}

	template<length_t C, length_t R, typename T>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<C, bool> equal(mat<C, R, T> const& a, mat<C, R, T> const& b, T Epsilon)
	{
		return equal(a, b, vec<C, T>(Epsilon));
	}

	template<length_t C, length_t R, typename T>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<C, bool> equal(mat<C, R, T> const& a, mat<C, R, T> const& b, vec<C, T> const& Epsilon)
	{
		vec<C, bool> Result(true);
		for(length_t i = 0; i < C; ++i)
			Result[i] = all(equal(a[i], b[i], Epsilon[i]));
		return Result;
	}

	template<length_t C, length_t R, typename T>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<C, bool> notEqual(mat<C, R, T> const& x, mat<C, R, T> const& y)
	{
		return notEqual(x, y, static_cast<T>(0));
	}

	template<length_t C, length_t R, typename T>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<C, bool> notEqual(mat<C, R, T> const& x, mat<C, R, T> const& y, T Epsilon)
	{
		return notEqual(x, y, vec<C, T>(Epsilon));
	}

	template<length_t C, length_t R, typename T>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<C, bool> notEqual(mat<C, R, T> const& a, mat<C, R, T> const& b, vec<C, T> const& Epsilon)
	{
		vec<C, bool> Result(true);
		for(length_t i = 0; i < C; ++i)
			Result[i] = any(notEqual(a[i], b[i], Epsilon[i]));
		return Result;
	}

	template<length_t C, length_t R, typename T>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<C, bool> equal(mat<C, R, T> const& a, mat<C, R, T> const& b, int MaxULPs)
	{
		return equal(a, b, vec<C, int>(MaxULPs));
	}

	template<length_t C, length_t R, typename T>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<C, bool> equal(mat<C, R, T> const& a, mat<C, R, T> const& b, vec<C, int> const& MaxULPs)
	{
		vec<C, bool> Result(true);
		for(length_t i = 0; i < C; ++i)
			Result[i] = all(equal(a[i], b[i], MaxULPs[i]));
		return Result;
	}

	template<length_t C, length_t R, typename T>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<C, bool> notEqual(mat<C, R, T> const& x, mat<C, R, T> const& y, int MaxULPs)
	{
		return notEqual(x, y, vec<C, int>(MaxULPs));
	}

	template<length_t C, length_t R, typename T>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<C, bool> notEqual(mat<C, R, T> const& a, mat<C, R, T> const& b, vec<C, int> const& MaxULPs)
	{
		vec<C, bool> Result(true);
		for(length_t i = 0; i < C; ++i)
			Result[i] = any(notEqual(a[i], b[i], MaxULPs[i]));
		return Result;
	}

}//namespace glm
