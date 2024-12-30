#include "Rook.h"

bool Rook::checkMove(Piece* board[8][8], Piece* source, Piece* destination) const
{
	// Calculate the start and end positions for the potential move
	int startX = std::min(source->getX(), destination->getX());
	int endX = std::max(source->getX(), destination->getX());
	int startY = std::min(source->getY(), destination->getY());
	int endY = std::max(source->getY(), destination->getY());

	// Check if the move is vertical (same X-coordinate)
	if (source->getX() == destination->getX())
	{
		// Loop through all squares between the source and destination
		for (int y = startY + 1; y < endY; y++)
		{
			// If any square in the path is not empty, the move is invalid
			if (board[y][source->getX()]->getType() != EMPTY)
			{
				return false;
			}
		}
		return true;
	}

	// Check if the move is horizontal (same Y-coordinate)
	if (source->getY() == destination->getY())
	{
		// Loop through all squares between the source and destination
		for (int x = startX + 1; x < endX; x++)
		{
			// If any square in the path is not empty, the move is invalid
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

Piece* Rook::clone(Piece* destination) const
{
	return new Rook(this->getType(), destination->getY(), destination->getX());
}
