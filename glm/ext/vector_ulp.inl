namespace glm
{
	template<length_t L, typename T>
	GLM_FUNC_QUALIFIER vec<L, T> nextFloat(vec<L, T> const& x)
	{
		vec<L, T> Result;
		for(length_t i = 0, n = Result.length(); i < n; ++i)
			Result[i] = nextFloat(x[i]);
		return Result;
	}

	template<length_t L, typename T>
	GLM_FUNC_QUALIFIER vec<L, T> nextFloat(vec<L, T> const& x, int ULPs)
	{
		vec<L, T> Result;
		for(length_t i = 0, n = Result.length(); i < n; ++i)
			Result[i] = nextFloat(x[i], ULPs);
		return Result;
	}

	template<length_t L, typename T>
	GLM_FUNC_QUALIFIER vec<L, T> nextFloat(vec<L, T> const& x, vec<L, int> const& ULPs)
	{
		vec<L, T> Result;
		for(length_t i = 0, n = Result.length(); i < n; ++i)
			Result[i] = nextFloat(x[i], ULPs[i]);
		return Result;
	}

	template<length_t L, typename T>
	GLM_FUNC_QUALIFIER vec<L, T> prevFloat(vec<L, T> const& x)
	{
		vec<L, T> Result;
		for(length_t i = 0, n = Result.length(); i < n; ++i)
			Result[i] = prevFloat(x[i]);
		return Result;
	}

	template<length_t L, typename T>
	GLM_FUNC_QUALIFIER vec<L, T> prevFloat(vec<L, T> const& x, int ULPs)
	{
		vec<L, T> Result;
		for(length_t i = 0, n = Result.length(); i < n; ++i)
			Result[i] = prevFloat(x[i], ULPs);
		return Result;
	}

	template<length_t L, typename T>
	GLM_FUNC_QUALIFIER vec<L, T> prevFloat(vec<L, T> const& x, vec<L, int> const& ULPs)
	{
		vec<L, T> Result;
		for(length_t i = 0, n = Result.length(); i < n; ++i)
			Result[i] = prevFloat(x[i], ULPs[i]);
		return Result;
	}

	template<length_t L>
	GLM_FUNC_QUALIFIER vec<L, int> floatDistance(vec<L, float> const& x, vec<L, float> const& y)
	{
		vec<L, int> Result;
		for(length_t i = 0, n = Result.length(); i < n; ++i)
			Result[i] = floatDistance(x[i], y[i]);
		return Result;
	}

	template<length_t L>
	GLM_FUNC_QUALIFIER vec<L, int64> floatDistance(vec<L, double> const& x, vec<L, double> const& y)
	{
		vec<L, int64> Result;
		for(length_t i = 0, n = Result.length(); i < n; ++i)
			Result[i] = floatDistance(x[i], y[i]);
		return Result;
	}
}//namespace glm
