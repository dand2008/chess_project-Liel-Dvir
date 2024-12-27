#include "Pawn.h"
#include <iostream>

using std::cout;
using namespace std;

// Function to check if the pawn's movement is valid
bool Pawn::checkMove(Piece board[8][8], Piece source, Piece destination) const
{

    // Determine the direction of movement based on the pawn's type
    int direction = (source.getType() == 'P') ? 1 : (source.getType() == 'p') ? -1 : 0;
    direction = direction * (-1);

    // If the type is not valid for a pawn, return false
    if (direction == 0) {
        cout << "Invalid pawn type!" << endl;
        return false;
    }

    // calc difference in pos
    int dx = destination.getX() - source.getX();
    int dy = destination.getY() - source.getY();

    //cout << "Source: (" << source.getX() << ", " << source.getY() << ")" << endl;
    //cout << "Destination: (" << destination.getX() << ", " << destination.getY() << ")" << endl;
    //cout << "dx: " << dx << ", dy: " << dy << ", direction: " << direction << endl;
    //cout << "Destination type: " << board[destination.getY()][destination.getX()].getType() << endl;


    // check bounds
    if (destination.getX() < 0 || destination.getX() >= 8 || destination.getY() < 0 || destination.getY() >= 8) {
        cout << "Move is out of bounds!" << endl;
        return false;
    }

    // forward
    if (dx == 0 && dy == direction) {
        if (board[destination.getY()][destination.getX()].getType() == '#') {
            return true;
        }        
    }


    // first move --> 2 steps forward
    if (dx == 0 && dy == 2 * direction &&
        ((direction == 1 && source.getY() == 1) || (direction == -1 && source.getY() == 6))) {
        if (board[destination.getY()][destination.getX()].getType() == '#' &&
            board[source.getY() + direction][source.getX()].getType() == '#') {
            cout << "Pawn is moving forward for the first time" << endl;
            return true;
        }
    }

    // diagonal capture
    if ((dx == 1 || dx == -1) && dy == direction) {
        if (board[destination.getY()][destination.getX()].getType() != '#' &&
            board[destination.getY()][destination.getX()].getType() != source.getType()) {
            cout << "Pawn is capturing a piece" << endl;
            return true;
        }
    }

    return false;
}