#pragma once
#include <iostream>
#include <string>
#include <ctype.h>
#include "Board.h"
#include "Utils.h"

using std::string;

class Engine
{
public:
	Engine(const char* board);
	//~Engine();
	char* getCode(string move);
	char getCurrPlayer() const;
	void displayBoard() const;
private:
	Board _board;
	char _currentPlayer;
};