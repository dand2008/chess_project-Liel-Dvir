#pragma once
#include <string>
#include <iostream>
#include "Piece.h"

class Rook : public Piece
{
public:
	bool checkMove(Piece* board[8][8], Piece* destination) const;
};