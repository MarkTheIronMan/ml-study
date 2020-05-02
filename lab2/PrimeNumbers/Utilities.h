#pragma once

#include <algorithm>
#include <fstream>
#include <iostream>
#include <set>
#include <vector>
#include <iterator>

const int MAX_LIM = int(1E+8);

using namespace std;

int StringToInt(const char* str, bool& error);
bool CheckBounds(int upperBound);
set<int> InsertPrimeNumbersInSet(const vector<bool>& numbers);
set<int> GeneratePrimeNumbersSet(int upperBound);
void PrintPrimeNumbers(set<int>& primeNumbersSet);