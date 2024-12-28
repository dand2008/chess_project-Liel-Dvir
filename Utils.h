#pragma once
#include <string>
#include "Piece.h"
using std::string;

class Utils
{
public:
	static int* fetchMove(string data)
	{
		if (data.length() == 4)
		{
			int* coords = new int[4];
			int sourceX = data[0] - 'a';
			int sourceY = 8 - (data[1] - '0');
			int destinationX = data[2] - 'a';
			int destinationY = 8 - (data[3] - '0');
			coords[0] = sourceX;
			coords[1] = sourceY;
			coords[2] = destinationX;
			coords[3] = destinationY;
			return coords;
		}
		else
		{
			throw std::string("ERROR: Invalid input!\n");
		}
	}
	static void movePiece(Piece* board[8][8], Piece& source, Piece& destination, char& currentPlayer)
	{
		char pieceType = source.getType();
		Piece* p;
		switch (tolower(pieceType))
		{
		case 'b': p = new Bishop(pieceType, destination.getY(), destination.getX()); break;
		case 'k': p = new King(pieceType, destination.getY(), destination.getX()); break;
		case 'n': p = new Knight(pieceType, destination.getY(), destination.getX()); break;
		case 'p': p = new Pawn(pieceType, destination.getY(), destination.getX()); break;
		case 'q': p = new Queen(pieceType, destination.getY(), destination.getX()); break;
		case 'r': p = new Rook(pieceType, destination.getY(), destination.getX()); break;
		default: p = new nullPiece(pieceType, destination.getY(), destination.getX()); break;
		}
		board[destination.getY()][destination.getX()] = p;

		board[source.getY()][source.getX()] = new nullPiece(EMPTY, source.getY(), source.getX());
		destination.setType(source.getType());
		destination.setColor(source.getColor());

		source.setType(EMPTY);
		source.setColor(EMPTY);

		currentPlayer = currentPlayer == WHITE ? BLACK : WHITE;
	}
};