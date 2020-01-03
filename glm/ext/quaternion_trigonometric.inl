#include "scalar_constants.hpp"

namespace glm
{
	template<typename T>
	GLM_FUNC_QUALIFIER T angle(qua<T> const& x)
	{
		if (abs(x.w) > cos_one_over_two<T>())
		{
			return asin(sqrt(x.x * x.x + x.y * x.y + x.z * x.z)) * static_cast<T>(2);
		}

		return acos(x.w) * static_cast<T>(2);
	}

	template<typename T>
	GLM_FUNC_QUALIFIER vec<3, T> axis(qua<T> const& x)
	{
		T const tmp1 = static_cast<T>(1) - x.w * x.w;
		if(tmp1 <= static_cast<T>(0))
			return vec<3, T>(0, 0, 1);
		T const tmp2 = static_cast<T>(1) / sqrt(tmp1);
		return vec<3, T>(x.x * tmp2, x.y * tmp2, x.z * tmp2);
	}

	template<typename T>
	GLM_FUNC_QUALIFIER qua<T> angleAxis(T const& angle, vec<3, T> const& v)
	{
		T const a(angle);
		T const s = glm::sin(a * static_cast<T>(0.5));

		return qua<T>(glm::cos(a * static_cast<T>(0.5)), v * s);
	}
}//namespace glm
