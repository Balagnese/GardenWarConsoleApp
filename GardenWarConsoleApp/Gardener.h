#pragma once
#include "Position.h"
#include "ObjField.h"
#include "MovingObject.h"

#include "Mole.h"
#include <vector>

class Gardener: public MovingObject
{
public:
	Gardener(int x, int y, double speed, ObjField* hit_field);
	~Gardener();
	void update();
	void hit_moles(std::vector<Mole*> m);
	Mole* find_closest();
	Position closest_mole_pos;
	std::vector<Mole*> moles_in_hit_field();
	void move();
private:
	ObjField* _hit_field;
	double _speed;
	double _delta;
	int _direction;
};

