#include "King.h"

bool King::checkMove(Piece* board[8][8], Piece* source, Piece* destination) const
{
	int sourceX = source->getX();
	int sourceY = source->getY();
	int destinationX = destination->getX();
	int destinationY = destination->getY();
	if ((sourceX == destinationX + 1 && sourceY == destinationY) ||
		(sourceX == destinationX - 1 && sourceY == destinationY) ||
		(sourceX == destinationX && sourceY == destinationY + 1) ||
		(sourceX == destinationX && sourceY == destinationY - 1) ||
		(sourceX == destinationX + 1 && sourceY == destinationY + 1) ||
		(sourceX == destinationX + 1 && sourceY == destinationY - 1) ||
		(sourceX == destinationX - 1 && sourceY == destinationY + 1) ||
		(sourceX == destinationX - 1 && sourceY == destinationY - 1))
	{
		return true;
	}
	return false;
}
