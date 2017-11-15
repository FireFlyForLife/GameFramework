#include "Matrix.h"
#include "Catch2/catch.hpp"

#include <iostream>

#include "ToString.h"

using namespace std;

//TODO: Write actual tests
TEST_CASE("Matrix")
{
	Matrix<3> matrix1{
		{3, 2, 4},
		{1, 9, 7},
		{6, 3, 2}
	};
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
