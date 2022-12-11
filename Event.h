#pragma once
#include <iostream>
#include <time.h>
#include <Windows.h>
#include <fstream>
#include <string>
#include <iomanip>
#include "Player.h"
#include "Enemy.h"

class Event
{
public:
	Event();

	void events();
	void fight(Player&, Enemy&);
	void saveGame(int&);
	void loadGame();
	void gameOver();


private:
	int choice_;
	int fightCount_;
	std::string saveCharacter;
};

