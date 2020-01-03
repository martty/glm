/// @ref gtx_wrap

namespace glm
{
	template<length_t L, typename T>
	GLM_FUNC_QUALIFIER vec<L, T> clamp(vec<L, T> const& Texcoord)
	{
		return glm::clamp(Texcoord, vec<L, T>(0), vec<L, T>(1));
	}

	template<typename genType>
	GLM_FUNC_QUALIFIER genType clamp(genType const& Texcoord)
	{
		return clamp(vec<1, genType>(Texcoord)).x;
	}

	template<length_t L, typename T>
	GLM_FUNC_QUALIFIER vec<L, T> repeat(vec<L, T> const& Texcoord)
	{
		return glm::fract(Texcoord);
	}

	template<typename genType>
	GLM_FUNC_QUALIFIER genType repeat(genType const& Texcoord)
	{
		return repeat(vec<1, genType>(Texcoord)).x;
	}

	template<length_t L, typename T>
	GLM_FUNC_QUALIFIER vec<L, T> mirrorClamp(vec<L, T> const& Texcoord)
	{
		return glm::fract(glm::abs(Texcoord));
	}

	template<typename genType>
	GLM_FUNC_QUALIFIER genType mirrorClamp(genType const& Texcoord)
	{
		return mirrorClamp(vec<1, genType>(Texcoord)).x;
	}

	template<length_t L, typename T>
	GLM_FUNC_QUALIFIER vec<L, T> mirrorRepeat(vec<L, T> const& Texcoord)
	{
		vec<L, T> const Abs = glm::abs(Texcoord);
		vec<L, T> const Clamp = glm::mod(glm::floor(Abs), vec<L, T>(2));
		vec<L, T> const Floor = glm::floor(Abs);
		vec<L, T> const Rest = Abs - Floor;
		vec<L, T> const Mirror = Clamp + Rest;
		return mix(Rest, vec<L, T>(1) - Rest, glm::greaterThanEqual(Mirror, vec<L, T>(1)));
	}

	template<typename genType>
	GLM_FUNC_QUALIFIER genType mirrorRepeat(genType const& Texcoord)
	{
		return mirrorRepeat(vec<1, genType>(Texcoord)).x;
	}
}//namespace glm
