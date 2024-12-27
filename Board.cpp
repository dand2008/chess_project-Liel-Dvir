#include "Board.h"

Board::Board(const char* board)
{
	char* ptr = (char*)board;
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
            Piece p(*ptr, i, j);
            p.setType(*ptr);
            p.setPos(i, j);
			_board[i][j] = p;
			ptr++;
		}
	}
}

Piece& Board::getPiece(int row, int col)
{
    return _board[row][col];
}

void Board::displayBoard() const {
    std::cout << "    a   b   c   d   e   f   g   h\n"; // Column labels
    std::cout << "  +---+---+---+---+---+---+---+---+\n"; // Top border

    for (int i = 0; i < 8; i++) {
        std::cout << (8 - i) << " | "; // Row label
        for (int j = 0; j < 8; j++) {
            _board[i][j].display();   // Display each square
            std::cout << " | ";      // Cell separator
        }
        std::cout << (8 - i) << "\n"; // Close row with label
        std::cout << "  +---+---+---+---+---+---+---+---+\n"; // Row separator
    }

    std::cout << "    a   b   c   d   e   f   g   h\n"; // Column labels again
}

Piece(&Board::getBoard())[8][8]
{
    return _board;
}

