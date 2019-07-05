#include "pch.h"
#include "ObjField.h"
#include <algorithm>


ObjField::~ObjField()
{
	
}

ObjField::ObjField(int width, int height) : Field(width, height)
{
}


Position ObjField::get_position()
{
	return this->_pos;
}

void ObjField::set_position(int x, int y)
{
	this->_pos = Position(x, y);
}

