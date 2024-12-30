#pragma once
#include "Piece.h"
#include "Bishop.h"
#include "Rook.h"

class Queen : public Bishop, public Rook
{
public:
	Queen(char p, int row, int col);
	bool checkMove(Piece* board[8][8], Piece* source, Piece* destination) const override;
};