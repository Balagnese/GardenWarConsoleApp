#include "pch.h"
#include "GreeadyEatingStrategy.h"
#include "EatingStrategy.h"
#include "ObjField.h"
#include "Game.h"


GreeadyEatingStrategy::~GreeadyEatingStrategy()
{
	delete this->eating_field;
}

GreeadyEatingStrategy::GreeadyEatingStrategy()
{
	this->eating_field = new ObjField(3, 3);
	for (int i = 0; i < this->eating_field->width(); i++)
		for (int j = 0; j < this->eating_field->height(); j++)
			this->eating_field->set(i, j, 1);
	this->eating_field->set_position(1, 1);
	this->eating_time = 30;
}

bool GreeadyEatingStrategy::is_done_eating()
{
	return Game::now() - this->time_start_eating >= this->eating_time;
}

void GreeadyEatingStrategy::eat()
{
	int x = this->get_mole()->get_position().x;
	int y = this->get_mole()->get_position().y;
	int offset_x = x - this->eating_field->get_position().x;
	int offset_y = y - this->eating_field->get_position().y;
	for (int i = 0; i < this->eating_field->width(); i++)
		for (int j = 0; j < this->eating_field->height(); j++) {
			if (offset_x + i >= 0 && offset_x + i < Game::field->width() 
				&& offset_y + j >= 0 && offset_y+j<Game::field->height())
				Game::field->set(offset_x + i, offset_y + j, this->eating_field->get(i, j) == 0 ?
					Game::field->get(offset_x + i, offset_y + j) : 0);
		}
			
}

void GreeadyEatingStrategy::on_update()
{
}

void GreeadyEatingStrategy::on_create()
{
	EatingStrategy::on_create();
	this->time_start_eating = Game::now();
}


EatingStrategy * GreedyEatingStrategyFactory::create()
{
	return new GreeadyEatingStrategy();
}
