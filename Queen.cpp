#include "Queen.h"

bool Queen::checkMove(Piece* board[8][8], Piece* destination) const
{
	if (Bishop::checkMove(board, destination) ||
		Rook::checkMove(board, destination))
	{
		return true;
	}
	return false;
}
