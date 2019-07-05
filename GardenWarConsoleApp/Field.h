#pragma once
class Field
{
public:
	Field() = delete;
	virtual ~Field();
	Field(int width, int height);
	int width();
	int height();
	void set(int x, int y, int val);
	int get(int x, int y);
private:
	int _width;
	int _height;
	int** _field;
};

