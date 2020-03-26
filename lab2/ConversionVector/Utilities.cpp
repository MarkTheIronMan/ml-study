#include "Utilities.h"
#include <fstream>
#include <iostream>
#include <iterator>
#include <sstream>
#include <vector>
#include <iomanip>

using namespace std;

void ReadVector(vector<double>& v, istream& input)
{
	string str;
	if (getline(input, str))
	{
		stringstream iter(str);
		copy(istream_iterator<double>(iter), istream_iterator<double>(), back_inserter(v));
	}
}

double GetSumOfPosNums(const vector<double>& v)
{
	double sum = 0;
	for (double s : v)
	{
		if (s > 0)
			sum = sum + s;
	}
	return sum;
}

void ConversionVector(vector<double>& v)
{
	double sumOfPosNums = GetSumOfPosNums(v);
	bool even = false;
	for (auto& d : v)
	{
		if (even)
		{
			d *= 2;
			even = false;
		}
		else
		{
			d -= sumOfPosNums;
			even = true;
		}
	}
}

void SortVector(vector<double>& v)
{
	sort(v.begin(), v.end());
}

void PrintVector(vector<double>& v)
{
	for (double d : v)
		cout << d << " " << setprecision(3);
}