/// @ref gtx_extend

namespace glm
{
	template<typename genType>
	GLM_FUNC_QUALIFIER genType extend
	(
		genType const& Origin,
		genType const& Source,
		genType const& Distance
	)
	{
		return Origin + (Source - Origin) * Distance;
	}

	template<typename T>
	GLM_FUNC_QUALIFIER vec<2, T> extend
	(
		vec<2, T> const& Origin,
		vec<2, T> const& Source,
		T const& Distance
	)
	{
		return Origin + (Source - Origin) * Distance;
	}

	template<typename T>
	GLM_FUNC_QUALIFIER vec<3, T> extend
	(
		vec<3, T> const& Origin,
		vec<3, T> const& Source,
		T const& Distance
	)
	{
		return Origin + (Source - Origin) * Distance;
	}

	template<typename T>
	GLM_FUNC_QUALIFIER vec<4, T> extend
	(
		vec<4, T> const& Origin,
		vec<4, T> const& Source,
		T const& Distance
	)
	{
		return Origin + (Source - Origin) * Distance;
	}
}//namespace glm
