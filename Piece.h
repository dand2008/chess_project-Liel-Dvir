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
	virtual ~Piece() = default;
	void display() const;

	char getType() const;
	void setType(char type);

	char getColor() const;
	void setColor(char c);

	int getX() const;
	int getY() const;
	void setPos(int row, int col);

	bool operator==(Piece& other) const;
	virtual bool checkMove(Piece* board[8][8], Piece* source, Piece* destination) const = 0; // Pure virtual function
	virtual Piece* clone(Piece* destination) const = 0; // Pure virtual function

protected:
	int _row;
	int _col;
	char _type;
	char _color;
};