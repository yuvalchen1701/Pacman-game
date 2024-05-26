#ifndef __POSITION_H
#define __POSITION_H

#include <stdlib.h>
#include "Board.h"
const int NUM_OF_DIRECTION = 4;


class Position
{

	private:
		int			x;
		int			y;

	public:
		Position(){}
		Position(int _x, int _y) { setX(_x); setY(_y); }
		void	setX(int x);
		void	setY(int y);
		int	getX() const;
		int	getY() const;
		bool		validPosition(Position pos, Board theBoard);
		bool operator==(const Position& posA);
};

#endif // __POSITION_H
