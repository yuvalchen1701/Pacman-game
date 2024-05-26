
#include "NoviceGhost.h"
#include "Position.h"

int NoviceGhost::counter = 0;
int NoviceGhost::x_posDirection = 0;
int NoviceGhost::y_posDirection = 0;

void NoviceGhost::MoveGhost(const Position& pos, Board& theBoard)
{
	Position pos_Direction;

	if (counter == 20 || counter == 0)
	{
		if (counter == 20)
			counter = 0;

		pos_Direction = getRandomDirection();

		/* Save random position */
		x_posDirection = pos_Direction.getX();
		y_posDirection = pos_Direction.getY();

	}

	pos_Direction.setX(x_posDirection);
	pos_Direction.setY(y_posDirection);
	validGhostPosition(getPosition(), pos_Direction, theBoard);
	setNewPosition(pos_Direction, theBoard);

	while (!isPositionInRange(getPosition(), theBoard))
	{
		pos_Direction = getRandomDirection();
		validGhostPosition(getPosition(), pos_Direction, theBoard);
		setNewPosition(pos_Direction, theBoard);

		/* Save random position*/
		x_posDirection = pos_Direction.getX();
		y_posDirection = pos_Direction.getY();
	}

	counter++;

	
}

