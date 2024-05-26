#pragma once
#include "Pacman.h"
#include "Game.h"
#include "Ghosts.h"
#include "Position.h"
#include "Fruit.h"
#include "BestGhost.h"
#include "NoviceGhost.h"
#include "GoodGhosts.h"

int Game::points;
int Game::life = 3;
int Game::NUM_OF_BREADCRUMBS = 0;

void Game::setPoints(int point)
{
	points = points + point;
}

void Game::setLife()
{
	life--;
}

int Game::getLife()
{
	return life;
}

int Game::getPoints()
{
	return points;
}

/* Function gets a reference of board and current position of Pacman.
   Function update and prints points if Pacman eats breadcrumbs */
void Game::setPacmanPoints(Board& theBoard, Position& curr)
{
	if (theBoard.getCell(curr.getX(), curr.getY()) == BREADCRUMBS)
	{
		theBoard.setCell(curr.getX(), curr.getY(), EMPTY_CH);
		Game::setPoints(1);
		Game::setNumOfBread();
		gotoxy(PointPos.getY(), PointPos.getX());
		cout << points;
	}
}

void Game::initObjectsPosition(Pacman& pacman, vector<Ghosts*> arr, int size, Position* initPosition, Board& theBoard)
{
	pacman.setPosition(initPosition[0].getX(), initPosition[0].getY());
	for (int i = 0; i < size; i++)
		arr[i]->setPosition(initPosition[i + 1].getX(), initPosition[i + 1].getY());
}

/* Function return true if is a game over - when one of the ghosts eat the Pacman.
*  In this case we notify the user accordingly.
*  In the other case - of losing life but it's not a game over.
   We initialize the game and reduce the number of life. */
bool Game::ghostEatPacman(Pacman& pacman,vector<Ghosts*>arr, int size, Position* initPosition, Position& curPacmanPos, Board& theBoard)
{
	bool isGameOver = false;
	bool isEaten = false;

	for (int i = 0; i < size && !isEaten ; i++)
	{
		if (arr[i]->getPosition().operator==(pacman.getPosition()))
		{
			isEaten = true;
			Game::setLife();
			if (Game::getLife() == 0)
			{
				printUserLose();
				isGameOver = true;
			}


			else
			{
				//gotoxy(curPacmanPos.getY(), curPacmanPos.getX()); // ERASE PACMAN
			//	cout << EMPTY_CH;

				/* ERASE Pacman and Ghosts */
				for (int i = 0; i < size; i++)
					arr[i]->FixBoard(arr[i]->getPosition(), theBoard);

				// INIT POSITION OF PACMAN AND GHOSTS
				initObjectsPosition(pacman, arr, size, initPosition,theBoard);

				/* Print Posiiton of Pacman and Ghosts */
				for (int i = 0; i < size; i++)
					arr[i]->printObject();

				pacman.printObject();
				curPacmanPos = pacman.getPosition();
			}

			gotoxy(LifePos.getY(), LifePos.getX());
			cout << life;

		}

	}

	return isGameOver;
}

void Game::PacmanEatFruit(Position& curr_PacmanPos, Position& pos_ValidBorders, Fruit& fruit, Board& theBoard)
{
	if (fruit.getPosition().operator==(curr_PacmanPos))
	{
		setPoints(fruit.getCurrVal());
		fruit.setPause(10);
		fruit.move(pos_ValidBorders, theBoard);
	}
}

void Game::GhostMeetFruit(vector<Ghosts*>arr, int size, const Position& pos_ValidBorders, Fruit& fruit, Board& theBoard)
{
	for (int i = 0; i < size; i++)
	{
		if (arr[i]->getPosition().operator==(fruit.getPosition()))
		{
			arr[i]->FixBoard(fruit.getPosition(), theBoard);
			arr[i]->setNewPosition(arr[i]->getRandomDirection(), theBoard);
			fruit.setNewPosition(pos_ValidBorders, theBoard);
		}
	}
}

/* The function prints a win message in case the user has successfully completed the game */
void Game::printUserWin()
{
	if (0 == NUM_OF_BREADCRUMBS)
	{
		system("cls");
		cout << "Congratulations you win!" << endl;
	}		
}

/* The function prints a lose message in case its game over */
void Game::printUserLose()
{
	system("cls");
	cout << "Ohh noooo it's GAME OVER" << endl;
}

/* Function returns a valid key diraction from user to move the Pacman at the beginning of the game */
char Game::getAValidKey()
{
	char key;

	key = _getch();

	while (key != LEFT_KEY_CAPITAL && key != LEFT_KEY_LITTLE &&
		key != RIGHT_KEY_CAPITAL && key != RIGHT_KEY_LITTLE &&
		key != DOWN_KEY_CAPITAL && key != DOWN_KEY_LITTLE &&
		key != UP_KEY_CAPITAL && key != UP_KEY_LITTLE)
	{
		key = _getch();
	}

	return key;
}

/* Function gets a key and return true if the key is a valid letter of movment. Otherwise, returns false. */
bool Game::isValidKey(char key)
{
	if (key != LEFT_KEY_CAPITAL && key != LEFT_KEY_LITTLE &&
		key != RIGHT_KEY_CAPITAL && key != RIGHT_KEY_LITTLE &&
		key != DOWN_KEY_CAPITAL && key != DOWN_KEY_LITTLE &&
		key != UP_KEY_CAPITAL && key != UP_KEY_LITTLE && key!=STAY_KEY_CAPITAL && key!=STAY_KEY_LITTLE)
		return false;

	else return true;
}

/* Function gets a ghost's object and print it sign acoording to current position */
void Game::printCurrGhost(Ghosts ghost)
{
	gotoxy(ghost.getPosition().getY(), ghost.getPosition().getX());
	cout << GHOST_CH;
	Sleep(150);
}


//--------------------------------------------------------------------------

void Game::setGame(vector<Ghosts*> arr_Ghost, Position& curPacmanPos, Board& theBoard)
{
	theBoard.printBoard(PointPos.getX());

	bool		isGameOver = false;
	int			countESC = 0;
	char		prev_key, key;
	Position	posDiraction_Pacman;
	Position	pos_ValidBorder(theBoard.getRows(), theBoard.getCols()); // Borders
	
	Pacman		pacman(curPacmanPos);
	Fruit		fruit(pos_ValidBorder);
	fruit.setNewPosition(pos_ValidBorder, theBoard);
	int sizeOfGhosts = arr_Ghost.size();
	
	for (int i = 0; i < sizeOfGhosts; i++)
		printCurrGhost(*(arr_Ghost[i]));

	pacman.printObject();
	fruit.printObject();
	
	// Pacman = initPosition[0]
	Position* initPosition;
	initPosition= new Position[sizeOfGhosts + 1];
	initPosition[0] = pacman.getPosition();
	for (int i = 0; i < sizeOfGhosts; i++)
		initPosition[i+1]=arr_Ghost[i]->getPosition();
	
	
	key = getAValidKey();
	posDiraction_Pacman = pacman.getDirection(key);
	
	while (!(isGameOver))
	{ 
		if (key != ESC)
			prev_key = key;

		if (_kbhit()) /* User press a key*/
		{
			key =_getch();
			if (!isValidKey(key))
			{
				if (key == ESC)
					countESC++;

				key = prev_key;
			}
				
			posDiraction_Pacman = pacman.getDirection(key);
		}

		if (countESC == 1)
		{
			gotoxy(0, 30);
			cout << "Enter ESC to countinue the game!";
		}

		if (countESC == 2)
			countESC = 0;

		if (countESC != 1)
		{
			pacman.movePacman(theBoard, curPacmanPos, posDiraction_Pacman);
			fruit.move(pos_ValidBorder, theBoard);


			for (int i = 0; i < sizeOfGhosts; i++)
			{
				arr_Ghost[i]->FixBoard(arr_Ghost[i]->getPosition(), theBoard);
				arr_Ghost[i]->MoveGhost(pacman.getPosition(), theBoard);
			}


			setPacmanPoints(theBoard, curPacmanPos);
			printUserWin(); //checks if the user win

			/*
			for (int i = 0; i < sizeOfGhosts; i++)
			{
				for (int j = i + 1; j < sizeOfGhosts; j++)
				{
					if(arr[i].getPosition().operator==(arr[j].getPosition()))
					//	arr[i].getVerseDirection(posDiraction_GhostA);
				}
			}*/

			isGameOver = ghostEatPacman(pacman, arr_Ghost, sizeOfGhosts, initPosition, curPacmanPos,theBoard);
			PacmanEatFruit(curPacmanPos, pos_ValidBorder, fruit, theBoard);
			GhostMeetFruit(arr_Ghost, sizeOfGhosts, pos_ValidBorder,fruit, theBoard);

			if (!(isGameOver))
			{
				for (int i = 0; i < sizeOfGhosts; i++)
					printCurrGhost(*(arr_Ghost[i]));
			}

		}
  	}
}