/// @ref gtc_reciprocal

#include "../trigonometric.hpp"
#include <limits>

namespace glm
{
	// sec
	template<typename genType>
	GLM_FUNC_QUALIFIER genType sec(genType angle)
	{
		GLM_STATIC_ASSERT(std::numeric_limits<genType>::is_iec559, "'sec' only accept floating-point values");
		return genType(1) / glm::cos(angle);
	}

	template<length_t L, typename T>
	GLM_FUNC_QUALIFIER vec<L, T> sec(vec<L, T> const& x)
	{
		GLM_STATIC_ASSERT(std::numeric_limits<T>::is_iec559, "'sec' only accept floating-point inputs");
		return detail::functor1<vec, L, T, T>::call(sec, x);
	}

	// csc
	template<typename genType>
	GLM_FUNC_QUALIFIER genType csc(genType angle)
	{
		GLM_STATIC_ASSERT(std::numeric_limits<genType>::is_iec559, "'csc' only accept floating-point values");
		return genType(1) / glm::sin(angle);
	}

	template<length_t L, typename T>
	GLM_FUNC_QUALIFIER vec<L, T> csc(vec<L, T> const& x)
	{
		GLM_STATIC_ASSERT(std::numeric_limits<T>::is_iec559, "'csc' only accept floating-point inputs");
		return detail::functor1<vec, L, T, T>::call(csc, x);
	}

	// cot
	template<typename genType>
	GLM_FUNC_QUALIFIER genType cot(genType angle)
	{
		GLM_STATIC_ASSERT(std::numeric_limits<genType>::is_iec559, "'cot' only accept floating-point values");

		genType const pi_over_2 = genType(3.1415926535897932384626433832795 / 2.0);
		return glm::tan(pi_over_2 - angle);
	}

	template<length_t L, typename T>
	GLM_FUNC_QUALIFIER vec<L, T> cot(vec<L, T> const& x)
	{
		GLM_STATIC_ASSERT(std::numeric_limits<T>::is_iec559, "'cot' only accept floating-point inputs");
		return detail::functor1<vec, L, T, T>::call(cot, x);
	}

	// asec
	template<typename genType>
	GLM_FUNC_QUALIFIER genType asec(genType x)
	{
		GLM_STATIC_ASSERT(std::numeric_limits<genType>::is_iec559, "'asec' only accept floating-point values");
		return acos(genType(1) / x);
	}

	template<length_t L, typename T>
	GLM_FUNC_QUALIFIER vec<L, T> asec(vec<L, T> const& x)
	{
		GLM_STATIC_ASSERT(std::numeric_limits<T>::is_iec559, "'asec' only accept floating-point inputs");
		return detail::functor1<vec, L, T, T>::call(asec, x);
	}

	// acsc
	template<typename genType>
	GLM_FUNC_QUALIFIER genType acsc(genType x)
	{
		GLM_STATIC_ASSERT(std::numeric_limits<genType>::is_iec559, "'acsc' only accept floating-point values");
		return asin(genType(1) / x);
	}

	template<length_t L, typename T>
	GLM_FUNC_QUALIFIER vec<L, T> acsc(vec<L, T> const& x)
	{
		GLM_STATIC_ASSERT(std::numeric_limits<T>::is_iec559, "'acsc' only accept floating-point inputs");
		return detail::functor1<vec, L, T, T>::call(acsc, x);
	}

	// acot
	template<typename genType>
	GLM_FUNC_QUALIFIER genType acot(genType x)
	{
		GLM_STATIC_ASSERT(std::numeric_limits<genType>::is_iec559, "'acot' only accept floating-point values");

		genType const pi_over_2 = genType(3.1415926535897932384626433832795 / 2.0);
		return pi_over_2 - atan(x);
	}

	template<length_t L, typename T>
	GLM_FUNC_QUALIFIER vec<L, T> acot(vec<L, T> const& x)
	{
		GLM_STATIC_ASSERT(std::numeric_limits<T>::is_iec559, "'acot' only accept floating-point inputs");
		return detail::functor1<vec, L, T, T>::call(acot, x);
	}

	// sech
	template<typename genType>
	GLM_FUNC_QUALIFIER genType sech(genType angle)
	{
		GLM_STATIC_ASSERT(std::numeric_limits<genType>::is_iec559, "'sech' only accept floating-point values");
		return genType(1) / glm::cosh(angle);
	}

	template<length_t L, typename T>
	GLM_FUNC_QUALIFIER vec<L, T> sech(vec<L, T> const& x)
	{
		GLM_STATIC_ASSERT(std::numeric_limits<T>::is_iec559, "'sech' only accept floating-point inputs");
		return detail::functor1<vec, L, T, T>::call(sech, x);
	}

	// csch
	template<typename genType>
	GLM_FUNC_QUALIFIER genType csch(genType angle)
	{
		GLM_STATIC_ASSERT(std::numeric_limits<genType>::is_iec559, "'csch' only accept floating-point values");
		return genType(1) / glm::sinh(angle);
	}

	template<length_t L, typename T>
	GLM_FUNC_QUALIFIER vec<L, T> csch(vec<L, T> const& x)
	{
		GLM_STATIC_ASSERT(std::numeric_limits<T>::is_iec559, "'csch' only accept floating-point inputs");
		return detail::functor1<vec, L, T, T>::call(csch, x);
	}

	// coth
	template<typename genType>
	GLM_FUNC_QUALIFIER genType coth(genType angle)
	{
		GLM_STATIC_ASSERT(std::numeric_limits<genType>::is_iec559, "'coth' only accept floating-point values");
		return glm::cosh(angle) / glm::sinh(angle);
	}

	template<length_t L, typename T>
	GLM_FUNC_QUALIFIER vec<L, T> coth(vec<L, T> const& x)
	{
		GLM_STATIC_ASSERT(std::numeric_limits<T>::is_iec559, "'coth' only accept floating-point inputs");
		return detail::functor1<vec, L, T, T>::call(coth, x);
	}

	// asech
	template<typename genType>
	GLM_FUNC_QUALIFIER genType asech(genType x)
	{
		GLM_STATIC_ASSERT(std::numeric_limits<genType>::is_iec559, "'asech' only accept floating-point values");
		return acosh(genType(1) / x);
	}

	template<length_t L, typename T>
	GLM_FUNC_QUALIFIER vec<L, T> asech(vec<L, T> const& x)
	{
		GLM_STATIC_ASSERT(std::numeric_limits<T>::is_iec559, "'asech' only accept floating-point inputs");
		return detail::functor1<vec, L, T, T>::call(asech, x);
	}

	// acsch
	template<typename genType>
	GLM_FUNC_QUALIFIER genType acsch(genType x)
	{
		GLM_STATIC_ASSERT(std::numeric_limits<genType>::is_iec559, "'acsch' only accept floating-point values");
		return asinh(genType(1) / x);
	}

	template<length_t L, typename T>
	GLM_FUNC_QUALIFIER vec<L, T> acsch(vec<L, T> const& x)
	{
		GLM_STATIC_ASSERT(std::numeric_limits<T>::is_iec559, "'acsch' only accept floating-point inputs");
		return detail::functor1<vec, L, T, T>::call(acsch, x);
	}

	// acoth
	template<typename genType>
	GLM_FUNC_QUALIFIER genType acoth(genType x)
	{
		GLM_STATIC_ASSERT(std::numeric_limits<genType>::is_iec559, "'acoth' only accept floating-point values");
		return atanh(genType(1) / x);
	}

	template<length_t L, typename T>
	GLM_FUNC_QUALIFIER vec<L, T> acoth(vec<L, T> const& x)
	{
		GLM_STATIC_ASSERT(std::numeric_limits<T>::is_iec559, "'acoth' only accept floating-point inputs");
		return detail::functor1<vec, L, T, T>::call(acoth, x);
	}
}//namespace glm
