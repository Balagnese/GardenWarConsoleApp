#include "pch.h"
#include "MovingObject.h"
#include "Game.h"


MovingObject::MovingObject(int x, int y)
{
	if (!set_position(x, y)) {
		throw;
	}
}


MovingObject::~MovingObject()
{
}

Position& MovingObject::get_position()
{
	return this->pos;
}

bool MovingObject::set_position(int x, int y)
{
	if ((x < 0) || (x >= Game::field->width()) || (y < 0) || (y >= Game::field->height())) {
		return false;
	}
	this->pos = Position(x, y);
	return true;
}
