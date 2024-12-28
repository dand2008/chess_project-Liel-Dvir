#pragma once
#include "Piece.h"
#include "Bishop.h"
#include "Rook.h"

class Queen : public Piece, public Bishop, public Rook
{
public:
	using Piece::Piece;
	bool checkMove(Piece* board[8][8], Piece* source, Piece* destination) const override;
};