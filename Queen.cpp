#include "Queen.h"

Queen::Queen(char p, int row, int col)
	: Piece(p, row, col), Bishop(p, row, col), Rook(p, row, col)
{
}

bool Queen::checkMove(Piece* board[8][8], Piece* source, Piece* destination) const
{
	if (Bishop::checkMove(board, source, destination) ||
		Rook::checkMove(board, source, destination))
	{
		return true;
	}
	return false;
}

Piece* Queen::clone(Piece* destination) const
{
	return new Queen(this->getType(), destination->getY(), destination->getX());
}
