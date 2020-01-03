namespace glm
{
	template<typename T>
	GLM_FUNC_QUALIFIER T dot(qua<T> const& x, qua<T> const& y)
	{
		GLM_STATIC_ASSERT(std::numeric_limits<T>::is_iec559, "'dot' accepts only floating-point inputs");
		return detail::compute_dot<qua<T>, T, false>::call(x, y);
	}

	template<typename T>
	GLM_FUNC_QUALIFIER T length(qua<T> const& q)
	{
		return glm::sqrt(dot(q, q));
	}

	template<typename T>
	GLM_FUNC_QUALIFIER qua<T> normalize(qua<T> const& q)
	{
		T len = length(q);
		if(len <= static_cast<T>(0)) // Problem
			return qua<T>(static_cast<T>(1), static_cast<T>(0), static_cast<T>(0), static_cast<T>(0));
		T oneOverLen = static_cast<T>(1) / len;
		return qua<T>(q.w * oneOverLen, q.x * oneOverLen, q.y * oneOverLen, q.z * oneOverLen);
	}

	template<typename T>
	GLM_FUNC_QUALIFIER qua<T> cross(qua<T> const& q1, qua<T> const& q2)
	{
		return qua<T>(
			q1.w * q2.w - q1.x * q2.x - q1.y * q2.y - q1.z * q2.z,
			q1.w * q2.x + q1.x * q2.w + q1.y * q2.z - q1.z * q2.y,
			q1.w * q2.y + q1.y * q2.w + q1.z * q2.x - q1.x * q2.z,
			q1.w * q2.z + q1.z * q2.w + q1.x * q2.y - q1.y * q2.x);
	}
}//namespace glm

