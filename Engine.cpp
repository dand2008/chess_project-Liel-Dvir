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

void Engine::displayBoard() const
{
	_board.displayBoard();
}

char* Engine::getCode(string move)
{
	static char code[2] = { 0 };
	int* coords = nullptr;
	
	// get source and destination from the string
	try { coords = Utils::fetchMove(move); }
	catch (const std::string& e)
	{
		std::cout << e;
		code[0] = '5';
		delete[] coords;
		return code;
	}

	Piece& source = _board.getPiece(coords[1], coords[0]);
	Piece& destination = _board.getPiece(coords[3], coords[2]);

	/* The move validity check order is as follows:
	*  1. Check if move string is legit
	*  2. Check if moved piece is the current player's piece
	*  3. Check if source and destination pieces are the same
	*  4. Check if destination piece is the current player's piece
	*  5. Check if moved piece can move in this path
	*/

	// check input validity
	if (move[0] < 'a' || move[0] > 'h' ||
		move[1] < '1' || move[1] > '8' ||
		move[2] < 'a' || move[2] > 'h' ||
		move[3] < '1' || move[3] > '8')
	{
		code[0] = '5';
	}
	// check if the source piece belongs to the current player
	else if (!(_currentPlayer == WHITE && source.getColor() == WHITE) &&
			 !(_currentPlayer == BLACK && source.getColor() == BLACK))
	{
		code[0] = '2';
	}
	// check if the destination is the same as the source
	else if (source == destination)
	{
		code[0] = '7';
	}
	// check if the piece lands on the any of the current player's pieces
	else if ((_currentPlayer == WHITE && destination.getColor() == WHITE) ||
			 (_currentPlayer == BLACK && destination.getColor() == BLACK))
	{
		code[0] = '3';
	}

	// After all source/destination checks, check if the piece can move like wanted
	else if (!checkPieceMove(_board.getBoard(), source, destination))
	{
		code[0] = '6';
	}

	// Tests passed! Yay!!
	else
	{
		Utils::movePiece(source, destination, _currentPlayer);
		code[0] = '0';
	}

	delete[] coords;
	return code;
}

// Improved checkPieceMove function
bool Engine::checkPieceMove(Piece board[8][8], Piece source, Piece destination)
{
    char piece = tolower(source.getType());
    if (piece == 'r')
    {
        Rook r;
        if (!r.checkMove(board, source, destination))
        {
            std::cout << "ERROR: Invalid move for a Rook!\n";
            return false;
        }
    }
    else if (piece == 'p')
    {
        Pawn p;
        if (!p.checkMove(board, source, destination))
	    {
			std::cout << "ERROR: Invalid move for a Pawn!\n";
			return false;
		}
    }
	else if (piece == 'b')
	{
		Bishop b;
		if (!b.checkMove(board, source, destination))
		{
			std::cout << "ERROR: Invalid move for a Bishop!\n";
			return false;
		}
	}
	else if (piece == 'q')
	{
		Queen q;
		if (!q.checkMove(board, source, destination))
		{
			std::cout << "ERROR: Invalid move for a Queen!\n";
			return false;
		}
	}
	else if (piece == 'n')
	{
		Knight n;
		if (!n.checkMove(board, source, destination))
		{
			std::cout << "ERROR: Invalid move for a Knight!\n";
			return false;
		}
	}
	else if (piece == 'k')
	{
		King k;
		if (!k.checkMove(board, source, destination))
		{
			std::cout << "ERROR: Invalid move for a King!\n";
			return false;
		}
	}
    // Add checks for other piece types here (King)
    else
    {
        std::cout << "ERROR: Unsupported piece type!\n";
        return false;
    }
    return true; // Ensure a return value on all paths
}