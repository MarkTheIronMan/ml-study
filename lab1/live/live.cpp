// live.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <fstream>
#include <optional>
#include "environment.h"

struct Args
{
	std::string inputFileName;
	std::string outputFileName;
};

optional<Args> ParseArgs(int argc, char* argv[])
{
	if ((argc != 2)&&(argc != 3))
	{
		std::cout << "Invalid arguments count\n";
		std::cout << "Usage live.exe <input file name> <output file name> or just <input file name>\n";
		return std::nullopt;
	}
	Args args;
	args.inputFileName = argv[1];
	args.outputFileName = argv[2];
	return args;
}

int main(int argc, char* argv[])
{
	auto args = ParseArgs(argc, argv);
	if (!args)
	{
		return 1;
	}
}
