#include "pch.h"
#include "BaseStrategy.h"


Mole * const BaseStrategy::get_mole()
{
	return this->_m;
}

void BaseStrategy::set_mole(Mole * m)
{
	this->_m = m;
}
