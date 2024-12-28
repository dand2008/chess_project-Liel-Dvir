#pragma once
#include <string>
#include <iostream>
#include "Piece.h"

class Rook : public Piece
{
public:
	using Piece::Piece;
	virtual bool checkMove(Piece* board[8][8], Piece* destination) const;
};