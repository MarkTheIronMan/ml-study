// ConversionVector.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#include "Utilities.h"
#include <fstream>
#include <iostream>
#include <iterator>
#include <sstream>
#include <vector>

using namespace std;

int main()
{
	vector<double> vec;
	ReadVector(vec, cin);
	ConversionVector(vec);
	SortVector(vec);
	PrintVector(vec);
	return 0;
}
