#include "pch.h"
#include "SlowMovingStrategy.h"
#include <cstdlib>
#include "Mole.h"
#include <iostream>

bool SlowMovingStrategy::is_done_move()
{
	return !(rand() % 50);
}

SlowMovingStrategy::SlowMovingStrategy()
{
	this->_speed = 0.1;
	this->_delta = 0;
}

void SlowMovingStrategy::move()
{
	this->_delta += this->_speed;
}

void SlowMovingStrategy::on_update()
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


SlowMovingStrategy::~SlowMovingStrategy()
{
}

MovingStrategy * SlowMovingStrategyFactory::create()
{
	return new SlowMovingStrategy();
}
