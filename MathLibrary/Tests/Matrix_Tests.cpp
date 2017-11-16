#include "Matrix.h"
#include "Catch2/catch.hpp"

#include <iostream>

#include "ToString.h"
#include "Vector.h"

using namespace std;
using namespace Math;

//TODO: Write actual tests
TEST_CASE("Matrix")
{
	Matrix<3> matrix1({
		{3, 2, 4},
		{1, 9, 7},
		{6, 3, 2}
	});
	cout << "matrix1:\n" << Math::ToString(matrix1) << endl;

	Matrix<3> matrix2{
		{ 1, 2, 7 },
		{ 3, 4, 2 },
		{ 2, 9, 4 }
	};
	cout << "matrix2:\n" << Math::ToString(matrix2) << endl;


	Matrix<3> addition_matrix = matrix1 + matrix2;
	cout << Math::ToString(addition_matrix) << endl;
	Matrix<3> subtracktion_matrix = matrix1 - matrix2;
	cout << Math::ToString(subtracktion_matrix) << endl;

	Matrix<3, 2> hori_matrix {
		{ 3, 2, 3},
		{4, 1, 2}
	};

	Matrix<2, 3> vert_matrix{
		{ 1, 5 },
		{ 3, 2},
		{6, 2 }
	};

	cout << "hori_matrix\n" << Math::ToString(hori_matrix) << endl;
	cout << "vert_matrix\n" << Math::ToString(vert_matrix) << endl;

	auto multiplication_matrix = hori_matrix * vert_matrix;
	cout << Math::ToString(multiplication_matrix) << endl;


}

template<unsigned w, unsigned h>
static void PrintMatrix(const Matrix<w, h>& m, const string* name = nullptr)
{
	if(name)
		cout << *name << Math::ToString(m) << endl;
	else
		cout << Math::ToString(m) << endl;

}

TEST_CASE("Matrix equality")
{
	Matrix<1> m1{ {2} };
	Matrix<1> m2{ {3} };
	Matrix<1> m3{ {2} };

	bool b = (m1 == m2);
	REQUIRE_FALSE(b);
	PrintMatrix(m1);
	PrintMatrix(m2);

	PrintMatrix(m3);
	b = (m1 == m3);
	REQUIRE(b);

	Matrix<2> m4{ {2, 3},{4, 5} };
	Matrix<2> m5{ {6, 7}, {8, 9} };
	Matrix<2> m6{ {2, 3}, {4, 5} };
	PrintMatrix(m4);
	PrintMatrix(m5);
	PrintMatrix(m6);

	b = m1 == m4;
	REQUIRE_FALSE(b);
	b = (m4 == m5);
	REQUIRE_FALSE(b);
	b = (m4 == m6);
	REQUIRE( b);

	Matrix<1, 2> m7{ 
		{2}, 
		{5} 
	};

	Vector2 vec{ 2, 5 };
	b = m7 == vec;
	REQUIRE(b);

	float fx = vec.x;
	float fy = vec.y;
	REQUIRE(fequals(fx, 2));
	REQUIRE(fequals(fy, 5));
}

//template<int m, int n>
//struct meme
//{
//	float x, y;
//
//	//meme(std::initializer_list<std::initializer_list<float>> meem) {}
//
//	meme(float (&meem)[m][n]) : x(meem[0]), y(meem[1])
//	{
//		cout << m << " " << n << endl;
//	}
//};
//
//TEST_CASE("DWA")
//{
//	meme<3, 3> m({ { {1.f, 2.f, 3.f}, {4.f, 4.f, 4.f}, {1.f, 1.f, 1.f} } });
//	
//}
