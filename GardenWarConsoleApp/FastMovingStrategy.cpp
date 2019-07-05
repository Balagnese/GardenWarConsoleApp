#include "pch.h"
#include "FastMovingStrategy.h"
#include "Mole.h"
#include <cstdlib>

bool FastMovingStrategy::is_done_move()
{
	return !(rand() % 50);
}


FastMovingStrategy::FastMovingStrategy()
{
	this->_speed = 0.3;
	this->_delta = 0;
}

void FastMovingStrategy::move()
{
	this->_delta += this->_speed;
}

void FastMovingStrategy::on_update()
{
	int x = this->get_mole()->get_position().x;
	int y = this->get_mole()->get_position().y;
	if (this->_delta > 1) {
		this->_delta-=1;
		bool moved = false;
		while (!moved) {
			int r = rand() % 4;
			switch (r)
			{
			case(0):
				moved = this->get_mole()->set_position(x - 1, y);
				break;
			case(1):
				moved = this->get_mole()->set_position(x + 1, y);
				break;
			case(2):
				moved = this->get_mole()->set_position(x, y - 1);
				break;
			default:
				moved = this->get_mole()->set_position(x, y + 1);
				break;
			}
		}
		
	}
}


FastMovingStrategy::~FastMovingStrategy()
{
}

MovingStrategy * FastMovingStrategyFactory::create()
{
	return new FastMovingStrategy();
}
