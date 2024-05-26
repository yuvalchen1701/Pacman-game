#pragma once

#include "Ghosts.h"

class NoviceGhost :public Ghosts
{
	private:
		static int counter; 
		static int x_posDirection;
		static int y_posDirection;
		  
	public:
		NoviceGhost(Position pos_NoviceGhost,int counter=0) :Ghosts(pos_NoviceGhost) {}
		void MoveGhost(const Position& pos, Board& theBoard) override;
};