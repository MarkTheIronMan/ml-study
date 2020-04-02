// FindAndReplace.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#include "Utilities.h"
#include <fstream>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <sstream>
#include <vector>
#include <string>

using namespace std;

struct Args
{
	string searchString;
	string strToReplace;
};

optional<Args> ParseArgs(int argc, char* argv[])
{
	if (argc != 3)
	{
		cout << "Invalid arguments count\n";
		return nullopt;
	}
	Args args;
	args.searchString = argv[1];
	args.strToReplace = argv[2];
	return args;
}


int main(int argc, char* argv[])
{
	auto args = ParseArgs(argc, argv);
	string str;
	string input;
	cin >> input;
	str = FindAndReplace(input, args->searchString, args->strToReplace);
	cout << str << endl;
}
