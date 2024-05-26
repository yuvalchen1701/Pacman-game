#ifndef __PACMAN_H
#define __PACMAN_H
	
#include "GameObjects.h"

class Pacman: public GameObjects
{
	public:
	Pacman(Position pos_Pacman) :GameObjects(pos_Pacman) {}
	void		setNewPosition(const Position& pos, Board& theBoard) override;
	void 		printObject() override;
	void		moveInTunel(Position& pos, Board& theBoard);
	Position	getPosition() { return GameObjects::getPosition(); }
	Position	getDirection(char key);
	void		movePacman(Board& theBoard, Position& curr, Position posDiraction);
	void		setInitPosition(const Position& init_PacmanPos, Board& theBoard) 
				{ setNewPosition(init_PacmanPos, theBoard); }
};

#endif // __PACMAN_H
