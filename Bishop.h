#pragma once
#include "Piece.h"

class Bishop : public Piece
{
public:
	bool checkMove(Piece board[8][8], Piece source, Piece destination) const;
};