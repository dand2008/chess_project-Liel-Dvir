#pragma once
#include "Piece.h"

class Knight : public Piece
{
public:
	virtual bool checkMove(Piece* board[8][8], Piece* destination) const;
};