#pragma once
#include "Position.h"

class MovingObject
{
public:
	MovingObject(int x, int y);
	~MovingObject();

	Position& get_position();
	bool set_position(int x, int y);
private:
	Position pos;
};

