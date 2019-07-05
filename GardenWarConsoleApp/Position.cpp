#include "pch.h"
#include "Position.h"


Position::Position(): Position(0,0)
{
}

Position::Position(int x, int y)
{
	this->x = x;
	this->y = y;
}

Position::~Position()
{
}

bool Position::operator==(Position & another) const
{
	return this->x == another.x && this->y == another.y;
}

bool Position::operator!=(Position & another) const
{
	return this->x != another.x || this->y != another.y;
}
