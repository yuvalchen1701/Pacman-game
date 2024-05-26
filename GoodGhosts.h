#pragma once

#include "Ghosts.h"

class GoodGhost : public Ghosts
{
	private:
		static int count_Smart;
		static int count_FiveSteps;
		static int x_posDirection;
		static int y_posDirection;

	public:
		GoodGhost(Position pos_GoodGhost) :Ghosts(pos_GoodGhost) {}
		void MoveGhost(const Position& pos, Board& theBoard) override;
};