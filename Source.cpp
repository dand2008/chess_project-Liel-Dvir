#include "Source.h"

void processMoveCode(char code);

void console()
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

		system("cls");

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
}

void gui()
{
	srand(time_t(NULL));

	system("start chessGraphics.exe");
	Sleep(600);


	Pipe p;
	bool isConnect = p.connect();

	string ans;
	while (!isConnect)
	{
		cout << "Cannot find an instance of ChessGraphics" << endl;
		cout << "Try to connect again or exit? (0-try again, 1-exit)" << endl;
		std::cin >> ans;

		if (ans == "0")
		{
			cout << "Trying to connect again..." << endl;
			Sleep(5000);
			isConnect = p.connect();
		}
		else
		{
			p.close();
			return;
		}
	}

	char msgToGraphics[1024];

	strcpy_s(msgToGraphics, "rnbqkbnrpppppppp################################PPPPPPPPRNBQKBNR0");

	Engine e(msgToGraphics);
	p.sendMessageToGraphics(msgToGraphics);   // send the board string

	// get message from graphics
	string msgFromGraphics = p.getMessageFromGraphics();

	while (msgFromGraphics != "quit")
	{
		char* code = e.getCode(msgFromGraphics);
		strcpy_s(msgToGraphics, code);

		if (code[0] == '0' || code[0] == '1' || code[0] == '8')
		{
			e.movePiece(msgFromGraphics);
			e.setCurrPlayer(e.getCurrPlayer() == WHITE ? BLACK : WHITE);
		}
		// return result to graphics
		p.sendMessageToGraphics(msgToGraphics);

		// get message from graphics
		msgFromGraphics = p.getMessageFromGraphics();
	}

	p.close();
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