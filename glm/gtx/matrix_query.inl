/// @ref gtx_matrix_query

namespace glm
{
	template<typename T>
	GLM_FUNC_QUALIFIER bool isNull(mat<2, 2, T> const& m, T const& epsilon)
	{
		bool result = true;
		for(length_t i = 0; result && i < m.length() ; ++i)
			result = isNull(m[i], epsilon);
		return result;
	}

	template<typename T>
	GLM_FUNC_QUALIFIER bool isNull(mat<3, 3, T> const& m, T const& epsilon)
	{
		bool result = true;
		for(length_t i = 0; result && i < m.length() ; ++i)
			result = isNull(m[i], epsilon);
		return result;
	}

	template<typename T>
	GLM_FUNC_QUALIFIER bool isNull(mat<4, 4, T> const& m, T const& epsilon)
	{
		bool result = true;
		for(length_t i = 0; result && i < m.length() ; ++i)
			result = isNull(m[i], epsilon);
		return result;
	}

	template<length_t C, length_t R, typename T>
	GLM_FUNC_QUALIFIER bool isIdentity(mat<C, R, T> const& m, T const& epsilon)
	{
		bool result = true;
		for(length_t i = 0; result && i < m[0].length() ; ++i)
		{
			for(length_t j = 0; result && j < i ; ++j)
				result = abs(m[i][j]) <= epsilon;
			if(result)
				result = abs(m[i][i] - 1) <= epsilon;
			for(length_t j = i + 1; result && j < m.length(); ++j)
				result = abs(m[i][j]) <= epsilon;
		}
		return result;
	}

	template<typename T>
	GLM_FUNC_QUALIFIER bool isNormalized(mat<2, 2, T> const& m, T const& epsilon)
	{
		bool result(true);
		for(length_t i = 0; result && i < m.length(); ++i)
			result = isNormalized(m[i], epsilon);
		for(length_t i = 0; result && i < m.length(); ++i)
		{
			typename mat<2, 2, T>::col_type v;
			for(length_t j = 0; j < m.length(); ++j)
				v[j] = m[j][i];
			result = isNormalized(v, epsilon);
		}
		return result;
	}

	template<typename T>
	GLM_FUNC_QUALIFIER bool isNormalized(mat<3, 3, T> const& m, T const& epsilon)
	{
		bool result(true);
		for(length_t i = 0; result && i < m.length(); ++i)
			result = isNormalized(m[i], epsilon);
		for(length_t i = 0; result && i < m.length(); ++i)
		{
			typename mat<3, 3, T>::col_type v;
			for(length_t j = 0; j < m.length(); ++j)
				v[j] = m[j][i];
			result = isNormalized(v, epsilon);
		}
		return result;
	}

	template<typename T>
	GLM_FUNC_QUALIFIER bool isNormalized(mat<4, 4, T> const& m, T const& epsilon)
	{
		bool result(true);
		for(length_t i = 0; result && i < m.length(); ++i)
			result = isNormalized(m[i], epsilon);
		for(length_t i = 0; result && i < m.length(); ++i)
		{
			typename mat<4, 4, T>::col_type v;
			for(length_t j = 0; j < m.length(); ++j)
				v[j] = m[j][i];
			result = isNormalized(v, epsilon);
		}
		return result;
	}

	template<length_t C, length_t R, typename T>
	GLM_FUNC_QUALIFIER bool isOrthogonal(mat<C, R, T> const& m, T const& epsilon)
	{
		bool result = true;
		for(length_t i(0); result && i < m.length() - 1; ++i)
		for(length_t j(i + 1); result && j < m.length(); ++j)
			result = areOrthogonal(m[i], m[j], epsilon);

		if(result)
		{
			mat<C, R, T> tmp = transpose(m);
			for(length_t i(0); result && i < m.length() - 1 ; ++i)
			for(length_t j(i + 1); result && j < m.length(); ++j)
				result = areOrthogonal(tmp[i], tmp[j], epsilon);
		}
		return result;
	}
}//namespace glm
