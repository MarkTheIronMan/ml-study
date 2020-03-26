// invert.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "stdafx.h"
#include "matrix.h"


int main(int argc, char* argv[])
{
	if (argc != 2)
	{
		cout << "Wrong number of arguments." << endl;
		cout << "Usage: invert.exe <input file>" << endl;
		return 1;
	}

	Matrix3x3 matrix;
	const string inputFile = argv[1];
	if (!ReadMatrix(inputFile, matrix))
	{
		cout << "Cannot read input matrix." << endl;
		return 1;
	}

	Matrix3x3 invertedMatrix;
	if (!Invert(matrix, invertedMatrix))
	{
		return 1;
	}

	PrintMatrix(invertedMatrix);

	return 0;
}
