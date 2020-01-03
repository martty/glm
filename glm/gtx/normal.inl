/// @ref gtx_normal

namespace glm
{
	template<typename T>
	GLM_FUNC_QUALIFIER vec<3, T> triangleNormal
	(
		vec<3, T> const& p1,
		vec<3, T> const& p2,
		vec<3, T> const& p3
	)
	{
		return normalize(cross(p1 - p2, p1 - p3));
	}
}//namespace glm
