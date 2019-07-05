// GardenWarConsoleApp.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <iostream>
#include "Mole.h"
#include "Game.h"
#include "GameField.h"
#include "Gardener.h"
#include "RandomMoleFactory.h"
#include <thread>
#include <chrono>
#include <time.h>
#include <vector>

/*int main()
{
	
	Mole* m;
	Game::field = new GameField(15, 15);
	srand(time(NULL));
	for (int i = 0; i < 15; i++)
		for (int j = 0; j < 15; j++) {
			Game::field->set(i, j, 1);
		}
	Game::mole_factory = new RandomMoleFactory();
	Game::field->create_mole(0, 0);
	Game::field->create_mole(2, 2);
	//Game::field->create_mole(12, 5);
	//Game::field->create_mole(3, 9);
	//Game::field->create_mole(2, 10);
	//Game::field->create_mole(2, 8);
	//Game::field->create_mole(3, 4);
	//Game::field->create_mole(8, 1);
	//Game::field->create_mole(8, 2);
	//Game::field->create_mole(0, 6);
	ObjField* hit_field = new ObjField(3, 3);
	hit_field->set_position(1, 1);
	for (int i = 0; i < hit_field->width(); i++)
		for (int j = 0; j < hit_field->height(); j++)
			hit_field->set(i, j, 1);
	Game::gardener = new Gardener(5, 5, 1, hit_field);
	long c = 0;
	while (true) {
		
		std::this_thread::sleep_for(std::chrono::milliseconds(50));
		system("cls");
		std::cout << c << std::endl;
		c++;
		std::vector<std::string> show_game = Game::field->representation();
		for (int i = 0; i < show_game.size(); i++) {
			std::cout << show_game[i].c_str() << std::endl;
		}
		Game::update();
		//Game::field->update();
		//Game::gardener->update();
		std::cout << Game::field->get_moles().size() << std::endl;
	}
	std::getchar();
}*/

int read_start_moles_count() {
	std::cout << "Enter start amount of moles (moles>=1): ";
	int amount_of_moles;
	std::cin >> amount_of_moles;
	if (amount_of_moles < 1)
		throw "";
	return amount_of_moles;
}

int read_field_width() {
	std::cout << "Enter game field width (width>0): ";
	int width;
	std::cin >> width;
	if (width <= 0)
		throw "";
	return width;
}

int read_field_height() {
	std::cout << "Enter game field height (height>0): ";
	int height;
	std::cin >> height;
	if (height <= 0)
		throw "";
	return height;
}

double read_gardener_speed() {
	std::cout << "Enter gardener speed (speed > 0): ";
	double gardener_speed;
	std::cin >> gardener_speed;
	if (gardener_speed <= 0)
		throw "" ;
	return gardener_speed;
}

ObjField * select_hit_field(std::vector<ObjField*> hit_fields) {
	std::cout << "Select gardener hit field:" << std::endl;
	
	for (int f_ind = 0; f_ind < hit_fields.size(); f_ind++) {
		std::cout << "Field " << f_ind << ":" << std::endl;
		for (int i = 0; i < hit_fields[f_ind]->width()+2; i++) {
			std::cout << ".";
		}
		std::cout << std::endl;
		for (int i = 0; i < hit_fields[f_ind]->width(); i++) {
			std::cout << ".";
			for (int j = 0; j < hit_fields[f_ind]->height(); j++) {
				if (hit_fields[f_ind]->get_position().x == i && hit_fields[f_ind]->get_position().y == j) {
					std::cout << "S";
				}
				else
					std::cout <<  (hit_fields[f_ind]->get(i, j) == 1 ? "o" : " ");
			}
			std::cout << ".";
			std::cout << std::endl;
		}
		for (int i = 0; i < hit_fields[f_ind]->width() + 2; i++) {
			std::cout << ".";
		}
		std::cout << std::endl << std::endl;
	}

	std::cout << "Enter index of selected field(0 - " << hit_fields.size() << "): ";
	int selected_index;
	std::cin >> selected_index;
	return hit_fields[selected_index];
}

void init_game(std::vector<ObjField*> gardener_hit_fields) {
	int start_moles = 0;
	bool repeater = 1;
	while (repeater) {
		try
		{
			start_moles = read_start_moles_count();
			repeater = 0;
		}
		catch (...)
		{
			std::cout << std::endl << "Invalid value of param" << std::endl;
		}

	}
	repeater = 1;
	int field_width = 0;
	while (repeater) {
		try
		{
			field_width = read_field_width();
			repeater = 0;
		}
		catch (...)
		{
			std::cout << std::endl << "Invalid value of param" << std::endl;
		}
	}
	repeater = 1;
	int field_height = 0;
	while (repeater) {
		try
		{
			field_height = read_field_height();
			repeater = 0;
		}
		catch (...)
		{
			std::cout << std::endl << "Invalid value of param" << std::endl;
		}
	}
	repeater = 1;
	double gardener_speed = 0;
	while (repeater) {
		try
		{
			gardener_speed = read_gardener_speed();
			repeater = 0;
		}
		catch (...)
		{
			std::cout << std::endl << "Invalid value of param" << std::endl;
		}
	}
	repeater = 1;
	ObjField* gardener_hit_field = nullptr;
	while (repeater) {
		try
		{
			gardener_hit_field = select_hit_field(gardener_hit_fields);
			repeater = 0;
		}
		catch (...)
		{
			std::cout << std::endl << "Invalid value of param" << std::endl;
		}
	}

	std::cout << "Initialization complete. Starting game";
	for (int i = 0; i < 10; i++) {
		std::cout << ".";
		std::this_thread::sleep_for(std::chrono::milliseconds(300));
	}

	std::cout << std::endl;
	Game::initGame(start_moles, field_width, field_height, new RandomMoleFactory(), gardener_speed, gardener_hit_field);
}

int main()
{
	srand(time(NULL));
	
	ObjField*  hit_field1 = new ObjField(3, 3);
	hit_field1->set_position(1, 1);
	for (int i = 0; i < hit_field1->width(); i++)
		for (int j = 0; j < hit_field1->height(); j++)
			hit_field1->set(i, j, 1);

	ObjField*  hit_field2 = new ObjField(5, 5);
	hit_field1->set_position(1, 1);
	int ** hit_field2_map = new int*[5]{
		new int[5] {0, 0, 1, 0, 0},
		new int[5] {0, 1, 1, 1, 0},
		new int[5] {1, 1, 1, 1, 1},
		new int[5] {0, 1, 1, 1, 0},
		new int[5] {0, 0, 1, 0, 0},
	};
	for (int i = 0; i < hit_field2->width(); i++)
		for (int j = 0; j < hit_field2->height(); j++)
			hit_field2->set(i, j, hit_field2_map[i][j]);
	hit_field2->set_position(2, 2);

	std::vector<ObjField*> gardener_hit_fields;
	gardener_hit_fields.push_back(hit_field1);
	gardener_hit_fields.push_back(hit_field2);
	init_game(gardener_hit_fields);
	//Game::initGame(30, 20, 20, new RandomMoleFactory(), 0.5, hit_field);
	while (true) {
		Game::update();
		std::this_thread::sleep_for(std::chrono::milliseconds(50));
		system("cls");
		std::cout << Game::now() << std::endl;
		std::vector<std::string> show_game = Game::field->representation();
		for (int i = 0; i < show_game.size(); i++) {
			std::cout << show_game[i].c_str() << std::endl;
		}
		if (Game::moles_won()) {
			std::cout << "Moles won" << std::endl;
			break;
		}
		if (Game::gardener_won()) {
			std::cout << "Gardener won" << std::endl;
			break;
		}
	}
	std::getchar();
}