#include "Pacman.h"
#include "Position.h"


/* Function gets a position of direction and reference of the board. 
   Function set the new position of the Pacman considering the boundaries, obstacles and passage in the tunnel. */
void Pacman::setNewPosition(const Position& pos, Board &theBoard)
{
	Position newPos;
	int new_x = pos.getX() + getPosition().getX();
	int new_y = pos.getY() + getPosition().getY();
	newPos.setX(new_x);
	newPos.setY(new_y);

	/* Set position if Pacman doesn't hit the obstacles and board boundaries */
	/* “STAY” key was not pressed */
	if (newPos.validPosition(newPos, theBoard) || (pos.getX() != 0 && pos.getY() != 0)) 
	{
		if (theBoard.isATunel(newPos.getX(), newPos.getY()))
		{
			moveInTunel(newPos,theBoard);
			setPosition(newPos.getX(), newPos.getY());
		}
		
		else
			setPosition(newPos.getX(), newPos.getY());
	}
	
}

/* Function gets a reference of position and set the location(position) according to the entrance to the tunnel */
void Pacman::moveInTunel(Position &pos, Board& theBoard)
{
	if (pos.getX() == 0)
		pos.setX(theBoard.getRows());
	else if (pos.getX() == theBoard.getRows())
		pos.setX(0);
	else if (pos.getY() == 0)
		pos.setY(theBoard.getCols());
	else if (pos.getY() == theBoard.getCols())
		pos.setY(0);
}

void Pacman::printObject()
{
	gotoxy(getPosition().getY(), getPosition().getX());
	cout << PACKMAN_CH;
	Sleep(300);
}

/* Function gets a reference of pacman's object, board and current positon of the pacman.
   And also gets position of diraction.
   Function set a new position of Pacman and update the current Pacman's position and prints the sign of it */
void Pacman::movePacman(Board& theBoard, Position& curr, Position posDiraction)
{
	gotoxy(curr.getY(), curr.getX());
	cout << EMPTY_CH;
	Sleep(300);

	setNewPosition(posDiraction, theBoard);
	curr = getPosition(); /* Update current Pacman's position */
	
	printObject();
}


/* Function gets a sign of direction and translate the sign to position */
Position Pacman::getDirection(char key)
{
	Position pos;
	switch (key)
	{
	case LEFT_KEY_LITTLE:
	case LEFT_KEY_CAPITAL:
		pos.setX(0);
		pos.setY(-1);
		break;
	case UP_KEY_LITTLE:
	case UP_KEY_CAPITAL:
		pos.setX(-1);
		pos.setY(0);
		break;
	case RIGHT_KEY_LITTLE:
	case RIGHT_KEY_CAPITAL:
		pos.setX(0);
		pos.setY(1);
		break;
	case DOWN_KEY_LITTLE:
	case DOWN_KEY_CAPITAL:
		pos.setX(1);
		pos.setY(0);
		break;
	case STAY_KEY_LITTLE:
	case STAY_KEY_CAPITAL:
		pos.setX(0);
		pos.setY(0);
		break;
	default:
		//pos.setX(0);
		//pos.setY(0);
		break;
	}
	return pos;
}