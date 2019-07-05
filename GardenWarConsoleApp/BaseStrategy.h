#pragma once
class Mole;
class BaseStrategy
{
	friend Mole;
public:
	virtual ~BaseStrategy(){}
	void virtual update() = 0;
	virtual void on_create(){}
	virtual void on_update() {};

protected:
	Mole* const get_mole();
private:
	void set_mole(Mole * m);
	Mole* _m;
};

