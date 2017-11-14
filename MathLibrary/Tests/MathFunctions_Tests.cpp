#include "MathFunctions.h"
#include "Catch2/catch.hpp"
#include <limits>

using namespace Math;

const float fepsilon = std::numeric_limits<float>::epsilon();

TEST_CASE("fequals")
{
	REQUIRE_FALSE(fequals(100.4f, 50.0f));
	REQUIRE(fequals(4464.5f / 2.0f, 4464.5f / 2.0f));
	REQUIRE(fequals(1244321.3f / 5.7f, 1244321.3f / 5.7f));
}

TEST_CASE("MoveTowards")
{
	int x = 0;
	int target = 50;
	int step = 30;

	int towards = MoveTowards(x, target, step);
	REQUIRE_FALSE(towards == 50);
	REQUIRE(towards == 30);

	float fx = 0.0f;
	float ftarget = 0.5f;
	float fstep = 0.3f;

	float ftowards = MoveTowards(fx, ftarget, fstep);
	REQUIRE_FALSE(fabs(ftowards - ftarget) < fepsilon);
	REQUIRE(fabs(ftowards - fstep) < fepsilon);
}

TEST_CASE("Clamp")
{
	int min = -15;
	int max = 15;
	REQUIRE(Clamp(10, min, max) == 10);
	REQUIRE(Clamp(-5, min, max) == -5);
	REQUIRE(Clamp(25, min, max) == 15);
	REQUIRE(Clamp(-70, min, max) == -15);
}
