#pragma once
#include "Piece.h"
#include "Utils.h"

class King : public Piece
{
public:
	using Piece::Piece;
	bool checkMove(Piece* board[8][8], Piece* destination) const override;
};