#include "pch.h"
#include "Gardener.h"
#include <vector>
#include "Mole.h"
#include "Game.h"
#include <algorithm>
#include <iostream>

Gardener::Gardener(int x, int y, double speed, ObjField * hit_field) : MovingObject(x, y)
{
	this->_speed = speed;
	if (hit_field == nullptr)
		throw;
	this->_hit_field = hit_field;
	this->_delta = 0;
	this->_direction = 0;
	closest_mole_pos = this->get_position();
}

Gardener::~Gardener()
{
	delete this->_hit_field;
}

void Gardener::update()
{
	if (_delta > 1) {
		_delta -= 1;
		switch (_direction)
		{
		case(1):
			set_position(this->get_position().x - 1, this->get_position().y);
			break;
		case(2):
			set_position(this->get_position().x, this->get_position().y - 1);
			break;
		case(3):
			set_position(this->get_position().x + 1, this->get_position().y);
			break;
		case(4):
			set_position(this->get_position().x, this->get_position().y + 1);
			break;
		default:
			break;
		}
	}

	_delta += _speed;
	
	Mole* closest = this->find_closest();


	closest_mole_pos = closest? closest->get_position() : closest_mole_pos;
	if (closest) {
		auto moles = Game::field->get_eating_moles();
		int k = 0;
	}


	int offset_x = closest_mole_pos.x - this->get_position().x;
	int offset_y = closest_mole_pos.y - this->get_position().y;
	_direction = 0;
	if (abs(offset_x) > abs(offset_y)) {
		if (offset_x < 0)
			_direction = 1;
		else if (offset_x > 0)
			_direction = 3;
		else
			_direction = 0;
	}
	else {
		if (offset_y < 0)
			_direction = 2;
		else if (offset_y > 0)
			_direction = 4;
		else
			_direction = 0;
	}
	
	auto moles_to_hit = moles_in_hit_field();
	auto moles = Game::field->get_eating_moles();
	if (moles_to_hit.size() > 0) {
		hit_moles(moles_to_hit);
	}


}

void Gardener::hit_moles(std::vector<Mole*> m)
{
	Game::field->kill_moles(m);
}

Mole * Gardener::find_closest()
{
	std::vector<Mole*> eating_moles = Game::field->get_eating_moles();
	Mole*closest = nullptr;
	Position self_pos = this->get_position();
	for (auto it = eating_moles.begin(); it != eating_moles.end(); it++) {
		if (!closest) {
			closest = *it;
		}
		int x = (*it)->get_position().x - self_pos.x;
		int y = (*it)->get_position().y - self_pos.y;
		int closest_x = closest->get_position().x - self_pos.x;
		int closest_y = closest->get_position().y - self_pos.y;
		if (x*x + y * y < closest_x*closest_x + closest_y * closest_y) {
			closest = *it;
		}
	}
	return closest;
}

std::vector<Mole*> Gardener::moles_in_hit_field()
{
	std::vector<Mole*> eating_moles = Game::field->get_eating_moles();
	std::vector<Mole*> moles_in_area;
	int hit_field_offset_x = this->get_position().x - this->_hit_field->get_position().x;
	int hit_field_offset_y = this->get_position().y - this->_hit_field->get_position().y;

	std::vector<Position> hitting_positions;
	for (int i = 0; i < this->_hit_field->width(); i++)
		for (int j = 0; j < this->_hit_field->height(); j++) {
			Position cellPos(i + hit_field_offset_x, j + hit_field_offset_y);
			if (cellPos.x >= 0 || cellPos.x < Game::field->width() ||
				cellPos.y >= 0 || cellPos.y < Game::field->height()) {
				if (this->_hit_field->get(i, j) == 1) {
					hitting_positions.push_back(cellPos);
				}
			}
		}

	for (auto it = eating_moles.begin(); it != eating_moles.end(); it++) {
		for (auto pos_it = hitting_positions.begin(); pos_it != hitting_positions.end(); pos_it++) {
			if ((*it)->get_position() == (*pos_it)) {
				moles_in_area.push_back((*it));
			}
		}
	}

	return moles_in_area;
}

void Gardener::move()
{
}
