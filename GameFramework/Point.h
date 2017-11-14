#pragma once
#include <string>
#include <type_traits>

template<typename T,
	typename = typename std::enable_if<std::is_arithmetic<T>::value, T>::type
>
struct GenericPoint
{
	using value_type = T;

	T x;
	T y;

	GenericPoint() : x(0), y(0) {}
	GenericPoint(T x, T y) : x(x), y(y){}
	GenericPoint(const GenericPoint&) = default;
	~GenericPoint(){}

	//TODO: Can I template this operator as well?
	GenericPoint operator+(const GenericPoint& point) const {
		return GenericPoint(x + point.x, y + point.y);
	}

	GenericPoint operator-(const GenericPoint& point) const {
		return GenericPoint(x - point.x, y - point.y);
	}

	GenericPoint operator*(const GenericPoint& point) const {
		return GenericPoint(x * point.x, y * point.y);
	}

	bool operator==(const GenericPoint& point) const {
		return x == point.x && y == point.y;
	}

	bool operator!=(const GenericPoint& point) const {
		return x != point.x || y != point.y;
	}

		
	//TODO: Add += -= etc operators

	///watch out for DividedByZeroException
	GenericPoint operator/(const GenericPoint& point) const {
		return GenericPoint(x / point.x, y / point.y);
	}

	std::string toStr() const
	{
		std::string txt("Point[x:" + std::to_string(x) + ", y:" + std::to_string(y) + "]");
		return txt;
	}

	//static const GenericPoint<T> zero{};
};

typedef GenericPoint<int> Point;
typedef GenericPoint<float> FPoint;
typedef GenericPoint<double> DPoint;

