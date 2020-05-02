// PrimeNumbers_test.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#define CATCH_CONFIG_MAIN
#include "../../catch2/catch.hpp"
#include <iostream>
#include <sstream>
#include "../PrimeNumbers/Utilities.h"


TEST_CASE("StringToInt for some string return int")
{
	int test = 10;
	bool err;
	int result;
	result = StringToInt("10", err);
	REQUIRE(result == test);
}

TEST_CASE("Check bounds for 0 must return false")
{
	bool test = false;
	int input = 0;
	bool result;
	result = CheckBounds(input);
	REQUIRE(result == test);
}

TEST_CASE("GeneratePrimeNumbersSet() for input 10 must return set of 2 3 5 7")
{
	std::set<int> test = { 2, 3, 5, 7 };
	int input = 8;
	auto result = GeneratePrimeNumbersSet(input);
	REQUIRE(result == test);
}
