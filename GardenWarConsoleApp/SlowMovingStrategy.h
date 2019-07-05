#pragma once
#include "MovingStrategy.h"
class SlowMovingStrategy : public MovingStrategy
{
public:
	~SlowMovingStrategy();
	SlowMovingStrategy();
protected:
	bool is_done_move() override;
	
	void move();
	void on_update() override;
private:
	double _speed; //клеток за тик
	double _delta;
};

class SlowMovingStrategyFactory: public MovingStrategyFactory {
public:
	MovingStrategy* create() override;
};
