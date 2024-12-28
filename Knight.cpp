#include "Knight.h"

bool Knight::checkMove(Piece* board[8][8], Piece* destination) const
{
	int sourceX = this->getX();
	int sourceY = this->getY();
	int destinationX = destination->getX();
	int destinationY = destination->getY();
	if ((sourceX == destinationX + 1 && sourceY == destinationY + 2) ||
		(sourceX == destinationX + 1 && sourceY == destinationY - 2) ||
		(sourceX == destinationX - 1 && sourceY == destinationY + 2) ||
		(sourceX == destinationX - 1 && sourceY == destinationY - 2) ||
		(sourceX == destinationX + 1 && sourceY == destinationY + 1) ||
		(sourceX == destinationX + 1 && sourceY == destinationY - 1) ||
		(sourceX == destinationX - 1 && sourceY == destinationY + 1) ||
		(sourceX == destinationX - 1 && sourceY == destinationY - 1))
	{
		return true;
	}
	return false;
}
