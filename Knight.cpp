#include "Knight.h"

bool Knight::checkMove(Piece* board[8][8], Piece* source, Piece* destination) const
{
	// Get the current position of the source piece (Knight)
	int sourceX = source->getX();
	int sourceY = source->getY();

	// Get the position of the destination
	int destinationX = destination->getX();
	int destinationY = destination->getY();


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

Piece* Knight::clone(Piece* destination) const
{
	return new Knight(this->getType(), destination->getY(), destination->getX());
}
