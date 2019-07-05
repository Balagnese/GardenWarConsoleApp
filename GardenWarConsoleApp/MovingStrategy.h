#pragma once
#include "BaseStrategy.h"
class MovingStrategy: public BaseStrategy
{
public:
	~MovingStrategy();
protected:
	MovingStrategy();
	bool virtual is_done_move() = 0;
	void update() override;
	void virtual move() = 0;
	void on_create() override;
};

class MovingStrategyFactory {
public:
	virtual MovingStrategy* create() = 0;
};
