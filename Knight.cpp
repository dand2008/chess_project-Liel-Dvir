#include "Knight.h"

bool Knight::checkMove(Piece* board[8][8], Piece* source, Piece* destination) const
{
	int sourceX = source->getX();
	int sourceY = source->getY();
	int destinationX = destination->getX();
	int destinationY = destination->getY();
	if ((sourceX == destinationX + 1 && sourceY == destinationY + 2) ||
		(sourceX == destinationX + 1 && sourceY == destinationY - 2) ||
		(sourceX == destinationX - 1 && sourceY == destinationY + 2) ||
		(sourceX == destinationX - 1 && sourceY == destinationY - 2) ||
		(sourceX == destinationX + 2 && sourceY == destinationY + 1) ||
		(sourceX == destinationX + 2 && sourceY == destinationY - 1) ||
		(sourceX == destinationX - 2 && sourceY == destinationY + 1) ||
		(sourceX == destinationX - 2 && sourceY == destinationY - 1))
	{
		return true;
	}
	return false;
}

Piece* Knight::clone(Piece* destination) const
{
	return new Knight(this->getType(), destination->getY(), destination->getX());
}
