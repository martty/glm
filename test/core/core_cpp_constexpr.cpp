#include <glm/glm.hpp>

#if GLM_CONFIG_CONSTEXP == GLM_ENABLE

#include <glm/gtc/constants.hpp>
#include <glm/gtc/quaternion.hpp>
#include <glm/ext/vector_relational.hpp>
#include <glm/ext/vector_bool4.hpp>
#include <glm/vector_relational.hpp>
#include <glm/detail/func_vector_relational.inl>
static int test_vec1()
{
	int Error = 0;
	
	{
		constexpr glm::bvec2 C(true);
		constexpr glm::bvec2 B(true);
		static_assert(glm::any(glm::equal(C, B)), "GLM: Failed constexpr");
	}

	return Error;
}

static int test_vec2()
{
	int Error = 0;

	{
		constexpr glm::bvec2 B(true);
		constexpr bool A = glm::all(B);
		static_assert(A, "GLM: Failed constexpr");
		
		constexpr glm::bvec2 D(true, false);
		constexpr bool C = glm::any(D);
		static_assert(C, "GLM: Failed constexpr");
	}
	
	{
		constexpr glm::bvec2 C(true);
		constexpr glm::bvec2 B(true, false);
		static_assert(glm::any(glm::equal(C, B)), "GLM: Failed constexpr");
	}
	
	{
		constexpr glm::ivec2 A(1);
		static_assert(glm::ivec2(1) == A, "GLM: Failed constexpr");
	}

	{
		constexpr glm::ivec2 I(1, 2);
		static_assert(glm::ivec2(1, 2) == I, "GLM: Failed constexpr");
	}

	{
		constexpr glm::ivec2 L(glm::ivec2(1, 2));
		static_assert(glm::ivec2(1, 2) == L, "GLM: Failed constexpr");

		constexpr glm::ivec2 M(glm::ivec3(1, 2, 3));
		static_assert(glm::ivec2(1, 2) == M, "GLM: Failed constexpr");

		constexpr glm::ivec2 N(glm::ivec4(1, 2, 3, 4));
		static_assert(glm::ivec2(1, 2) == N, "GLM: Failed constexpr");
	}

	{
		constexpr glm::ivec2 A(1);
		static_assert(A[0] == 1, "GLM: Failed constexpr");
		static_assert(glm::vec2(1.0f).x > 0.0f, "GLM: Failed constexpr");
		static_assert(glm::vec2(1.0f, -1.0f).x > 0.0f, "GLM: Failed constexpr");
		static_assert(glm::vec2(1.0f, -1.0f).y < 0.0f, "GLM: Failed constexpr");
		static_assert(glm::vec2::length() == 2, "GLM: Failed constexpr");
	}

	{
		constexpr glm::bvec2 A1(true);
		constexpr glm::bvec2 A2(true);
		constexpr glm::bvec2 B1(false);
		constexpr glm::bvec2 B2(false);
		static_assert(A1 == A2 && B1 == B2, "GLM: Failed constexpr");
		static_assert(A1 == A2 || B1 == B2, "GLM: Failed constexpr");
	}

	{
		constexpr glm::ivec2 A(1);
		constexpr glm::ivec2 B = A + 1;
		constexpr glm::ivec2 C(3);
		static_assert(A + B == C, "GLM: Failed constexpr");

		constexpr glm::ivec2 D = +A;
		static_assert(D == A, "GLM: Failed constexpr");
	}

	{
		constexpr glm::ivec2 A(3);
		constexpr glm::ivec2 B = A - 1;
		constexpr glm::ivec2 C(1);
		static_assert(A - B == C, "GLM: Failed constexpr");

		constexpr glm::ivec2 D = -A;
		static_assert(-D == A, "GLM: Failed constexpr");
	}

	{
		constexpr glm::ivec2 A(3);
		constexpr glm::ivec2 B = A * 1;
		static_assert(A == B, "GLM: Failed constexpr");

		constexpr glm::ivec2 C(1);
		static_assert(B * C == A, "GLM: Failed constexpr");
	}

	{
		constexpr glm::ivec2 A(3);
		constexpr glm::ivec2 B = A / 1;
		static_assert(A == B, "GLM: Failed constexpr");

		constexpr glm::ivec2 C(1);
		static_assert(B / C == A, "GLM: Failed constexpr");
	}

	return Error;
}

static int test_vec3()
{
	int Error = 0;

	{
		constexpr glm::bvec3 B(true);
		constexpr bool A = glm::all(B);
		static_assert(A, "GLM: Failed constexpr");
		
		constexpr glm::bvec3 D(true, false, true);
		constexpr bool C = glm::any(D);
		static_assert(C, "GLM: Failed constexpr");
	}
	
	{
		constexpr glm::bvec3 C(true);
		constexpr glm::bvec3 B(true, false, true);
		static_assert(glm::any(glm::equal(C, B)), "GLM: Failed constexpr");
	}
	
	{
		constexpr glm::ivec3 A(1);
		static_assert(glm::ivec3(1) == A, "GLM: Failed constexpr");
	}

	{
		constexpr glm::ivec3 B(glm::ivec2(1, 2), 3);
		static_assert(glm::ivec3(1, 2, 3) == B, "GLM: Failed constexpr");

		constexpr glm::ivec3 C(1, glm::ivec2(2, 3));
		static_assert(glm::ivec3(1, 2, 3) == C, "GLM: Failed constexpr");
	}

	{
		constexpr glm::ivec3 M(1, 2, 3);
		static_assert(glm::ivec3(1, 2, 3) == M, "GLM: Failed constexpr");
	}

	{
		constexpr glm::ivec3 N(glm::ivec4(1, 2, 3, 4));
		static_assert(glm::ivec3(1, 2, 3) == N, "GLM: Failed constexpr");
	}

	{
		constexpr glm::ivec3 const A(1);
		static_assert(A[0] == 1, "GLM: Failed constexpr");
		static_assert(glm::vec3(1.0f).x > 0.0f, "GLM: Failed constexpr");
		static_assert(glm::vec3(1.0f, -1.0f, -1.0f).x > 0.0f, "GLM: Failed constexpr");
		static_assert(glm::vec3(1.0f, -1.0f, -1.0f).y < 0.0f, "GLM: Failed constexpr");
		static_assert(glm::vec3::length() == 3, "GLM: Failed constexpr");
	}

	{
		constexpr glm::bvec3 A1(true);
		constexpr glm::bvec3 A2(true);
		constexpr glm::bvec3 B1(false);
		constexpr glm::bvec3 B2(false);
		static_assert(A1 == A2 && B1 == B2, "GLM: Failed constexpr");
		static_assert(A1 == A2 || B1 == B2, "GLM: Failed constexpr");
	}

	{
		constexpr glm::ivec3 A(1);
		constexpr glm::ivec3 B = A + 1;
		constexpr glm::ivec3 C(3);
		static_assert(A + B == C, "GLM: Failed constexpr");

		constexpr glm::ivec3 D = +A;
		static_assert(D == A, "GLM: Failed constexpr");
	}

	{
		constexpr glm::ivec3 A(3);
		constexpr glm::ivec3 B = A - 1;
		constexpr glm::ivec3 C(1);
		static_assert(A - B == C, "GLM: Failed constexpr");

		constexpr glm::ivec3 D = -A;
		static_assert(-D == A, "GLM: Failed constexpr");
	}

	{
		constexpr glm::ivec3 A(3);
		constexpr glm::ivec3 B = A * 1;
		static_assert(A == B, "GLM: Failed constexpr");

		constexpr glm::ivec3 C(1);
		static_assert(B * C == A, "GLM: Failed constexpr");
	}

	{
		constexpr glm::ivec3 A(3);
		constexpr glm::ivec3 B = A / 1;
		static_assert(A == B, "GLM: Failed constexpr");

		constexpr glm::ivec3 C(1);
		static_assert(B / C == A, "GLM: Failed constexpr");
	}

	return Error;
}

static int test_vec4()
{
	int Error = 0;
	
	{
		constexpr glm::bvec4 B(true);
		constexpr bool A = glm::all(B);
		static_assert(A, "GLM: Failed constexpr");
		
		constexpr glm::bvec4 D(true, false, true, false);
		constexpr bool C = glm::any(D);
		static_assert(C, "GLM: Failed constexpr");
	}
	
	{
		constexpr glm::bvec4 C(true);
		constexpr glm::bvec4 B(true, false, true, false);
		static_assert(glm::any(glm::equal(C, B)), "GLM: Failed constexpr");
	}

	{
		constexpr glm::ivec4 O(glm::ivec4(1));
		static_assert(glm::ivec4(1) == O, "GLM: Failed constexpr");

		constexpr glm::ivec4 A(1);
		static_assert(glm::ivec4(1) == A, "GLM: Failed constexpr");

		constexpr glm::ivec4 N(glm::ivec4(1, 2, 3, 4));
		static_assert(glm::ivec4(1, 2, 3, 4) == N, "GLM: Failed constexpr");
	}

	{
		constexpr glm::ivec4 A(glm::ivec3(1, 2, 3), 4);
		static_assert(glm::ivec4(1, 2, 3, 4) == A, "GLM: Failed constexpr");

		constexpr glm::ivec4 B(glm::ivec2(1, 2), glm::ivec2(3, 4));
		static_assert(glm::ivec4(1, 2, 3, 4) == B, "GLM: Failed constexpr");

		constexpr glm::ivec4 C(1, glm::ivec3(2, 3, 4));
		static_assert(glm::ivec4(1, 2, 3, 4) == C, "GLM: Failed constexpr");
	}

	{
		constexpr glm::ivec4 A(1);
		static_assert(A[0] == 1, "GLM: Failed constexpr");
		static_assert(glm::ivec4(1).x > 0, "GLM: Failed constexpr");
		static_assert(glm::ivec4(1, -1, -1, 1).x > 0, "GLM: Failed constexpr");
		static_assert(glm::ivec4(1, -1, -1, 1).y < 0, "GLM: Failed constexpr");
		static_assert(glm::ivec4::length() == 4, "GLM: Failed constexpr");
	}

	{
		constexpr glm::bvec4 A1(true);
		constexpr glm::bvec4 A2(true);
		constexpr glm::bvec4 B1(false);
		constexpr glm::bvec4 B2(false);
		static_assert(A1 == A2 && B1 == B2, "GLM: Failed constexpr");
		static_assert(A1 == A2 || B1 == B2, "GLM: Failed constexpr");
	}

	{
		constexpr glm::ivec4 A(1);
		constexpr glm::ivec4 B = A + 1;
		constexpr glm::ivec4 C(3);
		static_assert(A + B == C, "GLM: Failed constexpr");

		constexpr glm::ivec4 D = +A;
		static_assert(D == A, "GLM: Failed constexpr");
	}

	{
		constexpr glm::ivec4 A(3);
		constexpr glm::ivec4 B = A - 1;
		constexpr glm::ivec4 C(1);
		static_assert(A - B == C, "GLM: Failed constexpr");

		constexpr glm::ivec4 D = -A;
		static_assert(-D == A, "GLM: Failed constexpr");
	}

	{
		constexpr glm::ivec4 A(3);
		constexpr glm::ivec4 B = A * 1;
		static_assert(A == B, "GLM: Failed constexpr");

		constexpr glm::ivec4 C(1);
		static_assert(B * C == A, "GLM: Failed constexpr");
	}

	{
		constexpr glm::ivec4 A(3);
		constexpr glm::ivec4 B = A / 1;
		static_assert(A == B, "GLM: Failed constexpr");

		constexpr glm::ivec4 C(1);
		static_assert(B / C == A, "GLM: Failed constexpr");
	}

	return Error;
}

static int test_quat()
{
	int Error = 0;

	{
		static_assert(glm::quat::length() == 4, "GLM: Failed constexpr");
		static_assert(glm::quat(1.0f, glm::vec3(0.0f)).w > 0.0f, "GLM: Failed constexpr");
		static_assert(glm::quat(1.0f, 0.0f, 0.0f, 0.0f).w > 0.0f, "GLM: Failed constexpr");

		glm::quat constexpr Q = glm::identity<glm::quat>();
		static_assert(Q.x - glm::quat(1.0f, glm::vec3(0.0f)).x <= glm::epsilon<float>(), "GLM: Failed constexpr");
	}

	return Error;
}

static int test_mat2x2()
{
	int Error = 0;

	static_assert(glm::mat2x2::length() == 2, "GLM: Failed constexpr");

	return Error;
}

#endif//GLM_CONFIG_CONSTEXP == GLM_ENABLE

int main()
{
	int Error = 0;

#	if GLM_CONFIG_CONSTEXP == GLM_ENABLE
		Error += test_vec1();
		Error += test_vec2();
		Error += test_vec3();
		Error += test_vec4();
		Error += test_quat();
		Error += test_mat2x2();
#	endif//GLM_CONFIG_CONSTEXP == GLM_ENABLE

	return Error;
}

