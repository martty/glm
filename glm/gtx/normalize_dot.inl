/// @ref gtx_normalize_dot

namespace glm
{
	template<length_t L, typename T>
	GLM_FUNC_QUALIFIER T normalizeDot(vec<L, T> const& x, vec<L, T> const& y)
	{
		return glm::dot(x, y) * glm::inversesqrt(glm::dot(x, x) * glm::dot(y, y));
	}

	template<length_t L, typename T>
	GLM_FUNC_QUALIFIER T fastNormalizeDot(vec<L, T> const& x, vec<L, T> const& y)
	{
		return glm::dot(x, y) * glm::fastInverseSqrt(glm::dot(x, x) * glm::dot(y, y));
	}
}//namespace glm
