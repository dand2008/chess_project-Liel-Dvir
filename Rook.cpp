#include "Rook.h"

bool Rook::checkMove(Piece* board[8][8], Piece* source, Piece* destination) const
{
	int startX = std::min(source->getX(), destination->getX());
	int endX = std::max(source->getX(), destination->getX());
	int startY = std::min(source->getY(), destination->getY());
	int endY = std::max(source->getY(), destination->getY());
	if (source->getX() == destination->getX())
	{
		for (int y = startY + 1; y < endY; y++)
		{
			if (board[y][source->getX()]->getType() != EMPTY)
			{
				return false;
			}
		}
		return true;
	}
	if (source->getY() == destination->getY())
	{
		for (int x = startX + 1; x < endX; x++)
		{
			if (board[source->getY()][x]->getType() != EMPTY)
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