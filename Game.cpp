#include "Game.h"

Event event;

Game::Game()
{
	isPlaying_ = true;
	choice_ = 0;
}

void Game::mainMenu()
{
	std::cout << "=== MAIN MENU ===" << std::endl;
	std::cout << "[0] Quit" << std::endl;
	std::cout << "[1] Start game" << std::endl;
	std::cout << "Choice option: ";

	std::cin >> choice_;

	switch (choice_)
	{
	case 0:
		std::cout << std::endl << "END GAME" << std::endl;
		isPlaying_ = false;
		break;
	case 1:
		event.events();
		break;
	default:
		std::cout << "Invalid input" << std::endl;
		break;
	}
}

