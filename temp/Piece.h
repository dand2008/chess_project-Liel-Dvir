#pragma once
#include <string>
#include <iostream>
#include <ctype.h>
using std::string;
#define EMPTY '#'

class Piece
{
public:
	Piece();
	Piece(char p, int row, int col);
	void display() const;
	char getType() const;
	void setType(char type);
	char getColor() const;
	void setColor(char c);
	int getX() const;
	int getY() const;
	void setPos(int x, int y);
	bool operator==(Piece other) const;
private:
	int _row;
	int _col;
	char _type;
	char _color;
};