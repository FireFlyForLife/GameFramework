#pragma once
#include <math.h>
#include <limits>
#include <string>

namespace Math {
	template<typename T>
	inline T MoveTowards(T from, T to, T maxStep) {
		T diff = to - from;
		if (diff >= 0)
			return from + fmin(diff, maxStep);
		else
			return from + fmax(diff, -maxStep);
	}

	//Clamp a the value 'val' between 'min' and 'max'
	template<typename T>
	inline T Clamp(T val, T min, T max) {
		return fmin(max, fmax(val, min));
	}

	//Alias to Math::Clamp<float>
	inline float Clampf(float val, float max, float min) {
		return Clamp<float>(val, max, min);
	}
	
	inline bool fequals(float a, float b, float epsilon = std::numeric_limits<float>::epsilon())
	{
		return fabs(a - b) < epsilon;
	}
}
