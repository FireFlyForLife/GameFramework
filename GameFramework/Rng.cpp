#include "Rng.h"
#include <ctime>
#include <random>

std::mt19937_64 mt;

void Rng::Initialize()
{
	// ReSharper disable once CppZeroConstantCanBeReplacedWithNullptr
	mt.seed(time(0));
}

int Rng::NextInt(int max)
{
	std::uniform_int_distribution<int> distribution{ 0, max };
	return distribution(mt);
}

int Rng::NextInt(int min, int max)
{
	std::uniform_int_distribution<int> distribution{ min, max };
	return distribution(mt);
}

bool Rng::NextBool()
{
	std::uniform_int_distribution<int> distribution{ false, true };
	return !!distribution(mt);
}

float Rng::NextFloat(float max)
{
	std::uniform_real_distribution<float> distribution{ 0, max };
	return distribution(mt);
}

float Rng::NextFloat(float min, float max)
{
	std::uniform_real_distribution<float> distribution{ min, max };
	return distribution(mt);
}

double Rng::NextDouble(double max)
{
	std::uniform_real_distribution<double> distribution{ 0, max };
	return distribution(mt);
}

double Rng::NextDouble(double min, double max)
{
	std::uniform_real_distribution<double> distribution{ min, max };
	return distribution(mt);
}
