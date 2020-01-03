/// @ref gtx_matrix_cross_product

namespace glm
{
	template<typename T>
	GLM_FUNC_QUALIFIER mat<3, 3, T> matrixCross3
	(
		vec<3, T> const& x
	)
	{
		mat<3, 3, T> Result(T(0));
		Result[0][1] = x.z;
		Result[1][0] = -x.z;
		Result[0][2] = -x.y;
		Result[2][0] = x.y;
		Result[1][2] = x.x;
		Result[2][1] = -x.x;
		return Result;
	}

	template<typename T>
	GLM_FUNC_QUALIFIER mat<4, 4, T> matrixCross4
	(
		vec<3, T> const& x
	)
	{
		mat<4, 4, T> Result(T(0));
		Result[0][1] = x.z;
		Result[1][0] = -x.z;
		Result[0][2] = -x.y;
		Result[2][0] = x.y;
		Result[1][2] = x.x;
		Result[2][1] = -x.x;
		return Result;
	}

}//namespace glm
