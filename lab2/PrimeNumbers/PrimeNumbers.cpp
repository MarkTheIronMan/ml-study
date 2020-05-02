// PrimeNumbers.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "Utilities.h"
#include <algorithm>
#include <fstream>
#include <iostream>
#include <set>
#include <string>
#include <vector>
#include <ctime>
#include <chrono>

int main(int argc, char* argv[])
{
	if (argc != 2)
	{
		cout << "Wrong number of arguments." << endl;
		cout << "Usage < PrimeNumbers.exe <upper bound> >" << endl;
		return 1;
	}

	bool error;
	int upperBound = StringToInt(argv[1], error);

	if (error)
	{
		cout << "Wrong type of argument" << endl;
		return 1;
	}

	if (!CheckBounds(upperBound))
	{
		return 1;
	}
	
	chrono::time_point<chrono::system_clock> start, end;
	start = chrono::system_clock::now();

	auto primeNumbersSet = GeneratePrimeNumbersSet(upperBound);

	end = chrono::system_clock::now();
	int elapsed_seconds = chrono::duration_cast<chrono::seconds>(end - start).count();
	cout << "Time elapsed: " << elapsed_seconds << " seconds" << endl;
	PrintPrimeNumbers(primeNumbersSet);
	return 0;
}
