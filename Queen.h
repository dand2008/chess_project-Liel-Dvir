#pragma once
#include "Piece.h"
#include "Bishop.h"
#include "Rook.h"

class Queen : public Piece
{
public:
	using Piece::Piece;
	virtual bool checkMove(Piece* board[8][8], Piece* destination) const;
};