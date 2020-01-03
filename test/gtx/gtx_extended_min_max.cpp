#define GLM_ENABLE_EXPERIMENTAL

#include <glm/gtx/extended_min_max.hpp>
#include <glm/gtc/constants.hpp>
#include <glm/ext/scalar_relational.hpp>
#include <glm/ext/vector_relational.hpp>

// This file has divisions by zero to test isnan
#if GLM_COMPILER & GLM_COMPILER_VC
#	pragma warning(disable : 4723)
#endif

namespace fmin_
{
	static int test()
	{
		int Error = 0;

		glm::vec2 B0 = glm::fmin(glm::vec2(1), glm::vec2(1));
		glm::vec2 B1 = glm::fmin(glm::vec2(1), 1.0f);
		bool B2 = glm::all(glm::equal(B0, B1, glm::epsilon<float>()));
		Error += B2 ? 0 : 1;

		glm::vec3 C0 = glm::fmin(glm::vec3(1), glm::vec3(1));
		glm::vec3 C1 = glm::fmin(glm::vec3(1), 1.0f);
		bool C2 = glm::all(glm::equal(C0, C1, glm::epsilon<float>()));
		Error += C2 ? 0 : 1;

		glm::vec4 D0 = glm::fmin(glm::vec4(1), glm::vec4(1));
		glm::vec4 D1 = glm::fmin(glm::vec4(1), 1.0f);
		bool D2 = glm::all(glm::equal(D0, D1, glm::epsilon<float>()));
		Error += D2 ? 0 : 1;

		return Error;
	}
}//namespace fmin_

namespace fmax_
{
	static int test()
	{
		int Error = 0;

		glm::vec2 B0 = glm::fmax(glm::vec2(1), glm::vec2(1));
		glm::vec2 B1 = glm::fmax(glm::vec2(1), 1.0f);
		bool B2 = glm::all(glm::equal(B0, B1, glm::epsilon<float>()));
		Error += B2 ? 0 : 1;

		glm::vec3 C0 = glm::fmax(glm::vec3(1), glm::vec3(1));
		glm::vec3 C1 = glm::fmax(glm::vec3(1), 1.0f);
		bool C2 = glm::all(glm::equal(C0, C1, glm::epsilon<float>()));
		Error += C2 ? 0 : 1;

		glm::vec4 D0 = glm::fmax(glm::vec4(1), glm::vec4(1));
		glm::vec4 D1 = glm::fmax(glm::vec4(1), 1.0f);
		bool D2 = glm::all(glm::equal(D0, D1, glm::epsilon<float>()));
		Error += D2 ? 0 : 1;

		return Error;
	}
}//namespace fmax_

int main()
{
	int Error = 0;

	Error += fmin_::test();
	Error += fmax_::test();

	return Error;
}
