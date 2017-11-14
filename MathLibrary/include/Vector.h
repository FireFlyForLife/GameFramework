#pragma once
#include "MathFunctions.h"

class Vector
{
public:
	Vector() : x(0), y(0), z(0)
	{
	}

	float x;
	float y;
	float z;


	bool operator==(const Vector& other) const
	{
		return Math::fequals(x ,other.x)
			&& Math::fequals(y, other.y)
			&& Math::fequals(z, other.z);
	}

	bool operator!=(const Vector& other) const
	{
		return !(*this == other);
	}


	
};