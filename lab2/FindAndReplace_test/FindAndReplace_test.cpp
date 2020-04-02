// FindAndReplace_test.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <sstream>
#define CATCH_CONFIG_MAIN
#include "../../catch2/catch.hpp"
#include "../FindAndReplace/Utilities.h"

TEST_CASE("FindAndReplace() for empty string must return empty message 'Subject string is empty'")
{
	std::string input = "";
	std::string test = "Subject string is empty";
	std::string search = "search";
	std::string replace = "s";
	std::string result;
	result = FindAndReplace(input, search, replace);
	REQUIRE(result == test);
}

TEST_CASE("FindAndReplace() for non-empty string with no entries of replaced substring must return message 'Subject string is empty'")
{
	std::string input = "helloworld";
	std::string test = "There are no entries in subject string";
	std::string search = "search";
	std::string replace = "s";
	std::string result;
	result = FindAndReplace(input, search, replace);
	REQUIRE(result == test);
}

TEST_CASE("FindAndReplace() for normal case")
{
	std::string input = "helloworldhellonewday";
	std::string test = "hiworldhinewday";
	std::string search = "hello";
	std::string replace = "hi";
	std::string result;
	result = FindAndReplace(input, search, replace);
	REQUIRE(result == test);
}
