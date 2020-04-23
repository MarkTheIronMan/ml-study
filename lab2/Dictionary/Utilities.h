#pragma once

#include <algorithm>
#include <fstream>
#include <iostream>
#include <map>
#include <string>
#include <utility>


using namespace std;
typedef multimap<string, string> Dictionary;


bool ReadDictionaryFile(const string input, Dictionary& dict);
void SaveDictionary(const string& out, const Dictionary& dictionary);
bool DialogWithUser(Dictionary& dictionary, const string& filename);
bool AddNewTranslationByUser(Dictionary& dictionary, const string& userAnswer);
bool SaveChangesInDictionary();

bool IfTranslationExistsShow(const Dictionary& dictionary, const std::string& userAnswer);
bool CheckEmptyAnswer(const std::string& unknownWord, std::string& userTranslation);
void InsertInDictionary(Dictionary& dictionary, const std::string& userAnswer, const std::string& translation);
