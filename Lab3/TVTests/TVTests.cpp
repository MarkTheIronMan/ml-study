
#include "../CTVSet.h"
#include "../CTVSet.cpp"
#include "../RemoteControl.h"
#include "../../catch2/catch.hpp"

using namespace std;
/*
stringstream input;

void SetInput(string str1, stringstream& stream = input)
{
	stream.clear();
	stream << str1;
}
*/

TEST_CASE("TurnOn test")
{
	CTVSet tv;
	REQUIRE(tv.IsTurnedOn() == false);
	REQUIRE(tv.GetSelectedChannel() == 0);
}

TEST_CASE("SelectChannel test")
{
	int chan = 12;
	CTVSet tv;
	tv.TurnOn();
	REQUIRE(tv.SelectChannel(chan) == true);
}

TEST_CASE("SelectChannel test out of range")
{
	int chan = 100;
	CTVSet tv;
	tv.TurnOn();
	REQUIRE(tv.SelectChannel(chan) == false);
}
