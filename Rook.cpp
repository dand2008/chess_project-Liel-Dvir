#include "Rook.h"

bool Rook::checkMove(Piece* board[8][8], Piece* destination) const
{
	int sourceX = this->getX();
	int sourceY = this->getY();
	int destinationX = destination->getX();
	int destinationY = destination->getY();
	
	int dx = std::abs(destinationX - sourceX);
	int dy = std::abs(destinationY - sourceY);

	if (dx != 0 && dy != 0)
	{
		return false;
	}

	int stepX = (destinationX == sourceX) ? 0 : (destinationX > sourceX) ? 1 : -1;
	int stepY = (destinationY == sourceY) ? 0 : (destinationY > sourceY) ? 1 : -1;

	int currentX = sourceX + stepX;
	int currentY = sourceY + stepY;

	while (currentX != destinationX || currentY != destinationY)
	{
		if (board[currentY][currentX]->getType() != EMPTY)
		{
			return false; // Path is blocked
		}
		currentX += stepX;
		currentY += stepY;
	}

	return true;
}
