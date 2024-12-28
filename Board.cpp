#include "Board.h"

Board::Board(const char* board)
{
	char* ptr = (char*)board;
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
            if (tolower(*ptr) == 'p')
            {
                _board[i][j] = (new Pawn(*ptr, i, j));
            }
            if (tolower(*ptr) == 'r')
            {
                _board[i][j] = (new Rook(*ptr, i, j));
            }
            if (tolower(*ptr) == 'b')
            {
                _board[i][j] = (new Bishop(*ptr, i, j));
            }
            if (tolower(*ptr) == 'n')
            {
                _board[i][j] = (new Knight(*ptr, i, j));
            }
            if (tolower(*ptr) == 'q')
            {
                _board[i][j] = (new Queen(*ptr, i, j));
            }
            //if (tolower(*ptr) == 'k')
            //{
            //    _board[i][j] = *(new King(*ptr, i, j));
            //}
			ptr++;
		}
	}
}

Piece* Board::getPiece(int row, int col)
{
    return _board[row][col];
}

void Board::displayBoard() const {
    std::cout << "    a   b   c   d   e   f   g   h\n"; // Column labels
    std::cout << "  +---+---+---+---+---+---+---+---+\n"; // Top border

    for (int i = 0; i < 8; i++) {
        std::cout << (8 - i) << " | "; // Row label
        for (int j = 0; j < 8; j++) {
            *(_board[i][j]).display();   // Display each square
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

