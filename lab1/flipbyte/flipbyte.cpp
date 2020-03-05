// flipbyte.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.

#include <iostream>
#include <optional>
#include <string>

using namespace std;

optional<int> ParseArg(int argc, char* argv[])
{
	if (argc != 2)
	{
		cout << "Incorrect number of arguments" << endl;
		return nullopt;
	}

	int number;

	try
	{
		number = stoi(argv[1]);
	}
	catch (const invalid_argument& e)
	{
		cout << "Error: " << e.what() << ". Argument must be a number" << endl;
		return nullopt;
	}
	catch (const exception& e)
	{
		cout << "Error: " << e.what() << endl;
		return nullopt;
	}
	if ((number > UINT8_MAX) || (number < 0))
	{
		return nullopt;
	}
	return number;
}

uint8_t FlipByte(uint8_t number)
{
	uint8_t result = 0;

	for (int i = 0; i < 8; ++i)
	{
		result |= (number & 1) << (7 - i);
		number >>= 1;
	}

	return result;
}


int main(int argc, char* argv[])
{
	auto arg = ParseArg(argc, argv);

	if (!arg)
	{
		cout << "Invalid argument! \n Usage: flipbyte.exe <number in range 0..255>\n";
		return 1;
	}

	uint8_t byteNumber = static_cast<uint8_t>(*arg);
	int newNumber = FlipByte(byteNumber);
	cout << newNumber << endl;

	return 0;
}
