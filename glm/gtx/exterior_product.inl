/// @ref gtx_exterior_product

#include <limits>

namespace glm {
namespace detail
{
	template<typename T, bool Aligned>
	struct compute_cross_vec2
	{
		GLM_FUNC_QUALIFIER static T call(vec<2, T> const& v, vec<2, T> const& u)
		{
			GLM_STATIC_ASSERT(std::numeric_limits<T>::is_iec559, "'cross' accepts only floating-point inputs");

			return v.x * u.y - u.x * v.y;
		}
	};
}//namespace detail

	template<typename T>
	GLM_FUNC_QUALIFIER T cross(vec<2, T> const& x, vec<2, T> const& y)
	{
		return detail::compute_cross_vec2<T, false>::call(x, y);
	}
}//namespace glm

