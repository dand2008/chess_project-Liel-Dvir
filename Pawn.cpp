#include "Pawn.h"
#include <iostream>

using std::cout;
using namespace std;

// Function to check if the pawn's movement is valid
bool Pawn::checkMove(Piece board[8][8], Piece source, Piece destination) const
{
    // Determine the pawn's movement direction
    int direction = (source.getColor() == 'w') ? -1 : (source.getColor() == 'b') ? 1 : 0;
    if (direction == 0) {
        cout << "Invalid pawn type!" << endl;
        return false;
    }

    // Calculate the difference in positions
    int dx = destination.getX() - source.getX();
    int dy = destination.getY() - source.getY();

    //cout << "Source: (" << source.getX() << ", " << source.getY() << ")" << endl;
    //cout << "Destination: (" << destination.getX() << ", " << destination.getY() << ")" << endl;
    //cout << "dx: " << dx << ", dy: " << dy << ", direction: " << direction << endl;
    //cout << "Destination type: " << board[destination.getY()][destination.getX()].getType() << endl;
    
    // Check if the move is out of bounds
    if (destination.getX() < 0 || destination.getX() >= 8 || destination.getY() < 0 || destination.getY() >= 8) {
        cout << "Move is out of bounds!" << endl;
        return false;
    }

    // Forward move (1 step)
    if (dx == 0 && dy == direction && board[destination.getY()][destination.getX()].getType() == EMPTY) {
        return true;
    }

    // First move (2 steps forward)
    if (dx == 0 && dy == 2 * direction &&
        ((direction == 1 && source.getY() == 1) || (direction == -1 && source.getY() == 6)) &&
        board[destination.getY()][destination.getX()].getType() == EMPTY &&
        board[source.getY() + direction][source.getX()].getType() == EMPTY) {
        return true;
    }

    // Diagonal capture
    if ((dx == 1 || dx == -1) && dy == direction &&
        board[destination.getY()][destination.getX()].getType() != EMPTY &&
        board[destination.getY()][destination.getX()].getColor() != source.getColor()) {
        return true;
    }

    return false;
}
