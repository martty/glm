/// @ref gtc_epsilon

// Dependency:
#include "../vector_relational.hpp"
#include "../common.hpp"

namespace glm
{
	template<>
	GLM_FUNC_QUALIFIER bool epsilonEqual
	(
		float const& x,
		float const& y,
		float const& epsilon
	)
	{
		return abs(x - y) < epsilon;
	}

	template<>
	GLM_FUNC_QUALIFIER bool epsilonEqual
	(
		double const& x,
		double const& y,
		double const& epsilon
	)
	{
		return abs(x - y) < epsilon;
	}

	template<length_t L, typename T>
	GLM_FUNC_QUALIFIER vec<L, bool> epsilonEqual(vec<L, T> const& x, vec<L, T> const& y, T const& epsilon)
	{
		return lessThan(abs(x - y), vec<L, T>(epsilon));
	}

	template<length_t L, typename T>
	GLM_FUNC_QUALIFIER vec<L, bool> epsilonEqual(vec<L, T> const& x, vec<L, T> const& y, vec<L, T> const& epsilon)
	{
		return lessThan(abs(x - y), vec<L, T>(epsilon));
	}

	template<>
	GLM_FUNC_QUALIFIER bool epsilonNotEqual(float const& x, float const& y, float const& epsilon)
	{
		return abs(x - y) >= epsilon;
	}

	template<>
	GLM_FUNC_QUALIFIER bool epsilonNotEqual(double const& x, double const& y, double const& epsilon)
	{
		return abs(x - y) >= epsilon;
	}

	template<length_t L, typename T>
	GLM_FUNC_QUALIFIER vec<L, bool> epsilonNotEqual(vec<L, T> const& x, vec<L, T> const& y, T const& epsilon)
	{
		return greaterThanEqual(abs(x - y), vec<L, T>(epsilon));
	}

	template<length_t L, typename T>
	GLM_FUNC_QUALIFIER vec<L, bool> epsilonNotEqual(vec<L, T> const& x, vec<L, T> const& y, vec<L, T> const& epsilon)
	{
		return greaterThanEqual(abs(x - y), vec<L, T>(epsilon));
	}

	template<typename T>
	GLM_FUNC_QUALIFIER vec<4, bool> epsilonEqual(qua<T> const& x, qua<T> const& y, T const& epsilon)
	{
		vec<4, T> v(x.x - y.x, x.y - y.y, x.z - y.z, x.w - y.w);
		return lessThan(abs(v), vec<4, T>(epsilon));
	}

	template<typename T>
	GLM_FUNC_QUALIFIER vec<4, bool> epsilonNotEqual(qua<T> const& x, qua<T> const& y, T const& epsilon)
	{
		vec<4, T> v(x.x - y.x, x.y - y.y, x.z - y.z, x.w - y.w);
		return greaterThanEqual(abs(v), vec<4, T>(epsilon));
	}
}//namespace glm
