#pragma once
#include "Event.h"
#include <iostream>

class Game
{
public:
	Game();
	void mainMenu();

	bool getIsPlaying_() const { return isPlaying_; }

private:
	int choice_;
	bool isPlaying_;
};

