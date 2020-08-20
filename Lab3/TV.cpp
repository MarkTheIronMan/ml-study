#include "CTVSet.h"
#include "RemoteControl.h"

int main()
{
	CTVSet tv;
	CRemoteControl remoteControl(tv, std::cin);

	while (!std::cin.eof() && !std::cin.fail())
	{
		std::cout << "> ";
		if (!remoteControl.HandleCommand())
		{
			std::cout << "Unknown command!" << std::endl;
		}
	}

	return 0;
}