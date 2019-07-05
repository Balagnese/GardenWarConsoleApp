#pragma once
#include "Position.h"
#include "BaseStrategy.h"
#include "MovingObject.h"

#include "LoveStrategy.h"

enum class Sex
{
	MALE,
	FEMALE
};

class EatingStrategyFactory;
class LoveStrategyFactory;
class MovingStrategyFactory;

class Mole: public MovingObject
{
public:
	Mole() = delete;
	Mole(int x, int y, Sex s);
	virtual ~Mole();
	bool is_loving();
	void update();
	void start_move();
	void start_love();
	void start_eat();
	Sex get_sex();
private:

	int age;

	static const int grow_up_time = 20;

public:
	int time_until_love;
	bool _is_under_ground;
	inline bool is_under_ground();
	//friend void LoveStrategy::set_time_until_love(int);
private:
	static const int love_time = 30;
	Sex mole_sex;
	BaseStrategy* active_strategy;
	Mole* find_partner();
	bool ready_to_love();
	bool is_adult();

	void init_new_strategy();
protected:
	EatingStrategyFactory* eating_strategy_fact;
	LoveStrategyFactory* love_strategy_fact;
	MovingStrategyFactory* moving_strategy_fact;
};

