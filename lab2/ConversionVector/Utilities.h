#pragma once
#include <algorithm>
#include <fstream>
#include <functional>
#include <iostream>
#include <iterator>
#include <sstream>
#include <string>
#include <vector>

void ReadVector(std::vector<double>& v, std::istream& input);
double GetSumOfPosNums(const std::vector<double>& v);
void ConversionVector(std::vector<double>& v);
void SortVector(std::vector<double>& v);
void PrintVector(std::vector<double>& v);