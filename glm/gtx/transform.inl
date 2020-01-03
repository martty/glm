/// @ref gtx_transform

namespace glm
{
	template<typename T>
	GLM_FUNC_QUALIFIER mat<4, 4, T> translate(vec<3, T> const& v)
	{
		return translate(mat<4, 4, T>(static_cast<T>(1)), v);
	}

	template<typename T>
	GLM_FUNC_QUALIFIER mat<4, 4, T> rotate(T angle, vec<3, T> const& v)
	{
		return rotate(mat<4, 4, T>(static_cast<T>(1)), angle, v);
	}

	template<typename T>
	GLM_FUNC_QUALIFIER mat<4, 4, T> scale(vec<3, T> const& v)
	{
		return scale(mat<4, 4, T>(static_cast<T>(1)), v);
	}

}//namespace glm
