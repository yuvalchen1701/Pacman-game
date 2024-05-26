#pragma once
#include "Position.h"

class GameObjects
{
private:
	Position object_Pos;

public:
	GameObjects(){}
	GameObjects(Position pos) { object_Pos.setX(pos.getX()); object_Pos.setY(pos.getY());}
	Position	 getPosition() { return object_Pos; } 
	void		 setPosition(int _x, int _y) { object_Pos.setX(_x); object_Pos.setY(_y);}
	virtual void setNewPosition(const Position& pos, Board& theBoard) = 0;
	virtual void printObject() = 0;
};