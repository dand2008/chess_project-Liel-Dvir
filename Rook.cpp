#include "Rook.h"

bool Rook::checkMove(Piece* board[8][8], Piece* destination) const
{
	if (this->getX() == destination->getX())
	if (this->getX() == destination->getX())
	{
		int start = std::min(this->getY(), destination->getY());
		int end = std::max(this->getY(), destination->getY());

		for (int y = start; y < end; ++y)
		{
			if (board[y][this->getX()]->getType() != EMPTY)
			{
				return false;
			}
		}
		return true;
	}
	if (this->getY() == destination->getY())
	{
		int start = std::min(this->getX(), destination->getX());
		int end = std::max(this->getX(), destination->getX());

		for (int x = start; x < end; ++x)
		{
			if (board[this->getY()][x]->getType() != EMPTY)
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