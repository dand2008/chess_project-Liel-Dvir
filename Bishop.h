#pragma once
#include "Piece.h"

class Bishop : public Piece
{
public:
	using Piece::Piece;
	//bool checkMove(Piece board[8][8], Piece source, Piece destination) const;
	//virtual bool checkMove(Piece* board[8][8], Piece destination) const;
	virtual bool checkMove(Piece* board[8][8], Piece* destination) const;
};