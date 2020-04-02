#include "Utilities.h"
#include <string>
#include <fstream>
#include <iostream>
#include <iterator>
#include <sstream>

using namespace std;

std::string FindAndReplace(std::string const& subject, std::string const& search, std::string const& replace)
{
	string s = subject;
	if (s.empty())
		return ("Subject string is empty");
	size_t start_pos = s.find(search);
	if (start_pos == std::string::npos)
		return ("There are no entries in subject string");
	while (start_pos != std::string::npos)
	{
		s.replace(start_pos, search.length(), replace);
		start_pos = s.find(search, start_pos + replace.size());
	}
	return s;
}