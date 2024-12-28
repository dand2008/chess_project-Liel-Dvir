#include "Rook.h"

bool Rook::checkMove(Piece board[8][8], Piece source, Piece destination) const
{
	if (source.getX() == destination.getX())
	{
		int minY = std::min(source.getY(), destination.getY());
		int maxY = std::max(source.getY(), destination.getY());
		if (minY == maxY - 1)
		{
			return 1;
		}

		for (int i = minY + 1; i < maxY; i++)
		{
			if (board[i][source.getX()].getType() != EMPTY)
			{
				return 0;
			}
		}
		return 1;
	}
	if (source.getY() == destination.getY())
	{
		int minX = std::min(source.getX(), destination.getX());
		int maxX = std::max(source.getX(), destination.getX());
		if (minX == maxX - 1)
		{
			return 1;
		}

		for (int i = minX + 1; i < maxX; i++)
		{
			if (board[source.getY()][i].getType() != EMPTY)
			{
				return 0;
			}
		}
		return 1;
	}
	else
	{
		return 0;
	}
}