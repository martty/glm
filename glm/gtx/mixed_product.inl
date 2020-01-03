/// @ref gtx_mixed_product

namespace glm
{
	template<typename T>
	GLM_FUNC_QUALIFIER T mixedProduct
	(
		vec<3, T> const& v1,
		vec<3, T> const& v2,
		vec<3, T> const& v3
	)
	{
		return dot(cross(v1, v2), v3);
	}
}//namespace glm
