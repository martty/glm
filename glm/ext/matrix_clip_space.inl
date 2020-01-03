namespace glm
{
	template<typename T>
	GLM_FUNC_QUALIFIER mat<4, 4, T> ortho(T left, T right, T bottom, T top)
	{
		mat<4, 4, T> Result(static_cast<T>(1));
		Result[0][0] = static_cast<T>(2) / (right - left);
		Result[1][1] = static_cast<T>(2) / (top - bottom);
		Result[2][2] = - static_cast<T>(1);
		Result[3][0] = - (right + left) / (right - left);
		Result[3][1] = - (top + bottom) / (top - bottom);
		return Result;
	}

	template<typename T>
	GLM_FUNC_QUALIFIER mat<4, 4, T> orthoLH_ZO(T left, T right, T bottom, T top, T zNear, T zFar)
	{
		mat<4, 4, T> Result(1);
		Result[0][0] = static_cast<T>(2) / (right - left);
		Result[1][1] = static_cast<T>(2) / (top - bottom);
		Result[2][2] = static_cast<T>(1) / (zFar - zNear);
		Result[3][0] = - (right + left) / (right - left);
		Result[3][1] = - (top + bottom) / (top - bottom);
		Result[3][2] = - zNear / (zFar - zNear);
		return Result;
	}

	template<typename T>
	GLM_FUNC_QUALIFIER mat<4, 4, T> orthoLH_NO(T left, T right, T bottom, T top, T zNear, T zFar)
	{
		mat<4, 4, T> Result(1);
		Result[0][0] = static_cast<T>(2) / (right - left);
		Result[1][1] = static_cast<T>(2) / (top - bottom);
		Result[2][2] = static_cast<T>(2) / (zFar - zNear);
		Result[3][0] = - (right + left) / (right - left);
		Result[3][1] = - (top + bottom) / (top - bottom);
		Result[3][2] = - (zFar + zNear) / (zFar - zNear);
		return Result;
	}

	template<typename T>
	GLM_FUNC_QUALIFIER mat<4, 4, T> orthoRH_ZO(T left, T right, T bottom, T top, T zNear, T zFar)
	{
		mat<4, 4, T> Result(1);
		Result[0][0] = static_cast<T>(2) / (right - left);
		Result[1][1] = static_cast<T>(2) / (top - bottom);
		Result[2][2] = - static_cast<T>(1) / (zFar - zNear);
		Result[3][0] = - (right + left) / (right - left);
		Result[3][1] = - (top + bottom) / (top - bottom);
		Result[3][2] = - zNear / (zFar - zNear);
		return Result;
	}

	template<typename T>
	GLM_FUNC_QUALIFIER mat<4, 4, T> orthoRH_NO(T left, T right, T bottom, T top, T zNear, T zFar)
	{
		mat<4, 4, T> Result(1);
		Result[0][0] = static_cast<T>(2) / (right - left);
		Result[1][1] = static_cast<T>(2) / (top - bottom);
		Result[2][2] = - static_cast<T>(2) / (zFar - zNear);
		Result[3][0] = - (right + left) / (right - left);
		Result[3][1] = - (top + bottom) / (top - bottom);
		Result[3][2] = - (zFar + zNear) / (zFar - zNear);
		return Result;
	}

	template<typename T>
	GLM_FUNC_QUALIFIER mat<4, 4, T> orthoZO(T left, T right, T bottom, T top, T zNear, T zFar)
	{
#		if GLM_CONFIG_CLIP_CONTROL & GLM_CLIP_CONTROL_LH_BIT
			return orthoLH_ZO(left, right, bottom, top, zNear, zFar);
#		else
			return orthoRH_ZO(left, right, bottom, top, zNear, zFar);
#		endif
	}

	template<typename T>
	GLM_FUNC_QUALIFIER mat<4, 4, T> orthoNO(T left, T right, T bottom, T top, T zNear, T zFar)
	{
#		if GLM_CONFIG_CLIP_CONTROL & GLM_CLIP_CONTROL_LH_BIT
			return orthoLH_NO(left, right, bottom, top, zNear, zFar);
#		else
			return orthoRH_NO(left, right, bottom, top, zNear, zFar);
#		endif
	}

	template<typename T>
	GLM_FUNC_QUALIFIER mat<4, 4, T> orthoLH(T left, T right, T bottom, T top, T zNear, T zFar)
	{
#		if GLM_CONFIG_CLIP_CONTROL & GLM_CLIP_CONTROL_ZO_BIT
			return orthoLH_ZO(left, right, bottom, top, zNear, zFar);
#		else
			return orthoLH_NO(left, right, bottom, top, zNear, zFar);
#		endif

	}

	template<typename T>
	GLM_FUNC_QUALIFIER mat<4, 4, T> orthoRH(T left, T right, T bottom, T top, T zNear, T zFar)
	{
#		if GLM_CONFIG_CLIP_CONTROL & GLM_CLIP_CONTROL_ZO_BIT
			return orthoRH_ZO(left, right, bottom, top, zNear, zFar);
#		else
			return orthoRH_NO(left, right, bottom, top, zNear, zFar);
#		endif
	}

	template<typename T>
	GLM_FUNC_QUALIFIER mat<4, 4, T> ortho(T left, T right, T bottom, T top, T zNear, T zFar)
	{
#		if GLM_CONFIG_CLIP_CONTROL == GLM_CLIP_CONTROL_LH_ZO
			return orthoLH_ZO(left, right, bottom, top, zNear, zFar);
#		elif GLM_CONFIG_CLIP_CONTROL == GLM_CLIP_CONTROL_LH_NO
			return orthoLH_NO(left, right, bottom, top, zNear, zFar);
#		elif GLM_CONFIG_CLIP_CONTROL == GLM_CLIP_CONTROL_RH_ZO
			return orthoRH_ZO(left, right, bottom, top, zNear, zFar);
#		elif GLM_CONFIG_CLIP_CONTROL == GLM_CLIP_CONTROL_RH_NO
			return orthoRH_NO(left, right, bottom, top, zNear, zFar);
#		endif
	}

	template<typename T>
	GLM_FUNC_QUALIFIER mat<4, 4, T> frustumLH_ZO(T left, T right, T bottom, T top, T nearVal, T farVal)
	{
		mat<4, 4, T> Result(0);
		Result[0][0] = (static_cast<T>(2) * nearVal) / (right - left);
		Result[1][1] = (static_cast<T>(2) * nearVal) / (top - bottom);
		Result[2][0] = (right + left) / (right - left);
		Result[2][1] = (top + bottom) / (top - bottom);
		Result[2][2] = farVal / (farVal - nearVal);
		Result[2][3] = static_cast<T>(1);
		Result[3][2] = -(farVal * nearVal) / (farVal - nearVal);
		return Result;
	}

	template<typename T>
	GLM_FUNC_QUALIFIER mat<4, 4, T> frustumLH_NO(T left, T right, T bottom, T top, T nearVal, T farVal)
	{
		mat<4, 4, T> Result(0);
		Result[0][0] = (static_cast<T>(2) * nearVal) / (right - left);
		Result[1][1] = (static_cast<T>(2) * nearVal) / (top - bottom);
		Result[2][0] = (right + left) / (right - left);
		Result[2][1] = (top + bottom) / (top - bottom);
		Result[2][2] = (farVal + nearVal) / (farVal - nearVal);
		Result[2][3] = static_cast<T>(1);
		Result[3][2] = - (static_cast<T>(2) * farVal * nearVal) / (farVal - nearVal);
		return Result;
	}

	template<typename T>
	GLM_FUNC_QUALIFIER mat<4, 4, T> frustumRH_ZO(T left, T right, T bottom, T top, T nearVal, T farVal)
	{
		mat<4, 4, T> Result(0);
		Result[0][0] = (static_cast<T>(2) * nearVal) / (right - left);
		Result[1][1] = (static_cast<T>(2) * nearVal) / (top - bottom);
		Result[2][0] = (right + left) / (right - left);
		Result[2][1] = (top + bottom) / (top - bottom);
		Result[2][2] = farVal / (nearVal - farVal);
		Result[2][3] = static_cast<T>(-1);
		Result[3][2] = -(farVal * nearVal) / (farVal - nearVal);
		return Result;
	}

	template<typename T>
	GLM_FUNC_QUALIFIER mat<4, 4, T> frustumRH_NO(T left, T right, T bottom, T top, T nearVal, T farVal)
	{
		mat<4, 4, T> Result(0);
		Result[0][0] = (static_cast<T>(2) * nearVal) / (right - left);
		Result[1][1] = (static_cast<T>(2) * nearVal) / (top - bottom);
		Result[2][0] = (right + left) / (right - left);
		Result[2][1] = (top + bottom) / (top - bottom);
		Result[2][2] = - (farVal + nearVal) / (farVal - nearVal);
		Result[2][3] = static_cast<T>(-1);
		Result[3][2] = - (static_cast<T>(2) * farVal * nearVal) / (farVal - nearVal);
		return Result;
	}

	template<typename T>
	GLM_FUNC_QUALIFIER mat<4, 4, T> frustumZO(T left, T right, T bottom, T top, T nearVal, T farVal)
	{
#		if GLM_CONFIG_CLIP_CONTROL & GLM_CLIP_CONTROL_LH_BIT
			return frustumLH_ZO(left, right, bottom, top, nearVal, farVal);
#		else
			return frustumRH_ZO(left, right, bottom, top, nearVal, farVal);
#		endif
	}

	template<typename T>
	GLM_FUNC_QUALIFIER mat<4, 4, T> frustumNO(T left, T right, T bottom, T top, T nearVal, T farVal)
	{
#		if GLM_CONFIG_CLIP_CONTROL & GLM_CLIP_CONTROL_LH_BIT
			return frustumLH_NO(left, right, bottom, top, nearVal, farVal);
#		else
			return frustumRH_NO(left, right, bottom, top, nearVal, farVal);
#		endif
	}

	template<typename T>
	GLM_FUNC_QUALIFIER mat<4, 4, T> frustumLH(T left, T right, T bottom, T top, T nearVal, T farVal)
	{
#		if GLM_CONFIG_CLIP_CONTROL & GLM_CLIP_CONTROL_ZO_BIT
			return frustumLH_ZO(left, right, bottom, top, nearVal, farVal);
#		else
			return frustumLH_NO(left, right, bottom, top, nearVal, farVal);
#		endif
	}

	template<typename T>
	GLM_FUNC_QUALIFIER mat<4, 4, T> frustumRH(T left, T right, T bottom, T top, T nearVal, T farVal)
	{
#		if GLM_CONFIG_CLIP_CONTROL & GLM_CLIP_CONTROL_ZO_BIT
			return frustumRH_ZO(left, right, bottom, top, nearVal, farVal);
#		else
			return frustumRH_NO(left, right, bottom, top, nearVal, farVal);
#		endif
	}

	template<typename T>
	GLM_FUNC_QUALIFIER mat<4, 4, T> frustum(T left, T right, T bottom, T top, T nearVal, T farVal)
	{
#		if GLM_CONFIG_CLIP_CONTROL == GLM_CLIP_CONTROL_LH_ZO
			return frustumLH_ZO(left, right, bottom, top, nearVal, farVal);
#		elif GLM_CONFIG_CLIP_CONTROL == GLM_CLIP_CONTROL_LH_NO
			return frustumLH_NO(left, right, bottom, top, nearVal, farVal);
#		elif GLM_CONFIG_CLIP_CONTROL == GLM_CLIP_CONTROL_RH_ZO
			return frustumRH_ZO(left, right, bottom, top, nearVal, farVal);
#		elif GLM_CONFIG_CLIP_CONTROL == GLM_CLIP_CONTROL_RH_NO
			return frustumRH_NO(left, right, bottom, top, nearVal, farVal);
#		endif
	}

	template<typename T>
	GLM_FUNC_QUALIFIER mat<4, 4, T> perspectiveRH_ZO(T fovy, T aspect, T zNear, T zFar)
	{
		assert(abs(aspect - std::numeric_limits<T>::epsilon()) > static_cast<T>(0));

		T const tanHalfFovy = tan(fovy / static_cast<T>(2));

		mat<4, 4, T> Result(static_cast<T>(0));
		Result[0][0] = static_cast<T>(1) / (aspect * tanHalfFovy);
		Result[1][1] = static_cast<T>(1) / (tanHalfFovy);
		Result[2][2] = zFar / (zNear - zFar);
		Result[2][3] = - static_cast<T>(1);
		Result[3][2] = -(zFar * zNear) / (zFar - zNear);
		return Result;
	}

	template<typename T>
	GLM_FUNC_QUALIFIER mat<4, 4, T> perspectiveRH_NO(T fovy, T aspect, T zNear, T zFar)
	{
		assert(abs(aspect - std::numeric_limits<T>::epsilon()) > static_cast<T>(0));

		T const tanHalfFovy = tan(fovy / static_cast<T>(2));

		mat<4, 4, T> Result(static_cast<T>(0));
		Result[0][0] = static_cast<T>(1) / (aspect * tanHalfFovy);
		Result[1][1] = static_cast<T>(1) / (tanHalfFovy);
		Result[2][2] = - (zFar + zNear) / (zFar - zNear);
		Result[2][3] = - static_cast<T>(1);
		Result[3][2] = - (static_cast<T>(2) * zFar * zNear) / (zFar - zNear);
		return Result;
	}

	template<typename T>
	GLM_FUNC_QUALIFIER mat<4, 4, T> perspectiveLH_ZO(T fovy, T aspect, T zNear, T zFar)
	{
		assert(abs(aspect - std::numeric_limits<T>::epsilon()) > static_cast<T>(0));

		T const tanHalfFovy = tan(fovy / static_cast<T>(2));

		mat<4, 4, T> Result(static_cast<T>(0));
		Result[0][0] = static_cast<T>(1) / (aspect * tanHalfFovy);
		Result[1][1] = static_cast<T>(1) / (tanHalfFovy);
		Result[2][2] = zFar / (zFar - zNear);
		Result[2][3] = static_cast<T>(1);
		Result[3][2] = -(zFar * zNear) / (zFar - zNear);
		return Result;
	}

	template<typename T>
	GLM_FUNC_QUALIFIER mat<4, 4, T> perspectiveLH_NO(T fovy, T aspect, T zNear, T zFar)
	{
		assert(abs(aspect - std::numeric_limits<T>::epsilon()) > static_cast<T>(0));

		T const tanHalfFovy = tan(fovy / static_cast<T>(2));

		mat<4, 4, T> Result(static_cast<T>(0));
		Result[0][0] = static_cast<T>(1) / (aspect * tanHalfFovy);
		Result[1][1] = static_cast<T>(1) / (tanHalfFovy);
		Result[2][2] = (zFar + zNear) / (zFar - zNear);
		Result[2][3] = static_cast<T>(1);
		Result[3][2] = - (static_cast<T>(2) * zFar * zNear) / (zFar - zNear);
		return Result;
	}

	template<typename T>
	GLM_FUNC_QUALIFIER mat<4, 4, T> perspectiveZO(T fovy, T aspect, T zNear, T zFar)
	{
#		if GLM_CONFIG_CLIP_CONTROL & GLM_CLIP_CONTROL_LH_BIT
			return perspectiveLH_ZO(fovy, aspect, zNear, zFar);
#		else
			return perspectiveRH_ZO(fovy, aspect, zNear, zFar);
#		endif
	}

	template<typename T>
	GLM_FUNC_QUALIFIER mat<4, 4, T> perspectiveNO(T fovy, T aspect, T zNear, T zFar)
	{
#		if GLM_CONFIG_CLIP_CONTROL & GLM_CLIP_CONTROL_LH_BIT
			return perspectiveLH_NO(fovy, aspect, zNear, zFar);
#		else
			return perspectiveRH_NO(fovy, aspect, zNear, zFar);
#		endif
	}

	template<typename T>
	GLM_FUNC_QUALIFIER mat<4, 4, T> perspectiveLH(T fovy, T aspect, T zNear, T zFar)
	{
#		if GLM_CONFIG_CLIP_CONTROL & GLM_CLIP_CONTROL_ZO_BIT
			return perspectiveLH_ZO(fovy, aspect, zNear, zFar);
#		else
			return perspectiveLH_NO(fovy, aspect, zNear, zFar);
#		endif

	}

	template<typename T>
	GLM_FUNC_QUALIFIER mat<4, 4, T> perspectiveRH(T fovy, T aspect, T zNear, T zFar)
	{
#		if GLM_CONFIG_CLIP_CONTROL & GLM_CLIP_CONTROL_ZO_BIT
			return perspectiveRH_ZO(fovy, aspect, zNear, zFar);
#		else
			return perspectiveRH_NO(fovy, aspect, zNear, zFar);
#		endif
	}

	template<typename T>
	GLM_FUNC_QUALIFIER mat<4, 4, T> perspective(T fovy, T aspect, T zNear, T zFar)
	{
#		if GLM_CONFIG_CLIP_CONTROL == GLM_CLIP_CONTROL_LH_ZO
			return perspectiveLH_ZO(fovy, aspect, zNear, zFar);
#		elif GLM_CONFIG_CLIP_CONTROL == GLM_CLIP_CONTROL_LH_NO
			return perspectiveLH_NO(fovy, aspect, zNear, zFar);
#		elif GLM_CONFIG_CLIP_CONTROL == GLM_CLIP_CONTROL_RH_ZO
			return perspectiveRH_ZO(fovy, aspect, zNear, zFar);
#		elif GLM_CONFIG_CLIP_CONTROL == GLM_CLIP_CONTROL_RH_NO
			return perspectiveRH_NO(fovy, aspect, zNear, zFar);
#		endif
	}

	template<typename T>
	GLM_FUNC_QUALIFIER mat<4, 4, T> perspectiveFovRH_ZO(T fov, T width, T height, T zNear, T zFar)
	{
		assert(width > static_cast<T>(0));
		assert(height > static_cast<T>(0));
		assert(fov > static_cast<T>(0));

		T const rad = fov;
		T const h = glm::cos(static_cast<T>(0.5) * rad) / glm::sin(static_cast<T>(0.5) * rad);
		T const w = h * height / width; ///todo max(width , Height) / min(width , Height)?

		mat<4, 4, T> Result(static_cast<T>(0));
		Result[0][0] = w;
		Result[1][1] = h;
		Result[2][2] = zFar / (zNear - zFar);
		Result[2][3] = - static_cast<T>(1);
		Result[3][2] = -(zFar * zNear) / (zFar - zNear);
		return Result;
	}

	template<typename T>
	GLM_FUNC_QUALIFIER mat<4, 4, T> perspectiveFovRH_NO(T fov, T width, T height, T zNear, T zFar)
	{
		assert(width > static_cast<T>(0));
		assert(height > static_cast<T>(0));
		assert(fov > static_cast<T>(0));

		T const rad = fov;
		T const h = glm::cos(static_cast<T>(0.5) * rad) / glm::sin(static_cast<T>(0.5) * rad);
		T const w = h * height / width; ///todo max(width , Height) / min(width , Height)?

		mat<4, 4, T> Result(static_cast<T>(0));
		Result[0][0] = w;
		Result[1][1] = h;
		Result[2][2] = - (zFar + zNear) / (zFar - zNear);
		Result[2][3] = - static_cast<T>(1);
		Result[3][2] = - (static_cast<T>(2) * zFar * zNear) / (zFar - zNear);
		return Result;
	}

	template<typename T>
	GLM_FUNC_QUALIFIER mat<4, 4, T> perspectiveFovLH_ZO(T fov, T width, T height, T zNear, T zFar)
	{
		assert(width > static_cast<T>(0));
		assert(height > static_cast<T>(0));
		assert(fov > static_cast<T>(0));

		T const rad = fov;
		T const h = glm::cos(static_cast<T>(0.5) * rad) / glm::sin(static_cast<T>(0.5) * rad);
		T const w = h * height / width; ///todo max(width , Height) / min(width , Height)?

		mat<4, 4, T> Result(static_cast<T>(0));
		Result[0][0] = w;
		Result[1][1] = h;
		Result[2][2] = zFar / (zFar - zNear);
		Result[2][3] = static_cast<T>(1);
		Result[3][2] = -(zFar * zNear) / (zFar - zNear);
		return Result;
	}

	template<typename T>
	GLM_FUNC_QUALIFIER mat<4, 4, T> perspectiveFovLH_NO(T fov, T width, T height, T zNear, T zFar)
	{
		assert(width > static_cast<T>(0));
		assert(height > static_cast<T>(0));
		assert(fov > static_cast<T>(0));

		T const rad = fov;
		T const h = glm::cos(static_cast<T>(0.5) * rad) / glm::sin(static_cast<T>(0.5) * rad);
		T const w = h * height / width; ///todo max(width , Height) / min(width , Height)?

		mat<4, 4, T> Result(static_cast<T>(0));
		Result[0][0] = w;
		Result[1][1] = h;
		Result[2][2] = (zFar + zNear) / (zFar - zNear);
		Result[2][3] = static_cast<T>(1);
		Result[3][2] = - (static_cast<T>(2) * zFar * zNear) / (zFar - zNear);
		return Result;
	}

	template<typename T>
	GLM_FUNC_QUALIFIER mat<4, 4, T> perspectiveFovZO(T fov, T width, T height, T zNear, T zFar)
	{
#		if GLM_CONFIG_CLIP_CONTROL & GLM_CLIP_CONTROL_LH_BIT
			return perspectiveFovLH_ZO(fov, width, height, zNear, zFar);
#		else
			return perspectiveFovRH_ZO(fov, width, height, zNear, zFar);
#		endif
	}

	template<typename T>
	GLM_FUNC_QUALIFIER mat<4, 4, T> perspectiveFovNO(T fov, T width, T height, T zNear, T zFar)
	{
#		if GLM_CONFIG_CLIP_CONTROL & GLM_CLIP_CONTROL_LH_BIT
			return perspectiveFovLH_NO(fov, width, height, zNear, zFar);
#		else
			return perspectiveFovRH_NO(fov, width, height, zNear, zFar);
#		endif
	}

	template<typename T>
	GLM_FUNC_QUALIFIER mat<4, 4, T> perspectiveFovLH(T fov, T width, T height, T zNear, T zFar)
	{
#		if GLM_CONFIG_CLIP_CONTROL & GLM_CLIP_CONTROL_ZO_BIT
			return perspectiveFovLH_ZO(fov, width, height, zNear, zFar);
#		else
			return perspectiveFovLH_NO(fov, width, height, zNear, zFar);
#		endif
	}

	template<typename T>
	GLM_FUNC_QUALIFIER mat<4, 4, T> perspectiveFovRH(T fov, T width, T height, T zNear, T zFar)
	{
#		if GLM_CONFIG_CLIP_CONTROL & GLM_CLIP_CONTROL_ZO_BIT
			return perspectiveFovRH_ZO(fov, width, height, zNear, zFar);
#		else
			return perspectiveFovRH_NO(fov, width, height, zNear, zFar);
#		endif
	}

	template<typename T>
	GLM_FUNC_QUALIFIER mat<4, 4, T> perspectiveFov(T fov, T width, T height, T zNear, T zFar)
	{
#		if GLM_CONFIG_CLIP_CONTROL == GLM_CLIP_CONTROL_LH_ZO
			return perspectiveFovLH_ZO(fov, width, height, zNear, zFar);
		elif GLM_CONFIG_CLIP_CONTROL == GLM_CLIP_CONTROL_LH_NO
			return perspectiveFovLH_NO(fov, width, height, zNear, zFar);
		elif GLM_CONFIG_CLIP_CONTROL == GLM_CLIP_CONTROL_RH_ZO
			return perspectiveFovRH_ZO(fov, width, height, zNear, zFar);
		elif GLM_CONFIG_CLIP_CONTROL == GLM_CLIP_CONTROL_RH_NO
			return perspectiveFovRH_NO(fov, width, height, zNear, zFar);
#		endif
	}

	template<typename T>
	GLM_FUNC_QUALIFIER mat<4, 4, T> infinitePerspectiveRH(T fovy, T aspect, T zNear)
	{
		T const range = tan(fovy / static_cast<T>(2)) * zNear;
		T const left = -range * aspect;
		T const right = range * aspect;
		T const bottom = -range;
		T const top = range;

		mat<4, 4, T> Result(static_cast<T>(0));
		Result[0][0] = (static_cast<T>(2) * zNear) / (right - left);
		Result[1][1] = (static_cast<T>(2) * zNear) / (top - bottom);
		Result[2][2] = - static_cast<T>(1);
		Result[2][3] = - static_cast<T>(1);
		Result[3][2] = - static_cast<T>(2) * zNear;
		return Result;
	}

	template<typename T>
	GLM_FUNC_QUALIFIER mat<4, 4, T> infinitePerspectiveLH(T fovy, T aspect, T zNear)
	{
		T const range = tan(fovy / static_cast<T>(2)) * zNear;
		T const left = -range * aspect;
		T const right = range * aspect;
		T const bottom = -range;
		T const top = range;

		mat<4, 4, T> Result(T(0));
		Result[0][0] = (static_cast<T>(2) * zNear) / (right - left);
		Result[1][1] = (static_cast<T>(2) * zNear) / (top - bottom);
		Result[2][2] = static_cast<T>(1);
		Result[2][3] = static_cast<T>(1);
		Result[3][2] = - static_cast<T>(2) * zNear;
		return Result;
	}

	template<typename T>
	GLM_FUNC_QUALIFIER mat<4, 4, T> infinitePerspective(T fovy, T aspect, T zNear)
	{
#		if GLM_CONFIG_CLIP_CONTROL & GLM_CLIP_CONTROL_LH_BIT
			return infinitePerspectiveLH(fovy, aspect, zNear);
#		else
			return infinitePerspectiveRH(fovy, aspect, zNear);
#		endif
	}

	// Infinite projection matrix: http://www.terathon.com/gdc07_lengyel.pdf
	template<typename T>
	GLM_FUNC_QUALIFIER mat<4, 4, T> tweakedInfinitePerspective(T fovy, T aspect, T zNear, T ep)
	{
		T const range = tan(fovy / static_cast<T>(2)) * zNear;
		T const left = -range * aspect;
		T const right = range * aspect;
		T const bottom = -range;
		T const top = range;

		mat<4, 4, T> Result(static_cast<T>(0));
		Result[0][0] = (static_cast<T>(2) * zNear) / (right - left);
		Result[1][1] = (static_cast<T>(2) * zNear) / (top - bottom);
		Result[2][2] = ep - static_cast<T>(1);
		Result[2][3] = static_cast<T>(-1);
		Result[3][2] = (ep - static_cast<T>(2)) * zNear;
		return Result;
	}

	template<typename T>
	GLM_FUNC_QUALIFIER mat<4, 4, T> tweakedInfinitePerspective(T fovy, T aspect, T zNear)
	{
		return tweakedInfinitePerspective(fovy, aspect, zNear, epsilon<T>());
	}
}//namespace glm
