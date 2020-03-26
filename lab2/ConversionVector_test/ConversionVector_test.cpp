// ConversionVector_test.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <sstream>
#define CATCH_CONFIG_MAIN
#include "../../catch2/catch.hpp"
#include "../ConversionVector/Utilities.h"

TEST_CASE("ConversionVector() for empty vector must return empty vector")
{
	std::vector<double> emptyVec;
	ConversionVector(emptyVec);
	REQUIRE(emptyVec.empty());
}

TEST_CASE("GetSumOfPosNums() should return a sum of positive numbers in vector")
{
	std::vector<double> testvector{ -1, -2, -3, -4 };
	REQUIRE(GetSumOfPosNums(testvector) == 0);
}

TEST_CASE("ConversionVector() should double every even element and substracted sum of all positive elements of vector from every non-even element")
{
	std::vector<double> testvector{ -9, 4, -7, 8 };
	std::vector<double> testedvector{ 1, 2, 3, 4 };
	ConversionVector(testedvector);
	REQUIRE(testedvector == testvector);
}

TEST_CASE("SortVector() should sort elements in vector")
{
	std::vector<double> testvector{ 1, 2, 3, 4 };
	std::vector<double> testedvector{ 2, 1, 4, 3 };
	SortVector(testedvector);
	REQUIRE(testedvector == testvector);
}