#pragma once
#include <fstream>
#include <iomanip>
#include <iostream>
#include <optional>
#include <set>
#include <string>
#include <vector>

const size_t MAX_SIZE = 256;
const size_t MIN_SIZE = 3;

using namespace std;

set<char> forms = { ' ', '*', '#' };
const char BORDER = '*';
const char ALIVE_CELL = '#';
const char DEAD_CELL = ' ';

struct World
{
	vector<string> cells;
	size_t width = 0;
};

bool AreAllSymbolsInLineCorrect(std::set<char>& myset, string str)
{
	bool result = true;
	for (size_t i = 0; i < str.length() - 1; i++)
	{
		auto it = myset.find(str[i]);
		if (it == myset.end())
		{
			result = false;
			break;
		}
	}
	return result;
}

optional<World> GetWorldFromFile(const string& inputFile)
{
	ifstream input;
	input.open(inputFile);

	if (!input.is_open())
	{
		cout << "Failed to open '" << inputFile << "' for reading\n";
		return nullopt;
	}

	if (input.bad())
	{
		cout << "Failed to read data from input file\n";
		return nullopt;
	}
	World curWorld;
	string line;
	bool isWidthWithValue = false;

	while (getline(input, line))
	{
		if ((line.length() < MIN_SIZE) && (line.length() < MAX_SIZE))
		{
			cout << "Incorrect size of world" << endl;
			return nullopt;
		}

		if (!AreAllSymbolsInLineCorrect(forms, line))
		{
			cout << "Incorrect symbol in file" << endl;
			return nullopt;
		}

		if (curWorld.width == 0)
			curWorld.width = line.length();
		curWorld.cells.push_back(line);
	}
	return curWorld;
}

size_t CountLiveCells(const World& map)
{
	size_t count = 0;
	for (string str : map.cells)
	{
		for (size_t i = 1; i < size(str) - 1; i++)
		{
			if (str[i] == ALIVE_CELL)
				count++;
		}
	}
	return count;
}

size_t CountAliveNeighbors(const World& map, size_t row, size_t col)
{
	size_t count = 0;
	string str;
	for (size_t i = row - 1; i <= row + 1; i++)
	{
		for (size_t j = col - 1; j <= col + 1; j++)
		{
			if (map.cells[i][j] == ALIVE_CELL)
			{
				count++;
			}
		}
	}
	if (map.cells[row][col] == ALIVE_CELL)
		count--;
	return count;
}

char NewCell(const World& map, size_t row, size_t col)
{
	if (map.cells[row][col] == BORDER)
		return BORDER;
	size_t NeighborsNum = CountAliveNeighbors(map, row, col);
	if ((map.cells[row][col] == DEAD_CELL) && (NeighborsNum == 3))
		return ALIVE_CELL;
	if ((map.cells[row][col] == ALIVE_CELL) && ((NeighborsNum > 3) || (NeighborsNum < 2)))
		return DEAD_CELL;
	if ((map.cells[row][col] == ALIVE_CELL) && ((NeighborsNum == 2) || (NeighborsNum == 3)))
		return ALIVE_CELL;
}

World GetNewWorld(const World& map)
{
	World newWorld;
	newWorld.width = map.width;
	for (size_t i = 0; i < size(map.cells); i++)
	{
		string str;
		for (size_t j = 0; j < map.cells[i].length(); j++)
		{
			str.insert(str.end(), NewCell(map, i, j));
		}
		newWorld.cells.push_back(str);
	}
	return newWorld;
}

void PrintWorld(const World& map, ostream& output)
{
	for (string str : map.cells)
	{
		output << str << endl;
	}
}
