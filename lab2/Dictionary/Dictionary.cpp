// Dictionary.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#include <algorithm>
#include <fstream>
#include <iostream>
#include <map>
#include <string>
#include "Utilities.h"
#include <Windows.h>
#include <locale>

using namespace std;

int main(int argc, char* argv[])

{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	if (argc != 2)
	{
		cout << "Incorrect number of arguments" << endl;
		cout << "You should use << dictionary.exe <dictionary file> >>" << endl;
		return 1;
	}

	const string input = argv[1];
	Dictionary dictionary;
	if (!ReadDictionaryFile(input, dictionary))
	{
		return 1;
	}

	bool saveChanges = DialogWithUser(dictionary, input);
	if (saveChanges)
	{
		SaveDictionary(input, dictionary);
	}
	return 0;
}
