#pragma once
#include "MovingStrategy.h"
class FastMovingStrategy: public MovingStrategy
{
public:
	FastMovingStrategy();
	~FastMovingStrategy();
protected:
	bool is_done_move() override;
	void move();
	void on_update() override;
private:
	double _speed; //клеток за тик
	double _delta;
};

class FastMovingStrategyFactory : public MovingStrategyFactory {
public:
	MovingStrategy* create() override;
};
