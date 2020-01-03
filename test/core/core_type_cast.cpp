#include <glm/gtc/constants.hpp>
#include <glm/ext/vector_relational.hpp>
#include <glm/glm.hpp>
#include <algorithm>
#include <vector>
#include <iterator>

struct my_vec2
{
	operator glm::vec2() { return glm::vec2(x, y); }
	float x, y;
};

int test_std_copy()
{
	int Error = 0;

	{
		std::vector<int> High;
		High.resize(64);
		std::vector<int> Medium(High.size());
		
		std::copy(High.begin(), High.end(), Medium.begin());

		*Medium.begin() = *High.begin();
	}

	{
		std::vector<glm::dvec4> High4;
		High4.resize(64);
		std::vector<glm::vec4> Medium4(High4.size());
		
		std::copy(High4.begin(), High4.end(), Medium4.begin());

		*Medium4.begin() = *High4.begin();
	}

	{
		std::vector<glm::dvec3> High3;
		High3.resize(64);
		std::vector<glm::vec3> Medium3(High3.size());

		std::copy(High3.begin(), High3.end(), Medium3.begin());

		*Medium3.begin() = *High3.begin();
	}

	{
		std::vector<glm::dvec2> High2;
		High2.resize(64);
		std::vector<glm::vec2> Medium2(High2.size());

		std::copy(High2.begin(), High2.end(), Medium2.begin());

		*Medium2.begin() = *High2.begin();
	}

	glm::dvec4 v1;
	glm::vec4 v2;

	v2 = v1;

	return Error;
}

int main()
{
	int Error = 0;

	Error += test_std_copy();

	return Error;
}
