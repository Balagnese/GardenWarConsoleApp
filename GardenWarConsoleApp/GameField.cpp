#include "pch.h"
#include "GameField.h"
#include "Game.h"
#include "MoleFactory.h"
#include <string>
#include "Gardener.h"
#include <iostream>

GameField::GameField(int _width, int _height):Field(_width, _height)
{

}


GameField::~GameField()
{
}

void GameField::update()
{
	std::vector<Mole*> old_moles = _moles;
	for (auto it = old_moles.begin(); it != old_moles.end(); it++) {
		(*it)->update();
	}
	std::cout << "moles count" << _moles.size() << "; total killed " << this->killed_moles << std::endl;
}

void GameField::create_mole(int x, int y)
{
	Mole* m = Game::mole_factory->create(x, y);
	this->add_mole(m);
}

std::vector<Mole*> GameField::get_moles()
{
	return this->_moles;
}

std::vector<Mole*> GameField::get_eating_moles()
{
	std::vector<Mole*> eating_moles;
	for (auto i = this->_moles.begin(); i != this->_moles.end(); i++) {
		if (!(*i)->is_under_ground())
			eating_moles.push_back(*i);
	}
	return eating_moles;
}

void GameField::kill_moles(std::vector<Mole*> moles)
{
	for (auto it = moles.begin(); it != moles.end(); it++) {
		auto iter = std::find(this->_moles.begin(), this->_moles.end(), (*it));
		if (iter != _moles.end()) {
			delete *iter;
			this->_moles.erase(iter);
			this->killed_moles++;
		}
	}
	
}

void GameField::add_mole(Mole * mole)
{
	this->_moles.push_back(mole);
}

std::vector<std::string> GameField::representation()
{
	std::vector<std::string> show_field;
	show_field.push_back("");
	
	for (int i = 0; i < width()+2; i++) {
		show_field[0] += "X";
	}

	for (int i = 0; i < height(); i++) {
		show_field.push_back("");
		show_field[i+1] += "X";

		for (int j = 0; j < width(); j++) {
			show_field[i+1] += get(j, i) ? ".": " ";//std::to_string(get(i, j));
		}

		show_field[i+1] += "X";
	}
	show_field.push_back("");
	for (int i = 0; i < width()+2; i++) {
		show_field[height()+1] += "X";
	}

	for (auto it = _moles.begin(); it != _moles.end(); it++) {
		if ((*it)->is_under_ground()) {
			show_field[(*it)->get_position().y + 1][(*it)->get_position().x + 1] = (*it)->is_loving() ? 'l' :
				(*it)->get_sex() == Sex::MALE ? 'm' : 'f';
		}
		else {
			show_field[(*it)->get_position().y + 1][(*it)->get_position().x + 1] = (*it)->get_sex() == Sex::MALE ? 'M' : 'F';
		}
	}


	show_field[Game::gardener->get_position().y + 1][Game::gardener->get_position().x + 1] = 'G';

	return show_field;
}
