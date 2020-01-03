/// @ref gtx_float_normalize

#include <limits>

namespace glm
{
	template<length_t L, typename T>
	GLM_FUNC_QUALIFIER vec<L, float> floatNormalize(vec<L, T> const& v)
	{
		return vec<L, float>(v) / static_cast<float>(std::numeric_limits<T>::max());
	}

}//namespace glm
