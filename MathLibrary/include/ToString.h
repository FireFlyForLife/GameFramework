#pragma once
#include <string>
#include "Matrix.h"
#include <fstream>

namespace Math
{
	namespace _Impl_
	{
		template<unsigned width, unsigned height>
		std::string toStr(const Matrix<width, height>& matrix)
		{
			return "";
		}
	}

	template<typename T>
	std::string ToString(const T& t)
	{
//#if defined(_DEBUG) && !defined(MATH_DISABLE_WARNINGS)
//		throw std::exception((std::string("Unknown Type: ") + typeid(t).name() + ". Could not convert to std::string.").c_str());
//#endif
		auto str = _Impl_::toStr(t);

		return std::string("Unknown Type: ") + typeid(t).name() + ". Could not convert to std::string.";
	}

	template<unsigned width, unsigned height>
	std::string ToString(const Matrix<width, height>& t)
	{
		std::string matrix;
		for(unsigned y = 0; y < height; y++)
		{
			std::string line = "[ ";
			for(unsigned x = 0; x < width; x++)
			{
				line += std::to_string(t[x][y]) + ' ';
			}
			line += "]\n";
			matrix += line;
		}

		return matrix;
	}

	
}
