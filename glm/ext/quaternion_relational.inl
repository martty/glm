namespace glm
{
	template<typename T>
	GLM_FUNC_QUALIFIER vec<4, bool> equal(qua<T> const& x, qua<T> const& y)
	{
		vec<4, bool> Result;
		for(length_t i = 0; i < x.length(); ++i)
			Result[i] = x[i] == y[i];
		return Result;
	}

	template<typename T>
	GLM_FUNC_QUALIFIER vec<4, bool> equal(qua<T> const& x, qua<T> const& y, T epsilon)
	{
		vec<4, T> v(x.x - y.x, x.y - y.y, x.z - y.z, x.w - y.w);
		return lessThan(abs(v), vec<4, T>(epsilon));
	}

	template<typename T>
	GLM_FUNC_QUALIFIER vec<4, bool> notEqual(qua<T> const& x, qua<T> const& y)
	{
		vec<4, bool> Result;
		for(length_t i = 0; i < x.length(); ++i)
			Result[i] = x[i] != y[i];
		return Result;
	}

	template<typename T>
	GLM_FUNC_QUALIFIER vec<4, bool> notEqual(qua<T> const& x, qua<T> const& y, T epsilon)
	{
		vec<4, T> v(x.x - y.x, x.y - y.y, x.z - y.z, x.w - y.w);
		return greaterThanEqual(abs(v), vec<4, T>(epsilon));
	}
}//namespace glm

