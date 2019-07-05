#pragma once
#include "BaseStrategy.h"
class EatingStrategy: public BaseStrategy
{
public:
	~EatingStrategy();	
protected:
	EatingStrategy();
	virtual bool is_done_eating() = 0;
	virtual void eat() = 0;
	void update() override final;
	void on_create() override;
	void set_under_ground(bool b);
};

class EatingStrategyFactory {
public:
	virtual EatingStrategy* create()=0;
};
