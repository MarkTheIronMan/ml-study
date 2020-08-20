// Lab4.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "stdafx.h"
#include "CShapeMaker.h"
#include <fstream>
#include <iostream>

bool ReadFile(std::fstream& fileIn)
{
	if (!fileIn.is_open())
	{
		std::cout << "Input file cannot be opened." << std::endl;
		return false;
	}

	return true;
}

int main()
{
	const std::string fileIn = "input.txt";
	std::fstream inputFile(fileIn);
	if (ReadFile(inputFile))
	{
		CShapeMaker shape(inputFile, std::cout);

		while (!inputFile.eof())
		{
			if (!shape.HandleCommand())
			{
				std::cout << "Unknown command!" << std::endl;
			}
		}
	}

	return 0;
}