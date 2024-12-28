#include "Rook.h"

bool Rook::checkMove(Piece board[8][8], Piece source, Piece destination) const
{
	if (source.getX() == destination.getX())
	{
		int start = std::min(source.getY(), destination.getY());
		int end = std::max(source.getY(), destination.getY());

		for (int y = start; y < end; ++y)
		{
			if (board[y][source.getX()].getType() != EMPTY)
			{
				return false;
			}
		}
		return true;
	}
	if (source.getY() == destination.getY())
	{
		int start = std::min(source.getX(), destination.getX());
		int end = std::max(source.getX(), destination.getX());

		for (int x = start; x < end; ++x)
		{
			if (board[source.getY()][x].getType() != EMPTY)
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