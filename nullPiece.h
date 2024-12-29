#pragma once
#include "Piece.h"

class nullPiece : public Piece
{
	using Piece::Piece;
	bool checkMove(Piece* board[8][8], Piece* source, Piece* destination) const
	{
		return false;
	}
	Piece* clone(Piece* destination) const override
	{

		return new nullPiece(EMPTY, destination->getY(), destination->getX());
	}
};