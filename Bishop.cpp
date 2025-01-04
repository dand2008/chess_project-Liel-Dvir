#include "Bishop.h"

bool Bishop::checkMove(Piece* board[8][8], Piece* destination) const
{
    int sourceX = this->getX();
    int sourceY = this->getY();
    int destinationX = destination->getX();
    int destinationY = destination->getY();

    int dx = std::abs(sourceX - destinationX);
    int dy = std::abs(sourceY - destinationY);

    // Check if the move is diagonal
    if (dx != dy) {
        return false;
    }
    if (this->getColor() == destination->getColor())
    {
        return false;
    }

    if (this->getX() == destination->getX() && this->getY() == destination->getY())
    {
        return false;
    }

    // Determine the direction of movement
    int stepX = (destinationX > sourceX) ? 1 : -1;
    int stepY = (destinationY > sourceY) ? 1 : -1;

    // Check if the path is clear
    int currentX = sourceX + stepX;
    int currentY = sourceY + stepY;

    while (currentX != destinationX && currentY != destinationY)
    {
        if (board[currentY][currentX]->getType() != EMPTY)
        {
            return false; // Path is blocked
        }
        currentX += stepX;
        currentY += stepY;
    }

    return true; // All checks complete
}
