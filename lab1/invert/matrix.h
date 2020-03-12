#pragma once
#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>

const size_t MATRIX_SIZE = 3;

using namespace std;

struct Matrix3x3
{
	double elems[MATRIX_SIZE][MATRIX_SIZE];
};

struct Matrix2x2
{
	double elems[MATRIX_SIZE - 1][MATRIX_SIZE - 1];
};

bool ReadMatrix(const std::string fileInput, Matrix3x3& matrix)
{
	ifstream inputFile(fileInput);
	if (!inputFile.is_open())
	{
		cout << "Input file cannot be opened." << endl;
		return false;
	}
	for (int row = 0; row < MATRIX_SIZE; ++row)
		{
			for (int col = 0; col < MATRIX_SIZE; ++col)
			{
				if (!(inputFile >> matrix.elems[row][col]))
				{
					return false;
				}
			}
		}
	return true;
}

double FindDeterminant(const Matrix3x3& matrix)
{
	double det = matrix.elems[0][0] * matrix.elems[1][1] * matrix.elems[2][2] + matrix.elems[1][0] * matrix.elems[2][1] * matrix.elems[0][2] + matrix.elems[2][0] * matrix.elems[0][1] * matrix.elems[1][2] - matrix.elems[2][0] * matrix.elems[1][1] * matrix.elems[0][2] - matrix.elems[1][0] * matrix.elems[0][1] * matrix.elems[2][2] - matrix.elems[0][0] * matrix.elems[2][1] * matrix.elems[1][2];
	return det;
}

double FindMinor(const Matrix3x3& matrix, int col, int row)
{
	Matrix2x2 minorMatrix;
	for (int currRow = 0; currRow < MATRIX_SIZE; currRow++)
	{
		if (currRow == row)
		{
			continue;
		}

		int minorMatrixRow = (currRow > row) ? (currRow - 1) : currRow;

		for (int currCol = 0; currCol < MATRIX_SIZE; currCol++)
		{
			if (currCol == col)
			{
				continue;
			}

			int minorMatrixCol = (currCol > col) ? (currCol - 1) : currCol;

			minorMatrix.elems[minorMatrixRow][minorMatrixCol] = matrix.elems[currRow][currCol];
		}
	}

	return pow(-1, (row + col)) * (minorMatrix.elems[0][0] * minorMatrix.elems[1][1] - minorMatrix.elems[1][0] * minorMatrix.elems[0][1]);
}

void GetInvertedMatrix(const Matrix3x3& matrix, Matrix3x3& invertedMatrix, double determinant)
{
	for (int row = 0; row < MATRIX_SIZE; ++row)
	{
		for (int col = 0; col < MATRIX_SIZE; ++col)
		{
			double minor = FindMinor(matrix, row, col);
			invertedMatrix.elems[row][col] = minor / determinant;
		}
	}
}

bool Invert(const Matrix3x3& matrix, Matrix3x3& invertedMatrix)
{
	double determinant = FindDeterminant(matrix);

	if (determinant == 0)
	{
		return false;
	}

	GetInvertedMatrix(matrix, invertedMatrix, determinant);

	return true;
}

void PrintMatrix(const Matrix3x3& matrix)
{
	cout << fixed;
	for (size_t row = 0; row < MATRIX_SIZE; ++row)
	{
		for (size_t col = 0; col < MATRIX_SIZE; ++col)
		{
			cout << setprecision(3) << matrix.elems[row][col] << " ";
		}
		cout << endl;
	}
}
