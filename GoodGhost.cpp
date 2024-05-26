#include "GoodGhosts.h"
#include "Position.h"

int GoodGhost::count_Smart = 0;
int GoodGhost::count_FiveSteps = 0;
int GoodGhost::x_posDirection = 0;
int GoodGhost::y_posDirection = 0;

void GoodGhost::MoveGhost(const Position& pos, Board& theBoard)
{
	if (count_Smart < 20)
	{
		Position pos_Dir;

		if (pos.getX() < Ghosts::getPosition().getX())
		{
			pos_Dir.setX(-1);
			pos_Dir.setY(0);
			validGhostPosition(getPosition(), pos_Dir, theBoard);
			setNewPosition(pos_Dir, theBoard);
		}

		else if (pos.getX() > Ghosts::getPosition().getX())
		{
			pos_Dir.setX(1);
			pos_Dir.setY(0);
			validGhostPosition(getPosition(), pos_Dir, theBoard);
			setNewPosition(pos_Dir, theBoard);
		}

		else
		{
			if (pos.getY() < Ghosts::getPosition().getY())
			{
				pos_Dir.setX(0);
				pos_Dir.setY(-1);
				validGhostPosition(getPosition(), pos_Dir, theBoard);
				setNewPosition(pos_Dir, theBoard);
			}

			else if (pos.getY() > Ghosts::getPosition().getY())
			{
				pos_Dir.setX(0);
				pos_Dir.setY(1);
				validGhostPosition(getPosition(), pos_Dir, theBoard);
				setNewPosition(pos_Dir, theBoard);
			}
		}

		count_Smart++;
	}

	else if (count_Smart == 20)
	{
		Position pos_Random;
		
			pos_Random = getRandomDirection();
			
			if (count_FiveSteps >= 1 && count_FiveSteps < 5)
			{
				if (count_FiveSteps == 1)
				{/* Get random direction once - case of 5 steps */
					pos_Random = getRandomDirection();
					/* Save random position*/
					x_posDirection = pos_Random.getX();
					y_posDirection = pos_Random.getY();
				}

				validGhostPosition(getPosition(), pos_Random, theBoard);
				setNewPosition(pos_Random, theBoard);

				while (!isPositionInRange(getPosition(), theBoard))
				{
					pos_Random = getRandomDirection();
					validGhostPosition(getPosition(), pos_Random, theBoard);
					setNewPosition(pos_Random, theBoard);

					/* Save random position*/
					x_posDirection = pos_Random.getX();
					y_posDirection = pos_Random.getY();
				}

			}

		else if (count_FiveSteps == 5)
		{
			count_Smart = 0;
			count_FiveSteps = 0;
		}

		count_FiveSteps++;
	}
}

/*
void GoodGhost::Move_GoodGhost(const Position& pos_Pacman, Board& theBoard)
{

	if (count_Smart < 20)
	{
		Position pos_Dir;

		if (pos_Pacman.getX() < Ghosts::getPosition().getX())
		{
			pos_Dir.setX(-1);
			pos_Dir.setY(0);
			Ghosts::setNewPosition(pos_Dir, theBoard);
		}

		else if (pos_Pacman.getX() > Ghosts::getPosition().getX())
		{
			pos_Dir.setX(1);
			pos_Dir.setY(0);
			Ghosts::setNewPosition(pos_Dir, theBoard);
		}

		else
		{
			if (pos_Pacman.getY() < Ghosts::getPosition().getY())
			{
				pos_Dir.setX(0);
				pos_Dir.setY(-1);
				Ghosts::setNewPosition(pos_Dir, theBoard);
			}

			else if (pos_Pacman.getY() > Ghosts::getPosition().getY())
			{
				pos_Dir.setX(0);
				pos_Dir.setY(1);
				Ghosts::setNewPosition(pos_Dir, theBoard);
			}
		}

		count_Smart++;
	}

	else if (count_Smart == 20)
	{
		Position pos = getRandomDirection();
		Ghosts::setNewPosition(pos, theBoard);

		count_FiveSteps++;

		if (count_FiveSteps == 5)
		{
			count_Smart = 0;
			count_FiveSteps = 0;
		}
	}
}*/