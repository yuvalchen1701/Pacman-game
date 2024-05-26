#pragma once

#include "GameObjects.h"

class Fruit : public GameObjects
{
	private:
	int			curr_Value;
	int			pause;

	public:
		Fruit(Position pos_validBorders) :GameObjects(pos_validBorders) { pause = 0; curr_Value = rand() % 5 + 5; } //ctor
	const int					getCurrVal() { return curr_Value; }
	void						setNewPosition(const Position& pos_validBorders, Board& theBoard) override;
	void						printObject() override;
	void						setPause(int newPause) { pause = newPause; }
	void move(const Position& pos_validBorders, Board& theBoard);
	void FixScreen(Board& theBoard);
};