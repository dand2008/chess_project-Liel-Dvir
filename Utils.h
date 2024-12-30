#pragma once
#include <string>
#include "Piece.h"
using std::string;

class Utils
{
public:
	static int* fetchMove(string data)
	{
		if (data.length() != 4)
		{
			throw std::string("ERROR: Invalid input!\n");
		}
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
	static void movePiece(Piece* board[8][8], Piece& source, Piece& destination)
	{
		// save coords
		int sourceX = source.getX();
		int sourceY = source.getY();
		int destinationX = destination.getX();
		int destinationY = destination.getY();

		// Piece is gone
		delete& destination;

		// update destination
		source.setPos(destinationX, destinationY);
		board[destinationY][destinationX] = &source;

		// update source
		board[sourceY][sourceX] = new nullPiece(EMPTY, sourceX, sourceY);
	}
};