#include "../detail/_vectorize.hpp"

namespace glm
{
	template<length_t L, typename T>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<L, T> min(vec<L, T> const& x, vec<L, T> const& y, vec<L, T> const& z)
	{
		GLM_STATIC_ASSERT(std::numeric_limits<T>::is_iec559, "'min' only accept floating-point or integer inputs");
		return glm::min(glm::min(x, y), z);
	}

	template<length_t L, typename T>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<L, T> min(vec<L, T> const& x, vec<L, T> const& y, vec<L, T> const& z, vec<L, T> const& w)
	{
		GLM_STATIC_ASSERT(std::numeric_limits<T>::is_iec559, "'min' only accept floating-point or integer inputs");
		return glm::min(glm::min(x, y), glm::min(z, w));
	}

	template<length_t L, typename T>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<L, T> max(vec<L, T> const& x, vec<L, T> const& y, vec<L, T> const& z)
	{
		GLM_STATIC_ASSERT(std::numeric_limits<T>::is_iec559, "'max' only accept floating-point or integer inputs");
		return glm::max(glm::max(x, y), z);
	}

	template<length_t L, typename T>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<L, T> max(vec<L, T> const& x, vec<L, T> const& y, vec<L, T> const& z, vec<L, T> const& w)
	{
		GLM_STATIC_ASSERT(std::numeric_limits<T>::is_iec559, "'max' only accept floating-point or integer inputs");
		return glm::max(glm::max(x, y), glm::max(z, w));
	}

	template<length_t L, typename T>
	GLM_FUNC_QUALIFIER vec<L, T> fmin(vec<L, T> const& a, T b)
	{
		GLM_STATIC_ASSERT(std::numeric_limits<T>::is_iec559, "'fmin' only accept floating-point inputs");
		return detail::functor2<vec, L, T>::call(fmin, a, vec<L, T>(b));
	}

	template<length_t L, typename T>
	GLM_FUNC_QUALIFIER vec<L, T> fmin(vec<L, T> const& a, vec<L, T> const& b)
	{
		GLM_STATIC_ASSERT(std::numeric_limits<T>::is_iec559, "'fmin' only accept floating-point inputs");
		return detail::functor2<vec, L, T>::call(fmin, a, b);
	}

	template<length_t L, typename T>
	GLM_FUNC_QUALIFIER vec<L, T> fmin(vec<L, T> const& a, vec<L, T> const& b, vec<L, T> const& c)
	{
		GLM_STATIC_ASSERT(std::numeric_limits<T>::is_iec559, "'fmin' only accept floating-point inputs");
		return fmin(fmin(a, b), c);
	}

	template<length_t L, typename T>
	GLM_FUNC_QUALIFIER vec<L, T> fmin(vec<L, T> const& a, vec<L, T> const& b, vec<L, T> const& c, vec<L, T> const& d)
	{
		GLM_STATIC_ASSERT(std::numeric_limits<T>::is_iec559, "'fmin' only accept floating-point inputs");
		return fmin(fmin(a, b), fmin(c, d));
	}

	template<length_t L, typename T>
	GLM_FUNC_QUALIFIER vec<L, T> fmax(vec<L, T> const& a, T b)
	{
		GLM_STATIC_ASSERT(std::numeric_limits<T>::is_iec559, "'fmax' only accept floating-point inputs");
		return detail::functor2<vec, L, T>::call(fmax, a, vec<L, T>(b));
	}

	template<length_t L, typename T>
	GLM_FUNC_QUALIFIER vec<L, T> fmax(vec<L, T> const& a, vec<L, T> const& b)
	{
		GLM_STATIC_ASSERT(std::numeric_limits<T>::is_iec559, "'fmax' only accept floating-point inputs");
		return detail::functor2<vec, L, T>::call(fmax, a, b);
	}

	template<length_t L, typename T>
	GLM_FUNC_QUALIFIER vec<L, T> fmax(vec<L, T> const& a, vec<L, T> const& b, vec<L, T> const& c)
	{
		GLM_STATIC_ASSERT(std::numeric_limits<T>::is_iec559, "'fmax' only accept floating-point inputs");
		return fmax(fmax(a, b), c);
	}

	template<length_t L, typename T>
	GLM_FUNC_QUALIFIER vec<L, T> fmax(vec<L, T> const& a, vec<L, T> const& b, vec<L, T> const& c, vec<L, T> const& d)
	{
		GLM_STATIC_ASSERT(std::numeric_limits<T>::is_iec559, "'fmax' only accept floating-point inputs");
		return fmax(fmax(a, b), fmax(c, d));
	}
}//namespace glm
