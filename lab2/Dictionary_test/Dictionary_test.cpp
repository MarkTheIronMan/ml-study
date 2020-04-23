// Dictionary_test.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <sstream>
#define CATCH_CONFIG_MAIN
#include "../../catch2/catch.hpp"
#include "../Dictionary/Utilities.h"

TEST_CASE("ReadDictionaryFile() for no file must return false")
{
	std::string input = "";
	bool test = false;
	bool result;
	Dictionary dict;
	result = ReadDictionaryFile(input, dict);
	REQUIRE(result == test);
}

TEST_CASE("CheckEmptyAnswer() for empty answer must return false")
{
	std::string input = "";
	bool test = false;
	bool result;
	std::string word;
	result = CheckEmptyAnswer(word, input);
	REQUIRE(result == test);
}

TEST_CASE("IfTranslationExistsShow() must return true if translation is in dictionary")
{
	std::string word = "dog";
	bool test = true;
	bool result;
	Dictionary dict = { { "dog", "собака" } };
	result = IfTranslationExistsShow(dict, word);
	REQUIRE(result == test);
}
