#pragma once
#include "GameField.h"
#include "Mole.h"
#include "MoleFactory.h"
#include "ObjField.h"

//class MoleFactory;
class Gardener;
static class Game
{
public:
	~Game();
	static GameField* field;
	static Gardener* gardener;
	static MoleFactory* mole_factory;
	static long now();
	static void update();
	static void initGame(int start_moles_count, int field_width, int field_height, MoleFactory* moles_factory, float gandener_speed, ObjField* gardener_attack_field);
	static bool gardener_won();
	static bool moles_won();
private:
	static long time;
};



