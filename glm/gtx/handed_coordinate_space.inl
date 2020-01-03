/// @ref gtx_handed_coordinate_space

namespace glm
{
	template<typename T>
	GLM_FUNC_QUALIFIER bool rightHanded
	(
		vec<3, T> const& tangent,
		vec<3, T> const& binormal,
		vec<3, T> const& normal
	)
	{
		return dot(cross(normal, tangent), binormal) > T(0);
	}

	template<typename T>
	GLM_FUNC_QUALIFIER bool leftHanded
	(
		vec<3, T> const& tangent,
		vec<3, T> const& binormal,
		vec<3, T> const& normal
	)
	{
		return dot(cross(normal, tangent), binormal) < T(0);
	}
}//namespace glm
