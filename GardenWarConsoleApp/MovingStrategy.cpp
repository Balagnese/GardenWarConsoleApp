#include "pch.h"
#include "MovingStrategy.h"
#include "Mole.h"


MovingStrategy::MovingStrategy()
{
}


void MovingStrategy::update()
{
	
	if (is_done_move()) {
		this->get_mole()->start_eat();
	}
	else {
		this->on_update();
		move();
	}
	
}

void MovingStrategy::on_create()
{
}


MovingStrategy::~MovingStrategy()
{
}
