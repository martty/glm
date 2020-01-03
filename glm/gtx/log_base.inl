/// @ref gtx_log_base

namespace glm
{
	template<typename genType>
	GLM_FUNC_QUALIFIER genType log(genType const& x, genType const& base)
	{
		return glm::log(x) / glm::log(base);
	}

	template<length_t L, typename T>
	GLM_FUNC_QUALIFIER vec<L, T> log(vec<L, T> const& x, vec<L, T> const& base)
	{
		return glm::log(x) / glm::log(base);
	}
}//namespace glm
