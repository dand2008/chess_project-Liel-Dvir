#include "King.h"

bool King::checkMove(Piece* board[8][8], Piece* destination) const
{
	// Get current position of the source piece (King)
	int sourceX = this->getX();
	int sourceY = this->getY();

	// Get pos of destination
	int destinationX = destination->getX();
	int destinationY = destination->getY();

	// Check if the destination piece is of the same color
	if (this->getColor() == destination->getColor())
	{
		return false;
	}

	// Check if the destination is the same as the current position
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
		// Determine direction of castling (left or right)
		bool isKingSide = destinationX > sourceX; // King-side if destinationY > sourceY
		int rookX = isKingSide ? 7 : 0; // Rook is either on column 0 or 7

		// Get the Rook piece
		Piece* rook = board[sourceY][rookX];

		if (rook && tolower(rook->getType()) == 'r' && !rook->hasMoved()) // Rook exists and hasn't moved
		{
			// Check if spaces between King and Rook are empty
			int step = isKingSide ? 1 : -1;
			for (int x = sourceX + step; x != rookX; x += step)
			{
				if (board[sourceY][x]->getType() != EMPTY)
				{
					return false; // Space is not empty
				}
			}

			// Move the Rook to its new position
			Utils::movePiece(board, *rook, *board[sourceY][sourceX + step]);
			return true; // Castling is valid
		}
	}
	return false; // Invalid move for King
}