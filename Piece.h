#pragma once
#include <string>
#include <iostream>
#include <ctype.h>
using std::string;
#define WHITE 'w'
#define BLACK 'b'
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

	virtual bool checkMove(Piece* board[8][8], Piece* destination) const;

	bool operator==(Piece other) const;
private:
	int _row;
	int _col;
	char _type;
	char _color;
};