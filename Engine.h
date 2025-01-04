#pragma once
#include <iostream>
#include <string>
#include <ctype.h>
#include "Board.h"
#include "Utils.h"

using std::string;

enum MoveCode {
	VALID_MOVE = '0',
	CHECK = '1',
	NOT_PLAYER_PIECE = '2',
	DESTINATION_IS_OWN_PIECE = '3',
	MOVE_PUTS_IN_CHECK = '4',
	INVALID_INPUT = '5',
	ILLEGAL_MOVE = '6',
	SOURCE_DESTINATION_SAME = '7',
	CHECKMATE = '8'
};

class Engine
{
public:
	Engine(const char* board);
	//~Engine();
	char* getCode(string move);
	char getCurrPlayer() const;
	void setCurrPlayer(char player);
	void displayBoard() const;
	void movePiece(string move);
private:
	Board _board;
	char _currentPlayer;
};