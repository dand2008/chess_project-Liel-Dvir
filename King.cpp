#include "King.h"

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
	return false;
}
