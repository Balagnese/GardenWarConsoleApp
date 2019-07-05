#pragma once
#include "EatingStrategy.h"
#include "Mole.h"
#include "ObjField.h"

class GreeadyEatingStrategy: public EatingStrategy
{
public:
	~GreeadyEatingStrategy();
	GreeadyEatingStrategy();

protected:
	bool is_done_eating() override;
	void eat() override;
	void on_update() override;
	void on_create() override;
private:
	ObjField* eating_field;
	int eating_time;
	int time_start_eating;

};

class GreedyEatingStrategyFactory:public EatingStrategyFactory {
public:
	EatingStrategy* create() override;
};