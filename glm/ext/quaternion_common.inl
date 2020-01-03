namespace glm
{
	template<typename T>
	GLM_FUNC_QUALIFIER qua<T> mix(qua<T> const& x, qua<T> const& y, T a)
	{
		GLM_STATIC_ASSERT(std::numeric_limits<T>::is_iec559, "'mix' only accept floating-point inputs");

		T const cosTheta = dot(x, y);

		// Perform a linear interpolation when cosTheta is close to 1 to avoid side effect of sin(angle) becoming a zero denominator
		if(cosTheta > static_cast<T>(1) - epsilon<T>())
		{
			// Linear interpolation
			return qua<T>(
				mix(x.w, y.w, a),
				mix(x.x, y.x, a),
				mix(x.y, y.y, a),
				mix(x.z, y.z, a));
		}
		else
		{
			// Essential Mathematics, page 467
			T angle = acos(cosTheta);
			return (sin((static_cast<T>(1) - a) * angle) * x + sin(a * angle) * y) / sin(angle);
		}
	}

	template<typename T>
	GLM_FUNC_QUALIFIER qua<T> lerp(qua<T> const& x, qua<T> const& y, T a)
	{
		GLM_STATIC_ASSERT(std::numeric_limits<T>::is_iec559, "'lerp' only accept floating-point inputs");

		// Lerp is only defined in [0, 1]
		assert(a >= static_cast<T>(0));
		assert(a <= static_cast<T>(1));

		return x * (static_cast<T>(1) - a) + (y * a);
	}

	template<typename T>
	GLM_FUNC_QUALIFIER qua<T> slerp(qua<T> const& x, qua<T> const& y, T a)
	{
		GLM_STATIC_ASSERT(std::numeric_limits<T>::is_iec559, "'slerp' only accept floating-point inputs");

		qua<T> z = y;

		T cosTheta = dot(x, y);

		// If cosTheta < 0, the interpolation will take the long way around the sphere.
		// To fix this, one quat must be negated.
		if(cosTheta < static_cast<T>(0))
		{
			z = -y;
			cosTheta = -cosTheta;
		}

		// Perform a linear interpolation when cosTheta is close to 1 to avoid side effect of sin(angle) becoming a zero denominator
		if(cosTheta > static_cast<T>(1) - epsilon<T>())
		{
			// Linear interpolation
			return qua<T>(
				mix(x.w, z.w, a),
				mix(x.x, z.x, a),
				mix(x.y, z.y, a),
				mix(x.z, z.z, a));
		}
		else
		{
			// Essential Mathematics, page 467
			T angle = acos(cosTheta);
			return (sin((static_cast<T>(1) - a) * angle) * x + sin(a * angle) * z) / sin(angle);
		}
	}

	template<typename T>
	GLM_FUNC_QUALIFIER qua<T> conjugate(qua<T> const& q)
	{
		return qua<T>(q.w, -q.x, -q.y, -q.z);
	}

	template<typename T>
	GLM_FUNC_QUALIFIER qua<T> inverse(qua<T> const& q)
	{
		return conjugate(q) / dot(q, q);
	}

	template<typename T>
	GLM_FUNC_QUALIFIER vec<4, bool> isnan(qua<T> const& q)
	{
		GLM_STATIC_ASSERT(std::numeric_limits<T>::is_iec559, "'isnan' only accept floating-point inputs");

		return vec<4, bool>(isnan(q.x), isnan(q.y), isnan(q.z), isnan(q.w));
	}

	template<typename T>
	GLM_FUNC_QUALIFIER vec<4, bool> isinf(qua<T> const& q)
	{
		GLM_STATIC_ASSERT(std::numeric_limits<T>::is_iec559, "'isinf' only accept floating-point inputs");

		return vec<4, bool>(isinf(q.x), isinf(q.y), isinf(q.z), isinf(q.w));
	}
}//namespace glm

#if GLM_CONFIG_SIMD == GLM_ENABLE
#	include "quaternion_common_simd.inl"
#endif

