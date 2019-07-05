#pragma once
#include "Mole.h"

//class SlowMovingStrategy;
//class GreedyEatingStrategy;

class GreedySlowMole :
	public Mole
{
public:
	GreedySlowMole(int x, int y, Sex s);
	~GreedySlowMole();
};

