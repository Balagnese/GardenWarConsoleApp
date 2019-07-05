#pragma once
#include "MoleFactory.h"
class RandomMoleFactory :
	public MoleFactory
{
public:
	RandomMoleFactory();
	~RandomMoleFactory();
	Mole* create(int x, int y) override;
};

