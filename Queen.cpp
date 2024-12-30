#include "Queen.h"

Queen::Queen(char p, int row, int col)
	: Piece(p, row, col), Bishop(p, row, col), Rook(p, row, col)
{
}

bool Queen::checkMove(Piece* board[8][8], Piece* source, Piece* destination) const
{
	// A Queen can move diagonally (like a Bishop) or in straight lines (like a Rook).
	if (Bishop::checkMove(board, source, destination) ||
		Rook::checkMove(board, source, destination))
	{
		return true; // Valid move for the Queen
	}
	return false;
}
