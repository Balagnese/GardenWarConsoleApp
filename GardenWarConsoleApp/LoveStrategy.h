#pragma once
#include "BaseStrategy.h"
#include "Mole.h"
class LoveStrategy: public BaseStrategy
{
	friend class Mole;
public:
	LoveStrategy();
	//~LoveStrategy();
protected:
	bool is_done_love();
	void set_time_until_love(int time);
	int const loving_time = 20;
	int time_start_love;
	void update() override final;
	void on_create() override;
};

class LoveStrategyFactory {
public:
	LoveStrategy* create();
};

