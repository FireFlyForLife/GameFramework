#pragma once

class Rng
{
public:
	static void Initialize();

	static int NextInt(int max);
	static int NextInt(int min, int max);

	static bool NextBool();

	static float NextFloat(float max);
	static float NextFloat(float min, float max);

	static double NextDouble(double max);
	static double NextDouble(double min, double max);
};
