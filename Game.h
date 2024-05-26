#pragma once
#include <vector>
#include "Position.h"
using namespace std;

//class Position;
class Board;
class Pacman;
class Ghosts;
class Fruit;

class Game
{
	private:
		static int		points;
		static int		life;
		static int NUM_OF_BREADCRUMBS;
		Position PointPos;
		Position LifePos;

	public:
		Game(Position& posPL, int countBread) { PointPos.setX(posPL.getX()); PointPos.setY(posPL.getY());
												LifePos.setX(posPL.getX() + 1); LifePos.setY(posPL.getY()); NUM_OF_BREADCRUMBS = countBread;}
		void			setGame(vector<Ghosts*> arr_Ghost, Position& PacmanPos, Board& theBoard);
		static void		setPoints(int point);
		static void     setNumOfBread() { NUM_OF_BREADCRUMBS--; }
		static void		setLife();
		static int		getLife();
		static int		getPoints();
		static void		initCurrLife(int currLife) { life = currLife; }
		void			setPacmanPoints(Board& theBoard, Position& curr);
		bool			ghostEatPacman(Pacman& pacman, vector<Ghosts*> arr, int size, Position* initPosition, Position& curPacmanPos, Board& theBoard);
		void			printUserWin();
		void            printUserLose();
		char			getAValidKey();
		bool			isValidKey(char key);
		void			printCurrGhost(Ghosts ghost);
		void			initObjectsPosition(Pacman& pacman, vector<Ghosts*> arr, int size, Position* initPosition, Board& theBoard);
		void			GhostMeetFruit(vector<Ghosts*> arr, int size, const Position& pos_ValidBorders, Fruit& fruit, Board& theBoard);
		void			PacmanEatFruit(Position& curr_PacmanPos, Position& pos_ValidBorders, Fruit& fruit, Board& theBoard);
};