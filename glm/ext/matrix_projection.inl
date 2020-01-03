namespace glm
{
	template<typename T, typename U>
	GLM_FUNC_QUALIFIER vec<3, T> projectZO(vec<3, T> const& obj, mat<4, 4, T> const& model, mat<4, 4, T> const& proj, vec<4, U> const& viewport)
	{
		vec<4, T> tmp = vec<4, T>(obj, static_cast<T>(1));
		tmp = model * tmp;
		tmp = proj * tmp;

		tmp /= tmp.w;
		tmp.x = tmp.x * static_cast<T>(0.5) + static_cast<T>(0.5);
		tmp.y = tmp.y * static_cast<T>(0.5) + static_cast<T>(0.5);

		tmp[0] = tmp[0] * T(viewport[2]) + T(viewport[0]);
		tmp[1] = tmp[1] * T(viewport[3]) + T(viewport[1]);

		return vec<3, T>(tmp);
	}

	template<typename T, typename U>
	GLM_FUNC_QUALIFIER vec<3, T> projectNO(vec<3, T> const& obj, mat<4, 4, T> const& model, mat<4, 4, T> const& proj, vec<4, U> const& viewport)
	{
		vec<4, T> tmp = vec<4, T>(obj, static_cast<T>(1));
		tmp = model * tmp;
		tmp = proj * tmp;

		tmp /= tmp.w;
		tmp = tmp * static_cast<T>(0.5) + static_cast<T>(0.5);
		tmp[0] = tmp[0] * T(viewport[2]) + T(viewport[0]);
		tmp[1] = tmp[1] * T(viewport[3]) + T(viewport[1]);

		return vec<3, T>(tmp);
	}

	template<typename T, typename U>
	GLM_FUNC_QUALIFIER vec<3, T> project(vec<3, T> const& obj, mat<4, 4, T> const& model, mat<4, 4, T> const& proj, vec<4, U> const& viewport)
	{
		if(GLM_CONFIG_CLIP_CONTROL & GLM_CLIP_CONTROL_ZO_BIT)
			return projectZO(obj, model, proj, viewport);
		else
			return projectNO(obj, model, proj, viewport);
	}

	template<typename T, typename U>
	GLM_FUNC_QUALIFIER vec<3, T> unProjectZO(vec<3, T> const& win, mat<4, 4, T> const& model, mat<4, 4, T> const& proj, vec<4, U> const& viewport)
	{
		mat<4, 4, T> Inverse = inverse(proj * model);

		vec<4, T> tmp = vec<4, T>(win, T(1));
		tmp.x = (tmp.x - T(viewport[0])) / T(viewport[2]);
		tmp.y = (tmp.y - T(viewport[1])) / T(viewport[3]);
		tmp.x = tmp.x * static_cast<T>(2) - static_cast<T>(1);
		tmp.y = tmp.y * static_cast<T>(2) - static_cast<T>(1);

		vec<4, T> obj = Inverse * tmp;
		obj /= obj.w;

		return vec<3, T>(obj);
	}

	template<typename T, typename U>
	GLM_FUNC_QUALIFIER vec<3, T> unProjectNO(vec<3, T> const& win, mat<4, 4, T> const& model, mat<4, 4, T> const& proj, vec<4, U> const& viewport)
	{
		mat<4, 4, T> Inverse = inverse(proj * model);

		vec<4, T> tmp = vec<4, T>(win, T(1));
		tmp.x = (tmp.x - T(viewport[0])) / T(viewport[2]);
		tmp.y = (tmp.y - T(viewport[1])) / T(viewport[3]);
		tmp = tmp * static_cast<T>(2) - static_cast<T>(1);

		vec<4, T> obj = Inverse * tmp;
		obj /= obj.w;

		return vec<3, T>(obj);
	}

	template<typename T, typename U>
	GLM_FUNC_QUALIFIER vec<3, T> unProject(vec<3, T> const& win, mat<4, 4, T> const& model, mat<4, 4, T> const& proj, vec<4, U> const& viewport)
	{
		if(GLM_CONFIG_CLIP_CONTROL & GLM_CLIP_CONTROL_ZO_BIT)
			return unProjectZO(win, model, proj, viewport);
		else
			return unProjectNO(win, model, proj, viewport);
	}

	template<typename T, typename U>
	GLM_FUNC_QUALIFIER mat<4, 4, T> pickMatrix(vec<2, T> const& center, vec<2, T> const& delta, vec<4, U> const& viewport)
	{
		assert(delta.x > static_cast<T>(0) && delta.y > static_cast<T>(0));
		mat<4, 4, T> Result(static_cast<T>(1));

		if(!(delta.x > static_cast<T>(0) && delta.y > static_cast<T>(0)))
			return Result; // Error

		vec<3, T> Temp(
			(static_cast<T>(viewport[2]) - static_cast<T>(2) * (center.x - static_cast<T>(viewport[0]))) / delta.x,
			(static_cast<T>(viewport[3]) - static_cast<T>(2) * (center.y - static_cast<T>(viewport[1]))) / delta.y,
			static_cast<T>(0));

		// Translate and scale the picked region to the entire window
		Result = translate(Result, Temp);
		return scale(Result, vec<3, T>(static_cast<T>(viewport[2]) / delta.x, static_cast<T>(viewport[3]) / delta.y, static_cast<T>(1)));
	}
}//namespace glm
