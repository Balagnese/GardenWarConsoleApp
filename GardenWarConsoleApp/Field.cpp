#include "pch.h"
#include "Field.h"


Field::~Field()
{
	for (int i = 0; i < this->width(); i++) {
		delete[] this->_field[i];
	}
	delete[]_field;
}

Field::Field(int width, int height)
{
	this->_width = width;
	this->_height = height;
	this->_field = new int*[width];
	for (int i = 0; i < width; i++) {
		this->_field[i] = new int[height];
		for (int j = 0; j < height; j++)
			this->_field[i][j] = 0;
	}
}

int Field::width()
{
	return this->_width;
}

int Field::height()
{
	return this->_height;
}

void Field::set(int x, int y, int val)
{
	this->_field[x][y] = val;
}

int Field::get(int x, int y)
{
	return this->_field[x][y];
}


