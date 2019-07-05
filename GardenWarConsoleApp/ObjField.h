#pragma once
#include "Position.h"
#include "Field.h"
class ObjField: public Field
{
public:
	ObjField() = delete;
	~ObjField();
	ObjField(int width, int height);
	Position get_position();
	void set_position(int x, int y);
	
private:
	Position _pos;
};

