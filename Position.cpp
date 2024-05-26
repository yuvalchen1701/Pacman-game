#include "Position.h"

int Position::getX() const
{
	return x;
}

int Position::getY() const
{
	return y;
}

void Position::setX(int x)
{
	this->x = x;
}

void Position::setY(int y)
{
	this->y = y;
}


/* Function gets a position and board. And returns true if position is not on the obstacle boundaries*/
bool Position::validPosition(Position pos, Board theBoard)
{
	if (theBoard.getCell(pos.getX(), pos.getY()) == BORDER_CH)
		return false;

	else return true;
}

bool Position::operator==(const Position& posA)
{
	if (x == posA.getX() && y == posA.getY())
		return true;
	else return false;
}