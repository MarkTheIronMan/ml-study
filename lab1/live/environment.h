#pragma once
#include <fstream>
#include <iomanip>
#include <iostream>
#include <set>
#include <string>

const size_t MAX_SIZE = 256;

using namespace std;

set<char> forms = { ' ', '*', '#' };

struct world
{
	char elems[MAX_SIZE][MAX_SIZE];
	size_t colMax;
	size_t rowMax;
};

void PrintWorld(const world& currWorld)
{
	for (size_t row = 0; row < currWorld.rowMax; ++row)
	{
		for (size_t col = 0; col < currWorld.colMax; ++col)
		{
			cout <<  currWorld.elems[row][col];
		}
		cout << endl;
	}
}