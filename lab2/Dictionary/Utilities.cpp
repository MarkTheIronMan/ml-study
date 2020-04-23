#include "Utilities.h"

using namespace std;

bool ReadDictionaryFile(const string input, Dictionary& dict)
{
	ifstream inputFile(input);

	if (!inputFile.is_open())
	{
		cout << "�������� ���� �� ������" << endl;
		return false;
	}
	string newWord;
	string translation;
	pair<string, string> newPair;
	while (getline(inputFile, newWord))
	{
		transform(newWord.begin(), newWord.end(), newWord.begin(), tolower);
		getline(inputFile, translation);
		transform(translation.begin(), translation.end(), translation.begin(), tolower);
		newPair = make_pair(newWord, translation);
		dict.insert(newPair);
	}

	return true;
}

void SaveDictionary(const string& out, const Dictionary& dictionary)
{
	ofstream outputFile(out);
	for (const auto& savedTranslation : dictionary)
	{
		outputFile << savedTranslation.first << endl
				   << savedTranslation.second << endl;
	}
}

void NewLine(string& userAnswer)
{
	cout << "������� ����� ��� �������� ��� '...' ��� ���������� ���������" << endl;
	getline(cin, userAnswer);
	transform(userAnswer.begin(), userAnswer.end(), userAnswer.begin(), tolower);
}

bool DialogWithUser(Dictionary& dictionary, const string& filename)
{
	string userAnswer;
	NewLine(userAnswer);
	bool newTrans = false;
	bool wereChanges = false;
	while (userAnswer != "...")
	{
		if (!IfTranslationExistsShow(dictionary, userAnswer))
		{
			wereChanges = AddNewTranslationByUser(dictionary, userAnswer);
		}
		NewLine(userAnswer);
	}
	return wereChanges ? SaveChangesInDictionary() : false;
}

bool IfTranslationExistsShow(const Dictionary& dictionary, const string& userAnswer)
{
	bool TranslationExists = false;
	for (const auto newPair : dictionary)
	{
		if (newPair.first == userAnswer)
		{
			cout << newPair.second << endl;
			TranslationExists = true;
		}

		if (newPair.second == userAnswer)
		{
			cout << newPair.first << endl;
			TranslationExists = true;
		}
	}
	return TranslationExists;
}

bool GetTranslationByUser(const string& unknownWord, string& userTranslation)
{
	cout << "����������� ����� " << unknownWord << ". ������� ������� ��� ������ ������ ��� ������" << endl;
	getline(cin, userTranslation);

	return CheckEmptyAnswer(unknownWord, userTranslation);
}

bool CheckEmptyAnswer(const string& unknownWord, string& userTranslation)
{
	if (userTranslation.empty())
	{
		cout << "����� " << unknownWord << " ���������������" << endl;
		return false;
	}
	return true;
}

bool AddNewTranslationByUser(Dictionary& dictionary, const string& userAnswer)
{
	string translation;
	if (GetTranslationByUser(userAnswer, translation))
	{
		InsertInDictionary(dictionary, userAnswer, translation);
		return true;
	}
	return false;
}

void InsertInDictionary(Dictionary& dictionary, const string& userAnswer, const string& translation)
{
	pair<string, string> newPair;
	newPair = make_pair(userAnswer, translation);
	dictionary.insert(newPair);
	cout << "����� '" << userAnswer << "' ��������� � ������� ��� '" << translation << "'" << endl;
}

bool SaveChangesInDictionary()
{
	cout << "� ������� ���� ������� ���������. ������� Y ��� y ��� ���������� ����� �������." << endl;
	string userAnswer;
	getline(cin, userAnswer);
	if ((userAnswer == "Y") || (userAnswer == "y"))
	{
		cout << "��������� ���������. �� ��������." << endl;
		return true;
	}
	return false;
}
