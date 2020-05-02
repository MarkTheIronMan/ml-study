#include "Utilities.h"

int StringToInt(const char * str, bool& err)
{
	char* pLastChar = NULL;
	int temp = strtol(str, &pLastChar, 10);
	err = ((*str == '\0') || (*pLastChar != '\0'));

	return temp;
}

bool CheckBounds(int upperBound)
{
	if (upperBound < 1)
	{
		cout << "Bound must be greater than 1";
		return false;
	}

	if (upperBound > MAX_LIM)
	{
		cout << "Bound cannot be greater than limit";
		return false;
	}

	return true;
}

set<int> InsertPrimeNumbersInSet(const vector<bool>& numbers)
{
	set<int> primeNumbers;
	for (size_t i = 2; i < numbers.size(); ++i)
	{
		if (numbers[i])
		{
			primeNumbers.insert(primeNumbers.end(), i);
		}
	}

	return primeNumbers;
}

set<int> GeneratePrimeNumbersSet(int upperBound)
{
	vector<bool> numbers(upperBound + 1, true);
	for (size_t i = 2; i * i < numbers.size(); ++i)
	{
		if (numbers[i])
		{
			for (size_t j = i * i; j < numbers.size(); j += i)
			{
				numbers[j] = false;
			}
		}
	}

	return InsertPrimeNumbersInSet(numbers);
}

void PrintPrimeNumbers(std::set<int>& primeNumbersSet)
{
	copy(primeNumbersSet.begin(), primeNumbersSet.end(), ostream_iterator<int>(cout, " "));
}