#include "Pawn.h"
#include <iostream>

using std::cout;
using namespace std;

// Function to check if the pawn's movement is valid
bool Pawn::checkMove(Piece* board[8][8], Piece* source, Piece* destination) const
{
    int sourceX = source->getX();
    int sourceY = source->getY();
    int destinationX = destination->getX();
    int destinationY = destination->getY();
    // Determine the pawn's movement direction
    int direction = (source->getColor() == 'w') ? -1 : (source->getColor() == 'b') ? 1 : 0;

    // Calculate the difference in positions
    int dx = destinationX - sourceX;
    int dy = destinationY - sourceY;

    // Forward move (1 step)
    if (dx == 0 && dy == direction && board[destinationY][destinationX]->getType() == EMPTY) {
        return true;
    }

    // First move (2 steps forward)
    if (dx == 0 && dy == 2 * direction &&
        ((direction == 1 && sourceY == 1) || (direction == -1 && sourceY == 6)) &&
        board[destinationY][destinationX]->getType() == EMPTY &&
        board[sourceY + direction][sourceX]->getType() == EMPTY) {
        return true;
    }

    // Diagonal capture
    if ((dx == 1 || dx == -1) && dy == direction &&
        board[destinationY][destinationX]->getType() != EMPTY &&
        board[destinationY][destinationX]->getColor() != source->getColor()) {
        return true;
    }

    return false;
}
