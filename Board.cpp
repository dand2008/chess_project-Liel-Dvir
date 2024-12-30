#include "Board.h"

Board::Board(const char* board)
{
    char* ptr = (char*)board;
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            char pieceType = *ptr;
            Piece* p = nullptr;
            switch (tolower(pieceType))
            {
            case 'b': p = new Bishop(pieceType, i, j); break;
            case 'k': p = new King(pieceType, i, j); break;
            case 'n': p = new Knight(pieceType, i, j); break;
            case 'p': p = new Pawn(pieceType, i, j); break;
            case 'q': p = new Queen(pieceType, i, j); break;
            case 'r': p = new Rook(pieceType, i, j); break;
            default: p = new nullPiece(pieceType, i, j); break; // Default to a generic piece if type is unknown
            }
            _board[i][j] = p;
            ptr++;
        }
    }
}

Board::~Board()
{
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            delete _board[i][j];
        }
    }
}

Piece& Board::getPiece(int row, int col)
{
    return *(_board[row][col]);
}

void Board::displayBoard() const {
    std::cout << "    a   b   c   d   e   f   g   h\n"; // Column labels
    std::cout << "  +---+---+---+---+---+---+---+---+\n"; // Top border

    for (int i = 0; i < 8; i++) {
        std::cout << (8 - i) << " | "; // Row label
        for (int j = 0; j < 8; j++) {
            _board[i][j]->display();   // Display each square
            std::cout << " | ";      // Cell separator
        }
        std::cout << (8 - i) << "\n"; // Close row with label
        std::cout << "  +---+---+---+---+---+---+---+---+\n"; // Row separator
    }

    std::cout << "    a   b   c   d   e   f   g   h\n"; // Column labels again
}

Piece* (&Board::getBoard())[8][8]
{
    return _board;
}