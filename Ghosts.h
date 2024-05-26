#ifndef __GHOSTS_H
#define __GHOSTS_H

#include "GameObjects.h"
#include <stdlib.h>


class Ghosts : public GameObjects
{
	public:
		Ghosts(){}
		Ghosts(Position pos_Ghosts) :GameObjects(pos_Ghosts){} 
		void     setNewPosition(const Position& pos, Board& theBoard) override;
		void	 printObject() override;
		Position getRandomDirection();
		Position getPosition() { return GameObjects::getPosition(); }
		void	 FixBoard(const Position& curr, Board& theBoard);
		void	 validGhostPosition(const Position& curr, Position& posDiraction, Board& theBoard);
		void	getVerseDirection(Position& pos);
		void	setInitPosition(const Position& init_GhostPos, Board& theBoard) 
				{ setNewPosition(init_GhostPos, theBoard); }
		virtual void MoveGhost(const Position& curr, Board& theBoard) { ; }
		bool isPositionInRange(const Position& curr, Board& theBoard);
};

#endif // __GHOSTS_H