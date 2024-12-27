#include "Engine.h"
#include "Rook.h"
#include "Pawn.h"

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

void Engine::displayBoard() const
{
	_board.displayBoard();
}

char* Engine::getCode(string move)
{
	static char code[2] = { 0 };
	int* coords = nullptr;
	// get source and destination from the string
	try
	{
		coords = Utils::fetchMove(move);
	}
	catch (const std::string& e)
	{
		std::cout << e;
		code[0] = '5';
		delete[] coords;
		return code;
	}

	Piece& source = _board.getPiece(coords[0], coords[1]);
	Piece& destination = _board.getPiece(coords[2], coords[3]);

	//std::cout << source.getType() << std::endl;

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
			Pawn p;
			std::cout << "ERROR: Invalid move for a Pawn!\n";
			return false;
		}
    }
    // Add checks for other piece types here (e.g., Knight, Bishop, Queen, King)
    else
    {
        std::cout << "ERROR: Unsupported piece type!\n";
        return false;
    }
    return true; // Ensure a return value on all paths
}