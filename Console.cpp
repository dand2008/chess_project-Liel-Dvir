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

	char* code = nullptr;

	do
	{
		std::cout << "\n" << (e.getCurrPlayer() == WHITE ? "White" : "Black") << " to move." << std::endl;
		std::cout << "Enter move (e.g. e2e4): ";
		std::cin >> input;

		//system("cls");

		code = e.getCode(input);

		if (code[0] == VALID_MOVE || code[0] == CHECK || code[0] == CHECKMATE)
		{
			e.movePiece(input);
			if (code[0] != CHECKMATE)
			{
				// Switch current player
				e.setCurrPlayer(e.getCurrPlayer() == WHITE ? BLACK : WHITE);
			}
		}

		e.displayBoard();

		processMoveCode(code[0]);

	} while (input != "q" && code[0] != CHECKMATE);

	std::cout << (e.getCurrPlayer() == WHITE ? "White" : "Black") << " wins!";

	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	return 0;
}

void processMoveCode(char code)
{
	switch (code)
	{
	case CHECK:
		std::cout << "Check!\n";
		break;
	case NOT_PLAYER_PIECE:
		std::cout << "ERROR: Not your piece!\n";
		break;
	case DESTINATION_IS_OWN_PIECE:
		std::cout << "ERROR: Destination square cannot be your piece!\n";
		break;
	case MOVE_PUTS_IN_CHECK:
		std::cout << "ERROR: Invalid move: Move puts you in check!\n";
		break;
	case INVALID_INPUT:
		std::cout << "ERROR: Invalid input!\n";
		break;
	case ILLEGAL_MOVE:
		std::cout << "ERROR: Invalid move: Path obstructed or illegal move for piece.\n";
		break;
	case SOURCE_DESTINATION_SAME:
		std::cout << "ERROR: Source and Destination squares are the same!\n";
		break;
	case CHECKMATE:
		std::cout << "CHECKMATE!\n";
	}
}