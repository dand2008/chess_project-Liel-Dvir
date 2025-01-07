#include "King.h"
#include "Utils.h"

bool King::checkMove(Piece* board[8][8], Piece* destination) const
{
	// Get current position of the source piece (King)
	int sourceX = this->getX();
	int sourceY = this->getY();

	// Get pos of destination
	int destinationX = destination->getX();
	int destinationY = destination->getY();

	if (this->getColor() == destination->getColor())
	{
		return false;
	}

	if (this->getX() == destination->getX() && this->getY() == destination->getY())
	{
		return false;
	}

	// The King can move one square in any direction (horizontal, vertical, or diagonal)
	if ((sourceX == destinationX + 1 && sourceY == destinationY) ||
		(sourceX == destinationX - 1 && sourceY == destinationY) ||
		(sourceX == destinationX && sourceY == destinationY + 1) ||
		(sourceX == destinationX && sourceY == destinationY - 1) ||
		(sourceX == destinationX + 1 && sourceY == destinationY + 1) ||
		(sourceX == destinationX + 1 && sourceY == destinationY - 1) ||
		(sourceX == destinationX - 1 && sourceY == destinationY + 1) ||
		(sourceX == destinationX - 1 && sourceY == destinationY - 1))
	{
		return true; // Valid move for King
	}


    // Castling logic
	if (!this->hasMoved() && (destinationY == sourceY) && (abs(destinationX - sourceX) == 2))
	{
		std::cout << "Castling logic1\n";
		// Determine direction of castling (left or right)
		bool isKingSide = destinationX > sourceX; // King-side if destinationY > sourceY
		int rookX = isKingSide ? 7 : 0;          // Rook is either on column 0 or 7

		// Get the Rook piece
		Piece* rook = board[sourceY][rookX];
		if (rook && rook->getType() == 'R' && !rook->hasMoved())
		{
			std::cout << "Castling logic2\n";
			// Check if spaces between King and Rook are empty
			int step = isKingSide ? 1 : -1;
			for (int x = sourceX + step; x != rookX; x += step)
			{
				std::cout << "Castling logic3\n";
				if (board[sourceY][x]->getType() != '#')
				{
					std::cout << "Castling logic4 NOT GOOD\n";
					std::cout << board[sourceY][x]->getType() << "\n";
					return false; // Space is not empty
				}
			}
			std::cout << "Castling logic5\n";

			// Move the Rook to its new position
			Utils::movePiece(board, *rook, *board[sourceY][sourceX + step]);
			std::cout << "Castling logic6\n";
			return true; // Castling is valid
		}
	}
	return false;
}