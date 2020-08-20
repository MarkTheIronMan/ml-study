
#include "../../catch2/catch.hpp"
#include "../CTVSet.cpp"
#include "../CTVSet.h"
#include "../RemoteControl.h"

using namespace std;


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

TEST_CASE("Check previous channel")
{
	int ch1 = 10;
	int ch2 = 12;
	CTVSet tv;
	tv.TurnOn();
	tv.SelectChannel(ch1);
	tv.SelectChannel(ch2);
	tv.SelectPreviousChannel();
	REQUIRE(tv.GetSelectedChannel() == ch1);
}

TEST_CASE("Check channel name existance")
{
	string name = "OPT";
	int ch = 1;
	CTVSet tv;
	tv.TurnOn();
	tv.SetChannelName(ch, name);
	REQUIRE(tv.GetChannelName(ch, name) == true);
}