#include "Piece.h"

Piece::Piece(char p, int x, int y)
	: _x(x), _y(y)
{
	_color = isupper(p) ? WHITE : (islower(p) ? BLACK : EMPTY);
	_type = p;
}

Piece::Piece()
	: _type(EMPTY), _color(EMPTY), _x(0), _y(0)
{
}

void Piece::display() const
{
	if (_type == EMPTY)
	{
		std::cout << " ";
	}
	else
	{
		std::cout << _type;
	}
}

char Piece::getType() const
{
	return _type;
}

void Piece::setType(char type)
{
	_type = type;
}

char Piece::getColor() const
{
	return _color;
}

void Piece::setColor(char c)
{
	_color = c;
}

int Piece::getX() const
{
	return _x;
}

int Piece::getY() const
{
	return _y;
}

void Piece::setPos(int newX, int newY)
{
	_y = newY;
	_x = newX;
}

bool Piece::operator==(Piece& other) const
{
	return (_x == other._x && _y == other._y);
}
