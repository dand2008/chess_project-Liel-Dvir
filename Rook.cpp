#include "Rook.h"

bool Rook::checkMove(Piece* board[8][8], Piece* source, Piece* destination) const
{
	int sourceX = source->getX();
	int sourceY = source->getY();
	int destinationX = destination->getX();
	int destinationY = destination->getY();
	if (sourceX == destinationX)
	{
		int start = std::min(sourceY, destinationY);
		int end = std::max(sourceY, destinationY);

		for (int y = start; y < end; ++y)
		{
			if (board[y][sourceX]->getType() != EMPTY)
			{
				return false;
			}
		}
		return true;
	}
	if (sourceY == destinationY)
	{
		int start = std::min(sourceX, destinationX);
		int end = std::max(sourceX, destinationX);

		for (int x = start; x < end; ++x)
		{
			if (board[sourceY][x]->getType() != EMPTY)
			{
				return false;
			}
		}
		return true;
	}
	else
	{
		return false;
	}
}