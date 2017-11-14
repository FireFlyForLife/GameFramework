#include "Matrix.h"
#include "Catch2/catch.hpp"

#include <iostream>

#include "ToString.h"

using namespace std;

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


}