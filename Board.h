#pragma once
#include <string>
#include <vector>

#include "Piece.h"
#include "Rook.h"
#include "Pawn.h"
#include "Bishop.h"
#include "Queen.h"
#include "Knight.h"
using std::string;

class Board
{
public:
	Board(const char* board);
	Piece* getPiece(int row, int col);
	void displayBoard() const;
	Piece* (&getBoard())[8][8];
private:
	Piece* _board[8][8];
};