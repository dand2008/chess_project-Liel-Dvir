#include "Piece.h"

Piece::Piece(char p, int row, int col)
	: _row(row), _col(col)
{
	_color = isupper(p) ? WHITE : (islower(p) ? BLACK : EMPTY);
	_type = p;
}

Piece::Piece()
	: _type(EMPTY), _color(EMPTY), _row(0), _col(0)
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
	return _col;
}

int Piece::getY() const
{
	return _row;
}

void Piece::setPos(int row, int col)
{
	_row = row;
	_col = col;
}

bool Piece::operator==(Piece& other) const
{
	return (_row == other._row && _col == other._col);
}
