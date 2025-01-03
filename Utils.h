#pragma once
#include <string>
#include "Piece.h"
using std::string;

class Utils
{
public:
	/**
	 * @brief Receive a move string and translate it to 4 coords
	 * @param string move
	 * @returns int* [sourceX, sourceY, destinationX, destinationY] 
	 */
	static int* fetchMove(string move)
	{
		// Check if the input string length is exactly 4
		if (move.length() != 4)
		{
			throw std::string("ERROR: Invalid input!\n");
		}

		int* coords = new int[4]; // Alloc memory for the coordinates

		// Convert the source&destination position from chess notation to array indices
		int sourceX = move[0] - 'a';
		int sourceY = 8 - (move[1] - '0');
		int destinationX = move[2] - 'a';
		int destinationY = 8 - (move[3] - '0');

		// Store the converted coordinates in the array
		coords[0] = sourceX;
		coords[1] = sourceY;
		coords[2] = destinationX;
		coords[3] = destinationY;

		return coords; // Return the pointer to the array
	}

	/**
	 * @brief Move a piece from source to destination
	 * @param Piece* board[8][8] the board
	 * @param Piece& source the source piece
	 * @param Piece& destination the destination piece
	 * @returns void
	 */
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

	/**
	 * @brief Find the king on the board
	 * @param Piece* board[8][8] the board
	 * @param char currentPlayer the current player b/w
	 * @param bool isKingEnemy is the king to find - the enemy king
	 * @returns Piece* the king piece
	 */
	static Piece* findKing(Piece* board[8][8], char currentPlayer, bool isKingEnemy)
	{
		char enemyColor = currentPlayer == WHITE ? BLACK : WHITE;
		for (int y = 0; y < 8; y++)
		{
			for (int x = 0; x < 8; x++)
			{
				if (tolower(board[y][x]->getType()) == 'k' &&
					board[y][x]->getColor() == (isKingEnemy ? enemyColor : currentPlayer))
				{
					return board[y][x];
				}
			}
		}
		return nullptr;
	}

	/**
	 * @brief Check if the move puts the enemy/current king in check
	 * @param Piece* board[8][8] the board
	 * @param Piece& source the source piece
	 * @param Piece& destination the destination piece
	 * @param bool isCheckingEnemy is the king to check - the enemy king
	 * @returns bool true if the move puts the king in check
	 */
	static bool isCheck(Piece* board[8][8], Piece& source, Piece& destination, bool isCheckingEnemy)
	{
		// Find the enemy king
		Piece* enemyKing = findKing(board, source.getColor(), true);
		Piece* MyKing = findKing(board, source.getColor(), false);

		char enemyColor = source.getColor() == WHITE ? BLACK : WHITE;
		// Save the original piece at the destination and temporarily move the source
		Piece* originalPiece = board[destination.getY()][destination.getX()];
		board[destination.getY()][destination.getX()] = &source;
		board[source.getY()][source.getX()] = new nullPiece(EMPTY, source.getX(), source.getY()); // Mark the original position as empty

		// Temporarily update the source's coordinates
		int originalX = source.getX();
		int originalY = source.getY();
		source.setPos(destination.getX(), destination.getY());
		// Check if any of the source's allies can check the enemy king
		for (int y = 0; y < 8; y++)
		{
			for (int x = 0; x < 8; x++)
			{
				if (board[y][x]->getColor() != EMPTY && 
					board[y][x]->getColor() == (isCheckingEnemy ? source.getColor() : enemyColor))
				{
					if (board[y][x]->checkMove(board, isCheckingEnemy ? enemyKing : MyKing))
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

	/**
	 * @brief Check if the move puts the enemy king in checkmate
	 * @param Piece* board[8][8] the board
	 * @param Piece& source the source piece
	 * @param Piece& destination the destination piece
	 * @returns bool true if the move puts the enemy king in checkmate
	 */
	static bool isCheckmate(Piece* board[8][8], Piece& source, Piece& destination)
	{
		// Step 1: Check if the move puts the enemy king in check
		if (!isCheck(board, source, destination, true)) {
			return false; // No check, so no checkmate
		}

		// Step 2: Determine the enemy color
		char enemyColor = source.getColor() == WHITE ? BLACK : WHITE;

		// Save the original piece at the destination and temporarily move the source
		Piece* originalPiece = board[destination.getY()][destination.getX()];
		board[destination.getY()][destination.getX()] = &source;
		board[source.getY()][source.getX()] = new nullPiece(EMPTY, source.getX(), source.getY()); // Mark the original position as empty

		// Temporarily update the source's coordinates
		int originalX = source.getX();
		int originalY = source.getY();
		source.setPos(destination.getX(), destination.getY());

		// Step 3: Check if the enemy has any valid moves to escape check
		for (int y = 0; y < 8; y++) {
			for (int x = 0; x < 8; x++) {
				Piece* currentPiece = board[y][x];

				if (currentPiece->getColor() == enemyColor) {
					// Iterate through all possible moves for the enemy piece
					for (int dy = 0; dy < 8; dy++) {
						for (int dx = 1; dx < 8; dx++) {
							if (currentPiece->checkMove(board, board[dy][dx])) {
								// Temporarily move the piece
								Piece* tempOriginalPiece = board[dy][dx];

								// Check if the move escapes check
								bool stillInCheck = isCheck(board, *currentPiece, *tempOriginalPiece, false);

								if (!stillInCheck) {
									source.setPos(originalX, originalY);
									board[source.getY()][source.getX()] = &source;
									board[destination.getY()][destination.getX()] = originalPiece;
									return false; // The enemy can escape check, so no checkmate
								}
							}
						}
					}
				}
			}
		}
		// Step 4: If no valid moves escape check, it's a checkmate
		source.setPos(originalX, originalY);
		board[source.getY()][source.getX()] = &source;
		board[destination.getY()][destination.getX()] = originalPiece;
		return true;
	}
};