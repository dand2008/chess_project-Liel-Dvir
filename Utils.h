#pragma once
#include <string>
#include "Piece.h"
using std::string;

class Utils
{
public:
	static int* fetchMove(string data)
	{
		// Check if the input string length is exactly 4
		if (data.length() != 4)
		{
			throw std::string("ERROR: Invalid input!\n");
		}

		int* coords = new int[4]; // Alloc memory for the coordinates

		// Convert the source&destination position from chess notation to array indices
		int sourceX = data[0] - 'a';
		int sourceY = 8 - (data[1] - '0');
		int destinationX = data[2] - 'a';
		int destinationY = 8 - (data[3] - '0');

		// Store the converted coordinates in the array
		coords[0] = sourceX;
		coords[1] = sourceY;
		coords[2] = destinationX;
		coords[3] = destinationY;

		return coords; // Return the pointer to the array
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
	static Piece* findEnemyKing(Piece* board[8][8], Piece& source)
	{
		for (int y = 0; y < 8; y++)
		{
			for (int x = 0; x < 8; x++)
			{
				if (tolower(board[y][x]->getType()) == 'k' && board[y][x]->getColor() != source.getColor())
				{
					return board[y][x];
				}
			}
		}
		return nullptr;
	}
	static bool checkCheck(Piece* board[8][8], Piece& source, Piece& destination)
	{
		// Save the original piece at the destination and temporarily move the source
		Piece* originalPiece = board[destination.getY()][destination.getX()];
		board[destination.getY()][destination.getX()] = &source;
		board[source.getY()][source.getX()] = new nullPiece(EMPTY, source.getX(), source.getY()); // Mark the original position as empty

		// Temporarily update the source's coordinates
		int originalX = source.getX();
		int originalY = source.getY();
		source.setPos(destination.getX(), destination.getY()); // Assume setPosition updates x and y

		// Find the enemy king
		Piece* enemyKing = findEnemyKing(board, source);
		if (enemyKing == nullptr)
		{
			std::cerr << "Error: Enemy king not found." << std::endl;
			// Revert changes before returning
			source.setPos(originalX, originalY);
			board[source.getY()][source.getX()] = &source;
			board[destination.getY()][destination.getX()] = originalPiece;
			return false;
		}

		// Check if any of the source's allies can check the enemy king
		for (int y = 0; y < 8; y++)
		{
			for (int x = 0; x < 8; x++)
			{
				if (board[y][x] != nullptr && board[y][x]->getColor() == source.getColor())
				{
					if (board[y][x]->checkMove(board, board[y][x], enemyKing))
					{
						// Revert changes before returning
						source.setPos(originalX, originalY);
						board[source.getY()][source.getX()] = &source;
						board[destination.getY()][destination.getX()] = originalPiece;
						return true;
					}
				}
			}
		}

		// Revert changes after no check is found
		source.setPos(originalX, originalY);
		board[source.getY()][source.getX()] = &source;
		board[destination.getY()][destination.getX()] = originalPiece;

		return false;
	}
};