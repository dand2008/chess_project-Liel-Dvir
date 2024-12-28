#include "Queen.h"

bool Queen::checkMove(Piece board[8][8], Piece source, Piece destination) const
{
	if (Bishop::checkMove(board, source, destination) ||
		Rook::checkMove(board, source, destination))
	{
		return true;
	}
	return false;
}
