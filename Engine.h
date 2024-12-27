#pragma once
#include <iostream>
#include <string>
#include <ctype.h>
#include "Board.h"
#include "Utils.h"

#define EMPTY '#'
using std::string;

class Engine
{
public:
	Engine(const char* board);
	//~Engine();
	char* getCode(string move);
	char getCurrPlayer() const;
	bool checkPieceMove(Piece board[8][8], Piece source, Piece destination);
private:
	Board _board;
	char _currentPlayer;
};