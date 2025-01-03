#include "Knight.h"

bool Knight::checkMove(Piece* board[8][8], Piece* destination) const
{
	// Get the current position of the source piece (Knight)
	int sourceX = this->getX();
	int sourceY = this->getY();

	// Get the position of the destination
	int destinationX = destination->getX();
	int destinationY = destination->getY();

	if (this->getColor() == destination->getColor())
	{
		return false;
	}


	// Check if move matches the "L-shape" pattern of a Knight's movement
   // A Knight moves two squares in one direction and one square perpendicular to it.
	if ((sourceX == destinationX + 1 && sourceY == destinationY + 2) ||
		(sourceX == destinationX + 1 && sourceY == destinationY - 2) ||
		(sourceX == destinationX - 1 && sourceY == destinationY + 2) ||
		(sourceX == destinationX - 1 && sourceY == destinationY - 2) ||
		(sourceX == destinationX + 2 && sourceY == destinationY + 1) ||
		(sourceX == destinationX + 2 && sourceY == destinationY - 1) ||
		(sourceX == destinationX - 2 && sourceY == destinationY + 1) ||
		(sourceX == destinationX - 2 && sourceY == destinationY - 1))
	{
		return true; // Valid move for Knight
	}
	return false;
}
