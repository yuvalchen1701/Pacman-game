#include "Fruit.h"
#include "Position.h"

void Fruit::setNewPosition(const Position& pos_validBorders, Board& theBoard) /* x= row and y=cols of the file*/
{
	int new_x = rand() % pos_validBorders.getX() - 3;
	int new_y = rand() % pos_validBorders.getY();

	while (theBoard.getCell(new_x, new_y) == BORDER_CH || theBoard.isATunel(new_x, new_y))
	{
		new_x = rand() % pos_validBorders.getX() - 3;
		new_y = rand() % pos_validBorders.getY();
	}

	setPosition(new_x, new_y);
}

void Fruit::printObject() 
{
	gotoxy(getPosition().getY(), getPosition().getX());
	cout << curr_Value;
}

void Fruit::FixScreen(Board& theBoard)
{
	gotoxy(getPosition().getY(), getPosition().getX());
	cout << theBoard.getCell(getPosition().getX(), getPosition().getY());
	Sleep(150);
}

void Fruit::move(const Position& pos_validBorders, Board& theBoard)
{
	if (pause == 10)
	{
		FixScreen(theBoard);
		curr_Value = rand() % 5 + 5;
		pause = 0;
		setNewPosition(pos_validBorders, theBoard);
		printObject();
	}

	pause++;
}


