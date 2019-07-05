#pragma once
#include "Field.h"
#include "Mole.h"
#include <vector>
#include <string.h>

class GameField: public Field
{
public:
	GameField(int _width, int _height);
	~GameField();
	int killed_moles;
	void update();
	void create_mole(int x, int y);
	std::vector<Mole*> get_moles();
	std::vector<Mole*> get_eating_moles();
	void kill_moles(std::vector<Mole*> moles);
	void add_mole(Mole* mole);
	std::vector<std::string> representation();
private:
	std::vector<Mole*> _moles;
};

