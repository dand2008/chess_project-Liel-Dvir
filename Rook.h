#pragma once
#include <string>
#include <iostream>
#include "Piece.h"

class Rook : virtual public Piece
{
public:
	using Piece::Piece;
	bool checkMove(Piece* board[8][8], Piece* destination) const override;
};