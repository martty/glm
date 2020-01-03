#include "../matrix.hpp"

namespace glm
{
	template<length_t C, length_t R, typename T, typename U>
	GLM_FUNC_QUALIFIER mat<C, R, T> mix(mat<C, R, T> const& x, mat<C, R, T> const& y, U a)
	{
		return mat<C, R, U>(x) * (static_cast<U>(1) - a) + mat<C, R, U>(y) * a;
	}

	template<length_t C, length_t R, typename T, typename U>
	GLM_FUNC_QUALIFIER mat<C, R, T> mix(mat<C, R, T> const& x, mat<C, R, T> const& y, mat<C, R, U> const& a)
	{
		return matrixCompMult(mat<C, R, U>(x), static_cast<U>(1) - a) + matrixCompMult(mat<C, R, U>(y), a);
	}
}//namespace glm
