#include "pch.h"
#include "GreedySlowMole.h"

#include "GreeadyEatingStrategy.h"
#include "LoveStrategy.h"
#include "SlowMovingStrategy.h"


GreedySlowMole::GreedySlowMole(int x, int y, Sex s): Mole(x, y, s)
{
	this->eating_strategy_fact = new GreedyEatingStrategyFactory();
	this->love_strategy_fact = new LoveStrategyFactory();
	this->moving_strategy_fact = new SlowMovingStrategyFactory();
	this->start_move();
}


GreedySlowMole::~GreedySlowMole()
{
}
