/// @ref gtx_transform2

namespace glm
{
	template<typename T>
	GLM_FUNC_QUALIFIER mat<3, 3, T> shearX2D(mat<3, 3, T> const& m, T s)
	{
		mat<3, 3, T> r(1);
		r[1][0] = s;
		return m * r;
	}

	template<typename T>
	GLM_FUNC_QUALIFIER mat<3, 3, T> shearY2D(mat<3, 3, T> const& m, T s)
	{
		mat<3, 3, T> r(1);
		r[0][1] = s;
		return m * r;
	}

	template<typename T>
	GLM_FUNC_QUALIFIER mat<4, 4, T> shearX3D(mat<4, 4, T> const& m, T s, T t)
	{
		mat<4, 4, T> r(1);
		r[0][1] = s;
		r[0][2] = t;
		return m * r;
	}

	template<typename T>
	GLM_FUNC_QUALIFIER mat<4, 4, T> shearY3D(mat<4, 4, T> const& m, T s, T t)
	{
		mat<4, 4, T> r(1);
		r[1][0] = s;
		r[1][2] = t;
		return m * r;
	}

	template<typename T>
	GLM_FUNC_QUALIFIER mat<4, 4, T> shearZ3D(mat<4, 4, T> const& m, T s, T t)
	{
		mat<4, 4, T> r(1);
		r[2][0] = s;
		r[2][1] = t;
		return m * r;
	}

	template<typename T>
	GLM_FUNC_QUALIFIER mat<3, 3, T> reflect2D(mat<3, 3, T> const& m, vec<3, T> const& normal)
	{
		mat<3, 3, T> r(static_cast<T>(1));
		r[0][0] = static_cast<T>(1) - static_cast<T>(2) * normal.x * normal.x;
		r[0][1] = -static_cast<T>(2) * normal.x * normal.y;
		r[1][0] = -static_cast<T>(2) * normal.x * normal.y;
		r[1][1] = static_cast<T>(1) - static_cast<T>(2) * normal.y * normal.y;
		return m * r;
	}

	template<typename T>
	GLM_FUNC_QUALIFIER mat<4, 4, T> reflect3D(mat<4, 4, T> const& m, vec<3, T> const& normal)
	{
		mat<4, 4, T> r(static_cast<T>(1));
		r[0][0] = static_cast<T>(1) - static_cast<T>(2) * normal.x * normal.x;
		r[0][1] = -static_cast<T>(2) * normal.x * normal.y;
		r[0][2] = -static_cast<T>(2) * normal.x * normal.z;

		r[1][0] = -static_cast<T>(2) * normal.x * normal.y;
		r[1][1] = static_cast<T>(1) - static_cast<T>(2) * normal.y * normal.y;
		r[1][2] = -static_cast<T>(2) * normal.y * normal.z;

		r[2][0] = -static_cast<T>(2) * normal.x * normal.z;
		r[2][1] = -static_cast<T>(2) * normal.y * normal.z;
		r[2][2] = static_cast<T>(1) - static_cast<T>(2) * normal.z * normal.z;
		return m * r;
	}

	template<typename T>
	GLM_FUNC_QUALIFIER mat<3, 3, T> proj2D(
		const mat<3, 3, T>& m,
		const vec<3, T>& normal)
	{
		mat<3, 3, T> r(static_cast<T>(1));
		r[0][0] = static_cast<T>(1) - normal.x * normal.x;
		r[0][1] = - normal.x * normal.y;
		r[1][0] = - normal.x * normal.y;
		r[1][1] = static_cast<T>(1) - normal.y * normal.y;
		return m * r;
	}

	template<typename T>
	GLM_FUNC_QUALIFIER mat<4, 4, T> proj3D(
		const mat<4, 4, T>& m,
		const vec<3, T>& normal)
	{
		mat<4, 4, T> r(static_cast<T>(1));
		r[0][0] = static_cast<T>(1) - normal.x * normal.x;
		r[0][1] = - normal.x * normal.y;
		r[0][2] = - normal.x * normal.z;
		r[1][0] = - normal.x * normal.y;
		r[1][1] = static_cast<T>(1) - normal.y * normal.y;
		r[1][2] = - normal.y * normal.z;
		r[2][0] = - normal.x * normal.z;
		r[2][1] = - normal.y * normal.z;
		r[2][2] = static_cast<T>(1) - normal.z * normal.z;
		return m * r;
	}

	template<typename T>
	GLM_FUNC_QUALIFIER mat<4, 4, T> scaleBias(T scale, T bias)
	{
		mat<4, 4, T> result;
		result[3] = vec<4, T>(vec<3, T>(bias), static_cast<T>(1));
		result[0][0] = scale;
		result[1][1] = scale;
		result[2][2] = scale;
		return result;
	}

	template<typename T>
	GLM_FUNC_QUALIFIER mat<4, 4, T> scaleBias(mat<4, 4, T> const& m, T scale, T bias)
	{
		return m * scaleBias(scale, bias);
	}
}//namespace glm

