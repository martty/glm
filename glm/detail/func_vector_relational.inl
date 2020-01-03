namespace glm
{
	template<length_t L, typename T>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<L, bool> lessThan(vec<L, T> const& x, vec<L, T> const& y)
	{
		vec<L, bool> Result(true);
		for(length_t i = 0; i < L; ++i)
			Result[i] = x[i] < y[i];
		return Result;
	}

	template<length_t L, typename T>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<L, bool> lessThanEqual(vec<L, T> const& x, vec<L, T> const& y)
	{
		vec<L, bool> Result(true);
		for(length_t i = 0; i < L; ++i)
			Result[i] = x[i] <= y[i];
		return Result;
	}

	template<length_t L, typename T>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<L, bool> greaterThan(vec<L, T> const& x, vec<L, T> const& y)
	{
		vec<L, bool> Result(true);
		for(length_t i = 0; i < L; ++i)
			Result[i] = x[i] > y[i];
		return Result;
	}

	template<length_t L, typename T>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<L, bool> greaterThanEqual(vec<L, T> const& x, vec<L, T> const& y)
	{
		vec<L, bool> Result(true);
		for(length_t i = 0; i < L; ++i)
			Result[i] = x[i] >= y[i];
		return Result;
	}

	template<length_t L, typename T>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<L, bool> equal(vec<L, T> const& x, vec<L, T> const& y)
	{
		vec<L, bool> Result(true);
		for(length_t i = 0; i < L; ++i)
			Result[i] = x[i] == y[i];
		return Result;
	}

	template<length_t L, typename T>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<L, bool> notEqual(vec<L, T> const& x, vec<L, T> const& y)
	{
		vec<L, bool> Result(true);
		for(length_t i = 0; i < L; ++i)
			Result[i] = x[i] != y[i];
		return Result;
	}

	template<length_t L>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR bool any(vec<L, bool> const& v)
	{
		bool Result = false;
		for(length_t i = 0; i < L; ++i)
			Result = Result || v[i];
		return Result;
	}

	template<length_t L>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR bool all(vec<L, bool> const& v)
	{
		bool Result = true;
		for(length_t i = 0; i < L; ++i)
			Result = Result && v[i];
		return Result;
	}

	template<length_t L>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<L, bool> not_(vec<L, bool> const& v)
	{
		vec<L, bool> Result(true);
		for(length_t i = 0; i < L; ++i)
			Result[i] = !v[i];
		return Result;
	}
}//namespace glm

#if GLM_CONFIG_SIMD == GLM_ENABLE
#	include "func_vector_relational_simd.inl"
#endif
