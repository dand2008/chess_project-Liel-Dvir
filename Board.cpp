#include "Board.h"

Board::Board(const char* board)
{
    char* ptr = (char*)board;
    for (int y = 0; y < 8; y++)
    {
        for (int x = 0; x < 8; x++)
        {
            char pieceType = *ptr;
            Piece* p = nullptr;
            switch (tolower(pieceType))
            {
            case 'b': p = new Bishop(pieceType, x, y); break;
            case 'k': p = new King(pieceType, x, y); break;
            case 'n': p = new Knight(pieceType, x, y); break;
            case 'p': p = new Pawn(pieceType, x, y); break;
            case 'q': p = new Queen(pieceType, x, y); break;
            case 'r': p = new Rook(pieceType, x, y); break;
            default: p = new nullPiece(pieceType, x, y); break; // Default to a generic piece if type is unknown
            }
            _board[y][x] = p;
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