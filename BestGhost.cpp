
#include "BestGhost.h"
#include "Position.h"

void BestGhost::MoveGhost(const Position& pos, Board& theBoard) 
{
	Position pos_Dir;

	if (pos.getX() < getPosition().getX())
	{
		pos_Dir.setX(-1);
		pos_Dir.setY(0);
		validGhostPosition(getPosition(), pos_Dir, theBoard);
		setNewPosition(pos_Dir, theBoard);
	}

	else if (pos.getX() > getPosition().getX())
	{
		pos_Dir.setX(1);
		pos_Dir.setY(0);
		validGhostPosition(getPosition(), pos_Dir, theBoard);
		setNewPosition(pos_Dir, theBoard);
	}

	else
	{
		if (pos.getY() < getPosition().getY())
		{
			pos_Dir.setX(0);
			pos_Dir.setY(-1);
			validGhostPosition(getPosition(), pos_Dir, theBoard);
			setNewPosition(pos_Dir, theBoard);
		}
		

		else if (pos.getY() > getPosition().getY())
		{
			pos_Dir.setX(0);
			pos_Dir.setY(1);
			validGhostPosition(getPosition(), pos_Dir, theBoard);
			setNewPosition(pos_Dir, theBoard);
		}
		
	}
}

