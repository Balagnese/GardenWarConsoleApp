#include "pch.h"
#include "Game.h"
#include "Gardener.h"




Game::~Game()
{
}

long Game::now()
{
	return time;
}

void Game::update()
{
	Game::field->update();
	Game::gardener->update();
	time++;
}

void Game::initGame(int start_moles_count, int field_width, int field_height, MoleFactory* mole_factory, float gardener_speed, ObjField* gardener_attack_field)
{
	if (field_width <= 0 || field_height <= 0 || !mole_factory || !gardener_attack_field || gardener_speed <= 0||start_moles_count<=0)
		throw "";
	Game::field = new GameField(field_width, field_height);
	for (int i = 0; i < field_width; i++)
		for (int j = 0; j < field_height; j++) {
			Game::field->set(i, j, 1);
		}
	Game::gardener = new Gardener(rand() % field_width, rand() % field_height, gardener_speed, gardener_attack_field);
	Game::mole_factory = mole_factory;
	for (int i = 0; i < start_moles_count; i++) {
		Game::field->create_mole(rand() % field_width, rand() % field_height);
	}
}

bool Game::gardener_won()
{
	return Game::field->get_moles().size()==0;
}

bool Game::moles_won()
{
	for (int i = 0; i < Game::field->width(); i++) {
		for (int j = 0; j < Game::field->height(); j++) {
			if (Game::field->get(i, j))
				return false;
		}
	}
	return true;
}

GameField* Game::field = nullptr;
Gardener* Game::gardener = nullptr;
MoleFactory* Game::mole_factory = nullptr;
long Game::time = 0;

