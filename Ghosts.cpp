#include "Ghosts.h"
#include "Position.h"

/* Function gets a reference position and set the opposite position */
void Ghosts::getVerseDirection(Position& pos)
{
	if (pos.getX() == 0)
		pos.setY(pos.getY() * -1);
	else
		pos.setX(pos.getX() * -1);
}

/* Function gets a position of direction and set ghost's position */
void Ghosts::setNewPosition(const Position& pos, Board& theBoard)
{
	Position newPos;

	int new_x = pos.getX() + getPosition().getX();
	int new_y = pos.getY() + getPosition().getY();
	newPos.setX(new_x);
	newPos.setY(new_y);

	setPosition(newPos.getX(), newPos.getY());
}


void Ghosts::printObject()
{
	Position pos = getPosition();

	gotoxy(pos.getY(), pos.getX());
	cout << GHOST_CH;
	Sleep(150);
}

/* Function gets a reference of current ghost's position and board.
   Function prints the sign of the board in the current ghost's position */
void Ghosts::FixBoard(const Position& curr, Board& theBoard)
{
	gotoxy(curr.getY(), curr.getX());
	cout << theBoard.getCell(curr.getX(), curr.getY());
	Sleep(150);

}

/* Function gets a reference of ghost's object, current ghost's position, position of diraction and board.
   Function update the current position and set a new position for the ghost considerering the tunnels and obstacles.*/
void Ghosts::validGhostPosition(const Position& curr, Position &posDiraction, Board& theBoard)
{
	if(theBoard.isFrameBoard(curr.getX(), curr.getY()) || theBoard.isATunel(curr.getX(), curr.getY()))
		getVerseDirection(posDiraction);	
}

bool Ghosts::isPositionInRange(const Position& curr, Board& theBoard)
{
	if (curr.getX() >= 0 && curr.getX() < theBoard.getRows() - 3 && curr.getY() >= 0 && curr.getY() < theBoard.getCols() - 1)
		return true;
	else return false;
}
/* Function returns a random position of direction */
Position Ghosts::getRandomDirection()
{
	int randDir;
	Position pos;

	randDir = rand() % NUM_OF_DIRECTION;

	switch (randDir)
	{
	case 0: /* LEFT */
		pos.setX(0);
		pos.setY(-1);
		break;
	case 1: /* RIGHT */
		pos.setX(0);
		pos.setY(1);
		break;
	case 2: /* UP */
		pos.setX(-1);
		pos.setY(0);
		break;
	case 3: /* DOWN */
		pos.setX(1);
		pos.setY(0);
		break;
	default:
		break;
	}

	return pos;
}