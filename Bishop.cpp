#include "Bishop.h"

bool Bishop::checkMove(Piece* board[8][8], Piece* source, Piece* destination) const
{
    int x1 = source->getX();
    int y1 = source->getY();
    int x2 = destination->getX();
    int y2 = destination->getY();

    int dx = std::abs(x1 - x2);
    int dy = std::abs(y1 - y2);

    // Check if the move is diagonal
    if (dx != dy) {
        return false;
    }

    // Determine the direction of movement
    int stepX = (x2 > x1) ? 1 : -1;
    int stepY = (y2 > y1) ? 1 : -1;

    // Check if the path is clear
    int currentX = x1 + stepX;
    int currentY = y1 + stepY;

    while (currentX != x2 && currentY != y2) {
        if (board[currentY][currentX]->getType() != EMPTY) {
            return false; // Path is blocked
        }
        currentX += stepX;
        currentY += stepY;
    }

    return false;
}
