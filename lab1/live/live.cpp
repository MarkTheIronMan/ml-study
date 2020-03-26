// live.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "environment.h"
#include <fstream>
#include <iostream>

struct Args
{
	string inputFileName;
	optional<string> outputFileName = nullopt;
};

optional<ofstream> GetOutputStream(const string& outputFileName)
{
	ofstream out(outputFileName);
	if (!out.is_open())
		return nullopt;
	return out;
}

optional<Args> ParseArgs(int argc, char* argv[])
{
	if ((argc != 2) && (argc != 3))
	{
		std::cout << "Invalid arguments count\n";
		std::cout << "Usage live.exe <input file name> <output file name> or just <input file name>\n";
		return nullopt;
	}
	Args args;
	args.inputFileName = argv[1];
	if (argc == 3)
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

	auto myWorld = GetWorldFromFile(args->inputFileName);

	if (!myWorld)
	{
		return 1;
	}

	if (!args->outputFileName)
	{
		PrintWorld(*myWorld, cout);
		PrintWorld(GetNewWorld(*myWorld), cout);
	}
	else
	{
		auto output = GetOutputStream(args->outputFileName.value());
		if (!output)
			return 1;
		PrintWorld(*myWorld, output.value());
		PrintWorld(GetNewWorld(*myWorld), output.value());
	}
	return 0;
}
