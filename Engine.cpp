#include "Engine.h"
#include "Rook.h"
#include "Pawn.h"
#include "Bishop.h"
#include "Queen.h"
#include "Knight.h"
#include "King.h"

Engine::Engine(const char* board)
	: _board(board)
{
	_board.displayBoard();
	_currentPlayer = board[((string)board).length() - 1] == '0' ? WHITE : BLACK;
}

char Engine::getCurrPlayer() const
{
	return _currentPlayer;
}

void Engine::setCurrPlayer(char player)
{
	_currentPlayer = player;
}

void Engine::displayBoard() const
{
	_board.displayBoard();
}

void Engine::movePiece(string move)
{
	int* coords = Utils::fetchMove(move);

	// set source and destination according to coordinates
	Piece& source = _board.getPiece(coords[1], coords[0]);
	Piece& destination = _board.getPiece(coords[3], coords[2]);
	Utils::movePiece(_board.getBoard(), source, destination);
	delete[] coords;
}

char* Engine::getCode(string move)
{
	static char code[2] = { 0 };
	int* coords = nullptr;
	bool isCheckingEnemy = true;

	// get source and destination from the string
	try { coords = Utils::fetchMove(move); }
	catch (const std::string&)
	{
		code[0] = INVALID_INPUT;
		delete[] coords;
		return code;
	}

	// set source and destination according to coordinates
	Piece& source = _board.getPiece(coords[1], coords[0]);
	Piece& destination = _board.getPiece(coords[3], coords[2]);
	delete[] coords;

	// check input validity
	if (move[0] < 'a' || move[0] > 'h' ||
		move[1] < '1' || move[1] > '8' ||
		move[2] < 'a' || move[2] > 'h' ||
		move[3] < '1' || move[3] > '8')
	{
		code[0] = INVALID_INPUT;
	}

	// check if the source piece belongs to the current player
	else if (!(_currentPlayer == WHITE && source.getColor() == WHITE) &&
		!(_currentPlayer == BLACK && source.getColor() == BLACK))
	{
		code[0] = NOT_PLAYER_PIECE;
	}

	// check if the destination is the same as the source
	else if (source == destination)
	{
		code[0] = SOURCE_DESTINATION_SAME;
	}

	// check if the piece lands on the any of the current player's pieces
	else if ((_currentPlayer == WHITE && destination.getColor() == WHITE) ||
		(_currentPlayer == BLACK && destination.getColor() == BLACK))
	{
		code[0] = DESTINATION_IS_OWN_PIECE;
	}

	// After all source/destination checks, check if the piece can move legally like wanted
	else if (!source.checkMove(_board.getBoard(), &destination))
	{
		code[0] = ILLEGAL_MOVE;
	}

	// Check if the player's move puts the enemy in checkmate
	else if (Utils::isCheckmate(_board.getBoard(), source, destination))
	{
		code[0] = CHECKMATE;
	}

	// Check if the player's move puts the enemy in check
	else if (Utils::isCheck(_board.getBoard(), source, destination, isCheckingEnemy))
	{
		code[0] = CHECK;
	}

	// Check if a move puts the player in check or doesn't get them out of check
	else if (Utils::isCheck(_board.getBoard(), source, destination, !isCheckingEnemy))
	{
		code[0] = MOVE_PUTS_IN_CHECK;
	}

	// Tests passed! Yay!!
	else
	{
		code[0] = VALID_MOVE;
	}

	return code;
}