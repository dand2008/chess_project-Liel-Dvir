#pragma once
#include <string>
#include <iostream>
#include "Piece.h"

class Pawn : public Piece
{
public:
	using Piece::Piece;
	bool checkMove(Piece* board[8][8], Piece* source, Piece* destination) const override;
};