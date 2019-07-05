#include "pch.h"
#include "LoveStrategy.h"
#include "Mole.h"
#include <iostream>
#include "Game.h"

LoveStrategy::LoveStrategy()
{
}

bool LoveStrategy::is_done_love()
{
	return Game::now() -  this->time_start_love >= this->loving_time ;
}

void LoveStrategy::set_time_until_love(int time)
{
	this->get_mole()->time_until_love = time;
}

void LoveStrategy::update()
{
	if (this->is_done_love()) {
		if(this->get_mole()->get_sex() == Sex::FEMALE)
			Game::field->create_mole(this->get_mole()->get_position().x, this->get_mole()->get_position().y);
		this->get_mole()->start_move();
	}
	else {
		//std::cout << "making love " << (this->get_mole()->get_sex() == Sex::MALE ? "Male" : "Female") << " left" << this->loving_time + 10 << std::endl;
	}
}

void LoveStrategy::on_create()
{
	this->set_time_until_love(this->loving_time+10);
	this->time_start_love = Game::now();
	//std::cout << "starting love " << (this->get_mole()->get_sex() == Sex::MALE ? "Male" : "Female") << " left" << this->loving_time + 10 << std::endl;
}

LoveStrategy * LoveStrategyFactory::create()
{
	return new LoveStrategy();
}
