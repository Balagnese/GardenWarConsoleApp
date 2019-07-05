#pragma once
class Mole;
class MoleFactory
{
public:
	MoleFactory();
	~MoleFactory();
	virtual Mole* create(int x, int y) = 0;
};

