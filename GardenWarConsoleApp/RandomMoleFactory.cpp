#include "pch.h"
#include "RandomMoleFactory.h"
#include "Mole.h"
#include <cstdlib>
#include "GreedyFastMole.h"
#include "GreedySlowMole.h"


RandomMoleFactory::RandomMoleFactory()
{
}


RandomMoleFactory::~RandomMoleFactory()
{
}

Mole * RandomMoleFactory::create(int x, int y)
{
	int rnd_type = rand() % 2;
	int rnd_sex = rand() % 2;
	return new GreedyFastMole(x, y, rnd_sex ? Sex::MALE : Sex::FEMALE);
	if (rnd_type == 0) {
		return new GreedyFastMole(x, y, rnd_sex ? Sex::MALE : Sex::FEMALE);
	}
	else {
		return new GreedySlowMole(x, y, rnd_sex ? Sex::MALE : Sex::FEMALE);
	}
	return nullptr;
}
