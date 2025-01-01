#pragma once
#include "Piece.h"

class nullPiece : public Piece
{
	using Piece::Piece;
	bool checkMove(Piece* board[8][8], Piece* destination) const
	{
		return false;
	}
};