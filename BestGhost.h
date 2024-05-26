#pragma once

#include "Ghosts.h"

class BestGhost: public Ghosts
{
	public:
		BestGhost(Position pos_BestGhost) :Ghosts(pos_BestGhost){}
		void MoveGhost(const Position& pos, Board& theBoard) override;
};