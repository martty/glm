#include "scalar_integer.hpp"

namespace glm
{
	template<length_t L, typename T>
	GLM_FUNC_QUALIFIER vec<L, bool> isPowerOfTwo(vec<L, T> const& Value)
	{
		GLM_STATIC_ASSERT(std::numeric_limits<T>::is_integer, "'isPowerOfTwo' only accept integer inputs");

		vec<L, T> const Result(abs(Value));
		return equal(Result & (Result - vec<L, T>(1)), vec<L, T>(0));
	}

	template<length_t L, typename T>
	GLM_FUNC_QUALIFIER vec<L, T> nextPowerOfTwo(vec<L, T> const& v)
	{
		GLM_STATIC_ASSERT(std::numeric_limits<T>::is_integer, "'nextPowerOfTwo' only accept integer inputs");

		return detail::compute_ceilPowerOfTwo<L, T, std::numeric_limits<T>::is_signed>::call(v);
	}

	template<length_t L, typename T>
	GLM_FUNC_QUALIFIER vec<L, T> prevPowerOfTwo(vec<L, T> const& v)
	{
		GLM_STATIC_ASSERT(std::numeric_limits<T>::is_integer, "'prevPowerOfTwo' only accept integer inputs");

		return detail::functor1<vec, L, T, T>::call(prevPowerOfTwo, v);
	}

	template<length_t L, typename T>
	GLM_FUNC_QUALIFIER vec<L, bool> isMultiple(vec<L, T> const& Value, T Multiple)
	{
		GLM_STATIC_ASSERT(std::numeric_limits<T>::is_integer, "'isMultiple' only accept integer inputs");

		return (Value % Multiple) == vec<L, T>(0);
	}

	template<length_t L, typename T>
	GLM_FUNC_QUALIFIER vec<L, bool> isMultiple(vec<L, T> const& Value, vec<L, T> const& Multiple)
	{
		GLM_STATIC_ASSERT(std::numeric_limits<T>::is_integer, "'isMultiple' only accept integer inputs");

		return (Value % Multiple) == vec<L, T>(0);
	}

	template<length_t L, typename T>
	GLM_FUNC_QUALIFIER vec<L, T> nextMultiple(vec<L, T> const& Source, T Multiple)
	{
		GLM_STATIC_ASSERT(std::numeric_limits<T>::is_integer, "'nextMultiple' only accept integer inputs");

		return detail::functor2<vec, L, T>::call(nextMultiple, Source, vec<L, T>(Multiple));
	}

	template<length_t L, typename T>
	GLM_FUNC_QUALIFIER vec<L, T> nextMultiple(vec<L, T> const& Source, vec<L, T> const& Multiple)
	{
		GLM_STATIC_ASSERT(std::numeric_limits<T>::is_integer, "'nextMultiple' only accept integer inputs");

		return detail::functor2<vec, L, T>::call(nextMultiple, Source, Multiple);
	}

	template<length_t L, typename T>
	GLM_FUNC_QUALIFIER vec<L, T> prevMultiple(vec<L, T> const& Source, T Multiple)
	{
		GLM_STATIC_ASSERT(std::numeric_limits<T>::is_integer, "'prevMultiple' only accept integer inputs");

		return detail::functor2<vec, L, T>::call(prevMultiple, Source, vec<L, T>(Multiple));
	}

	template<length_t L, typename T>
	GLM_FUNC_QUALIFIER vec<L, T> prevMultiple(vec<L, T> const& Source, vec<L, T> const& Multiple)
	{
		GLM_STATIC_ASSERT(std::numeric_limits<T>::is_integer, "'prevMultiple' only accept integer inputs");

		return detail::functor2<vec, L, T>::call(prevMultiple, Source, Multiple);
	}

	template<length_t L, typename T>
	GLM_FUNC_QUALIFIER vec<L, int> findNSB(vec<L, T> const& Source, vec<L, int> SignificantBitCount)
	{
		GLM_STATIC_ASSERT(std::numeric_limits<T>::is_integer, "'findNSB' only accept integer inputs");

		return detail::functor2_vec_int<L, T>::call(findNSB, Source, SignificantBitCount);
	}
}//namespace glm
