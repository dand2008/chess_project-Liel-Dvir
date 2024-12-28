#include "King.h"
#include <iostream>

using std::cout;
using namespace std;

bool King::checkMove(Piece* board[8][8], Piece* source, Piece* destination) const
//bool King::checkMove(Piece board[8][8], Piece source, Piece destination) const
{
    int direction = (this->getType() == 'P') ? -1 : (this->getType() == 'p') ? 1 : 0;
    if (direction == 0) {
        cout << "Invalid king type!" << endl;
        return false;
    }

    // Calculate the difference in positions
    int dx = destination->getX() - this->getX();
    int dy = destination->getY() - this->getY();

	// Check if the move is out of bounds
	if (destination->getX() < 0 || destination->getX() >= 8 || destination->getY() < 0 || destination->getY() >= 8) {
		cout << "Move is out of bounds!" << endl;
		return false;
	}

	// Forward move (1 step)
	if ((dx == 0 || dx == 1 || dx == -1) && (dy == 0 || dy == 1 || dy == -1) // if (difference in x is 0 || 1 || -1) && (difference in y is 0 || 1 || -1)
		&& board[destination->getY()][destination->getX()]->getType() != this->getType()) // not moving to same color
	{
		return true;
	}

	return false;
}
