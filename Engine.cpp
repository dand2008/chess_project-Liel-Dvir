#include "Engine.h"
#include "Rook.h"

Engine::Engine(const char* board)
	: _board(board)
{
	_board.displayBoard();
	_currentPlayer = board[((string)board).length() - 1] == '0' ? 'w' : 'b';
}

char Engine::getCurrPlayer() const
{
	return _currentPlayer;
}

char* Engine::getCode(string move)
{
	static char code[2] = { 0 };
	// get source and destination from the string
	int *coords = Utils::fetchMove(move);
	Piece& source = _board.getPiece(coords[0], coords[1]);
	Piece& destination = _board.getPiece(coords[2], coords[3]);

	//std::cout << source.getType() << std::endl;

	// check input validity
	if (move[0] < 'a' || move[0] > 'h' ||
			 move[1] < '1' || move[1] > '8' ||
			 move[2] < 'a' || move[2] > 'h' ||
			 move[3] < '1' || move[3] > '8')
	{
		std::cout << "ERROR: Invalid input!\n";
		code[0] = '5';
	}
	// check if the source piece belongs to the current player
	else if (!(_currentPlayer == 'w' && source.getColor() == 'w') && !(_currentPlayer == 'b' && source.getColor() == 'b'))
	{
		std::cout << "ERROR: Not your piece!\n";
		code[0] = '2';
	}
	// check if the destination is the same as the source
	else if (source == destination)
	{
		std::cout << "ERROR: Source and Destination squares are the same!\n";
		code[0] = '7';
	}
	// check if the piece lands on the any of the current player's pieces
	else if ((_currentPlayer == 'w' && destination.getColor() == 'w') || (_currentPlayer == 'b' && destination.getColor() == 'b'))
	{
		std::cout << "ERROR: Destination square cannot be your piece!\n";
		code[0] = '3';
	}
	// check piece move validity
	else if (tolower(source.getType()) == 'r')
	{
		Rook r;
		if (r.checkMove(_board.getBoard(), source, destination))
		{
			Utils::movePiece(source, destination, _currentPlayer);
			code[0] = '0';
		}
		else
		{
			std::cout << "ERROR: Invalid move for a Rook!\n";
		}
	}
	else
	{
		Utils::movePiece(source, destination, _currentPlayer);
		code[0] = '0';
	}
	_board.displayBoard();

	delete[] coords;
	return code;
}