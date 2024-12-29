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

		std::cout << "src before: " << source.getType() << ", dst before: " << destination.getType();
		Piece* p = source.clone(&destination);

		board[destination.getY()][destination.getX()] = p;

		board[source.getY()][source.getX()] = new nullPiece(EMPTY, source.getY(), source.getX());

		destination.setColor(source.getColor());
		source.setColor(EMPTY);
		destination.setType(source.getType());
		source.setType(EMPTY);

		currentPlayer = currentPlayer == WHITE ? BLACK : WHITE;
	}
};