#include "pch.h"
#include "EatingStrategy.h"
#include "Mole.h"
#include "Game.h"


EatingStrategy::EatingStrategy()
{
}


EatingStrategy::~EatingStrategy()
{
}

void EatingStrategy::update()
{
	if (!(this->is_done_eating())) {
		this->on_update();
	}
	else {
		//Game::field->stop_eating(this->get_mole());
		this->set_under_ground(true);
		this->eat();
		this->get_mole()->start_move();
	}
}

void EatingStrategy::on_create()
{
	this->set_under_ground(false);
}

void EatingStrategy::set_under_ground(bool b)
{
	this->get_mole()->_is_under_ground = b;
}

