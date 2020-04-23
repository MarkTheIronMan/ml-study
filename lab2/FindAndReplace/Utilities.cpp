#include "Utilities.h"
#include <string>
#include <fstream>
#include <iostream>
#include <iterator>
#include <sstream>

using namespace std;

string FindAndReplace(string const& subject, string const& search, string const& replace)
{
	string s = subject;
	if (s.empty())
		return ("Subject string is empty");
	size_t start_pos = s.find(search);
	if (start_pos == string::npos)
		return ("There are no entries in subject string");
	while (start_pos != string::npos)
	{
		s.replace(start_pos, search.length(), replace);
		start_pos = s.find(search, start_pos + replace.size());
	}
	return s;
}