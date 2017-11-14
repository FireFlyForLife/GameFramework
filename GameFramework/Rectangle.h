#pragma once
#include <string>

template<typename T,
	typename = typename std::enable_if<std::is_arithmetic<T>::value, T>::type
>
struct GenericRectangle
{
	using value_type = T;

	T x;
	T y;
	T width;
	T height;

	GenericRectangle() 
		: x(0), y(0), width(0), height(0)
	{
	}

	GenericRectangle(T x, T y, T width, T height)
		: x(x), y(y), width(width), height(height)
	{
	}

	GenericRectangle(const GenericRectangle& copy) = default;

	~GenericRectangle()
	{
	}

	GenericRectangle<T> operator+(const GenericRectangle<T>& rect) const {
		return GenericRectangle<T>(x + rect.x, y + rect.y, width + rect.width, height + rect.height);
	}
	GenericRectangle<T> operator-(const GenericRectangle<T>& rect) const {
		return GenericRectangle<T>(x - rect.x, y - rect.y, width - rect.width, height - rect.height);
	}
	GenericRectangle<T> operator*(const GenericRectangle<T>& rect) const {
		return GenericRectangle<T>(x * rect.x, y * rect.y, width * rect.width, height * rect.height);
	}
	GenericRectangle<T> operator/(const GenericRectangle<T>& rect) const {
		return GenericRectangle<T>(x / rect.x, y / rect.y, width / rect.width, height / rect.height);
	}
	//TODO: Add += -= etc operators
	bool operator==(const GenericRectangle<T>& rect) const {
		return x == rect.x && y == rect.y && width == rect.width && height == rect.height;
	}

	std::string toStr() const {
		std::string txt("Rectangle[x:" + std::to_string(x) +
			" ,y:" + std::to_string(y) +
			" ,w:" + std::to_string(width) +
			" ,h:" + std::to_string(height));
		return txt;
	}
};

using Rectangle = GenericRectangle<int>;
using FRectangle = GenericRectangle<float>;
using DRectangle = GenericRectangle<double>;
