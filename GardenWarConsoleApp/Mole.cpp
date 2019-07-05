#include "pch.h"
#include "Mole.h"
#include "Position.h"
#include "MovingStrategy.h"
#include "LoveStrategy.h"
#include "EatingStrategy.h"
#include "Game.h"

Mole::Mole(int x, int y, Sex s): MovingObject(x, y)
{
	this->mole_sex = s;
	this->time_until_love = 0;
	this->_is_under_ground = 1;
	//this->active_strategy = this->moving_strategy_fact->create();
	//init_new_strategy();
}


Mole::~Mole()
{
	delete this->active_strategy;
	delete this->eating_strategy_fact;
	delete this->love_strategy_fact;
	delete this->moving_strategy_fact;
}

bool Mole::is_loving()
{
	return !ready_to_love();
}


void Mole::update()
{
	//todo искать тут партнёра для размножения(если это возможно) и апдейтить активную стратегию
	if (active_strategy == nullptr) {
		active_strategy = this->moving_strategy_fact->create();
		init_new_strategy();
	}
		
	if (!is_adult()) {
		age++;
	}
	if (!ready_to_love()) {
		time_until_love--;
	}
	Mole* partner = find_partner();
	if (partner) {
		this->start_love();
		partner->start_love();
	}
	
	active_strategy->update();
}

void Mole::start_move()
{
	delete this->active_strategy;
	this->active_strategy = this->moving_strategy_fact->create();
	init_new_strategy();
}

void Mole::start_love()
{
	delete this->active_strategy;
	this->active_strategy = this->love_strategy_fact->create();
	init_new_strategy();
}

void Mole::start_eat()
{
	delete this->active_strategy;
	this->active_strategy = this->eating_strategy_fact->create();
	init_new_strategy();
}

Sex Mole::get_sex()
{
	return this->mole_sex;
}



bool Mole::is_under_ground()
{
	return this->_is_under_ground;
}

Mole* Mole::find_partner()
{
	if (!this->is_adult() || !this->ready_to_love() || !this->is_under_ground())
		return nullptr;
	auto moles = Game::field->get_moles();
	for (auto it = moles.begin(); it != moles.end(); it++) {
		if ((*it)->get_position() == this->get_position()) {
			auto m = *it;
			bool ready_to_love = m->ready_to_love();
			bool is_adult = m->is_adult();
			bool diff_gender = this->mole_sex != m->mole_sex;
			bool is_underground = m->is_under_ground();
			if (m->ready_to_love() && m->is_adult() && (this->mole_sex != m->mole_sex) && is_underground) {
				return *it;
			}
		}
	}
	return nullptr;
}

bool Mole::ready_to_love()
{
	return this->time_until_love <= 0;
}

bool Mole::is_adult()
{
	return 1;
	return this->age > grow_up_time;
}

void Mole::init_new_strategy() {
	this->active_strategy->set_mole(this);
	this->active_strategy->on_create();
}

