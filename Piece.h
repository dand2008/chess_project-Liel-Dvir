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
	void setPos(int newX, int newY);

	bool operator==(Piece& other) const;
	virtual bool checkMove(Piece* board[8][8], Piece* destination) const = 0; // Pure virtual function

	bool hasMoved() const {
		std::cout << "hasMoved returned" << _hasMoved <<std::endl;
		return _hasMoved;
	}

	void setMoved(bool hasMoved) {
		_hasMoved = hasMoved;
	}

	void setX(int newY) {
		_x = newY;
	}

protected:
	int _y;
	int _x;
	char _type;
	char _color;
	bool _hasMoved;
};