#include "Source.h"
#include <crtdbg.h>
#define _CRTDBG_MAP_ALLOC

int main(int argc, char** argv)
{
	if (argc != 2)
	{
		std::cerr << "Error: Invalid arguments.\n";
		std::cerr << "Usage: " << argv[0] << " -g (gui) / -c (console)\n";
		return 1; // Return non-zero exit code to indicate failure
	}
	if (!strcmp(argv[1], "-g"))
	{
		gui();
	}
	else if (!strcmp(argv[1], "-c"))
	{
		console();
	}
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	return 0;
}