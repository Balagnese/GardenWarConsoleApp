#include "pch.h"
#include "GreedyFastMole.h"
#include "GreeadyEatingStrategy.h"
#include "FastMovingStrategy.h"

GreedyFastMole::GreedyFastMole(int x, int y, Sex s): Mole(x, y, s)
{
	this->eating_strategy_fact = new GreedyEatingStrategyFactory();
	this->love_strategy_fact = new LoveStrategyFactory();
	this->moving_strategy_fact = new FastMovingStrategyFactory();
	this->start_move();
}


GreedyFastMole::~GreedyFastMole()
{
}
