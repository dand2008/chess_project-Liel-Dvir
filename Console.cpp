#include "Engine.h"

using std::cout;
using std::endl;
using std::string;


int main()
{
	char msgToGraphics[1024];
	string input;

	strcpy_s(msgToGraphics, "rnbqkbnrpppppppp################################PPPPPPPPRNBQKBNR0");
	Engine e(msgToGraphics);

	std::cout << "\n" << (e.getCurrPlayer() == 'w' ? "White" : "Black") << " to move." << std::endl;
	std::cout << "Enter move (e.g. e2e4): ";
	std::cin >> input;

	while (input != "quit")
	{
		system("cls");
		char *code = e.getCode(input);
		e.displayBoard();
		switch (code[0])
		{
		case '2':
			std::cout << "ERROR: Not your piece!\n";
			break;
		case '3':
			std::cout << "ERROR: Destination square cannot be your piece!\n";
			break;
		case '5':
			std::cout << "ERROR: Invalid input!\n";
			break;
		case '6':
			break;
		case '7':
			std::cout << "ERROR: Source and Destination squares are the same!\n";
			break;

		}

		std::cout << "\n" << (e.getCurrPlayer() == 'w' ? "White" : "Black") << " to move." << std::endl;
		std::cout << "Enter move (e.g. e2e4): ";
		std::cin >> input;
	}
	return 0;
}