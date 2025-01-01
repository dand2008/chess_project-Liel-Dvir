#pragma once
#include "Piece.h"

class Bishop : virtual public Piece
{
public:
	using Piece::Piece;
	bool checkMove(Piece* board[8][8], Piece* destination) const override;
};