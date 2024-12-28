#pragma once
#include "Piece.h"

class Knight : public Piece
{
public:
	bool checkMove(Piece* board[8][8], Piece* destination) const;
};