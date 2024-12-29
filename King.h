#pragma once
#include "Piece.h"

class King : public Piece
{
public:
	using Piece::Piece;
	bool checkMove(Piece* board[8][8], Piece* source, Piece* destination) const override;
	Piece* clone(Piece* destination) const override;
};