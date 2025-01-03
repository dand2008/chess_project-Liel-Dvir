#include "Engine.h"
#include <crtdbg.h>
#define _CRTDBG_MAP_ALLOC

using std::cout;
using std::endl;
using std::string;

void processMoveCode(char code);

int main()
{
	char setup[66];
	string input;

	strcpy_s(setup, "rnbqkbnrpppppppp################################PPPPPPPPRNBQKBNR0");
	Engine e(setup);

	std::cout << "\n" << (e.getCurrPlayer() == 'w' ? "White" : "Black") << " to move." << std::endl;
	std::cout << "Enter move (e.g. e2e4): ";
	std::cin >> input;

	while (input != "quit")
	{
		system("cls");

		char *code = e.getCode(input);

		if (code[0] == '0' || code[0] == '1' || code[0] == '8')
		{
			e.movePiece(input);
		}
		e.displayBoard();

		processMoveCode(code[0]);

		std::cout << "\n" << (e.getCurrPlayer() == 'w' ? "White" : "Black") << " to move." << std::endl;
		std::cout << "Enter move (e.g. e2e4): ";
		std::cin >> input;
	}

	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	return 0;
}

void processMoveCode(char code)
{
	switch (code)
	{
	case '1':
		std::cout << "Check!\n";
		break;
	case '2':
		std::cout << "ERROR: Not your piece!\n";
		break;
	case '3':
		std::cout << "ERROR: Destination square cannot be your piece!\n";
		break;
	case '4':
		std::cout << "ERROR: Invalid move: Move puts you in check!\n";
		break;
	case '5':
		std::cout << "ERROR: Invalid input!\n";
		break;
	case '6':
		std::cout << "ERROR: Invalid move: Path obstructed or illegal move for piece.\n";
		break;
	case '7':
		std::cout << "ERROR: Source and Destination squares are the same!\n";
		break;
	case '8':
		std::cout << "CHECKMATE!\n";
	}
}