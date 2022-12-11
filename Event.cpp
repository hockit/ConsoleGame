#include "Event.h"

Player player;
Enemy enemy;

Event::Event()
{
	choice_ = 0;
	fightCount_ = 1;
	saveCharacter = "Save.txt";
}

void Event::events()
{
	
	

	do
	{
	system("cls");
	std::cout << "[0] Load game" << std::endl;
	std::cout << "[1] Dungeon" << std::endl;
	std::cout << "[2] Save game (in prepare)" << std::endl;
	std::cout << "[3] Back to main menu" << std::endl;
	std::cout << "-> ";
	std::cin >> choice_;


		switch (choice_)
		{
		case 0:
			loadGame();
			break;
		case 1:
			fight(player, enemy);
			break;
		case 2:
			saveGame(fightCount_);
			break;
		case 3:
			system("cls");
			break;
		default:
			std::cout << "Invalid input" << std::endl;
			break;
		}
	} while (choice_ != 3);
}



void Event::fight(Player& player, Enemy& enemy)
{
	int playerAttack;
	int enemyAttack;

	system("cls");
	std::cout << "GET READY FOR THE NEXT BATTLE" << std::endl;
	std::cout << std::endl;

	player.showStats();

	std::cout << std::endl;
	std::cout << "=== VS ===" << std::endl;
	std::cout << std::endl;

	enemy.showStats();

	std::cout << std::endl;
	system("pause");
	system("cls");
	std::cout << "ROUND " << fightCount_ << ". FIGHT!" << std::endl;

	do
	{
		srand(time(NULL));

		std::cout << "You attacking..." << std::endl << std::endl;
		playerAttack = ((rand() % player.getAttack() + 2) - rand() % enemy.getDefence());
		Sleep(1500);

		if (playerAttack <= 0) {
			playerAttack = 1;
		}

		enemy.strikePoint(playerAttack);

		std::cout << "Enemy's current stats" << std::endl;
		enemy.showStats();

		if (enemy.getHp() <= 0) {
			std::cout << "ROUND " << fightCount_ << " WIN!!!" << std::endl;
			std::cout << "Enemy is down!" << std::endl << std::endl;
			++fightCount_;
			player.upgradeStats();
			enemy.upgradeStats();
			break;
		}

		std::cout << "Enemy attacking..." << std::endl << std::endl;
		enemyAttack = ((rand() % enemy.getAttack() + 4) - rand() % player.getDefence());
		Sleep(1500);
				

		if (enemyAttack <= 0) {
			enemyAttack = 1;
		}

		player.strikePoint(enemyAttack);

		std::cout << "Player's current stats" << std::endl;
		player.showStats();

		if (player.getHp() <= 0) {
			system("cls");
			choice_ = 3;
			gameOver();
			break;
		}

	} while (player.getHp() > 0 && enemy.getHp() > 0);
}

void Event::gameOver()
{
	--fightCount_;
	std::cout << "YOU DIED" << std::endl;
	std::cout << "You survived " << fightCount_ << " round(s)" << std::endl << std::endl;
}

void Event::saveGame(int& fightCount)
{
	std::ofstream save(saveCharacter);

	if (save.is_open()) {
		save << player.getHpMax() << " ";
		save << player.getHp() << " ";
		save << player.getAttack() << " ";
		save << player.getDefence() << " ";
		save << fightCount;
	}
	else {
		std::cout << "Error." << std::endl;
	}
	save.close();
}

void Event::loadGame()
{
	int hpMax{ 0 };
	int hp{ 0 };
	int attack{ 0 };
	int defence{ 0 };
	int fightCount{ 0 };

	std::ifstream load(saveCharacter);

	if (load.is_open()) {
		while (!load.eof())
		{
			load >> hpMax;
			load.ignore(0, ' ');
			load >> hp;
			load.ignore(0, ' ');
			load >> attack;
			load.ignore(0, ' ');
			load >> defence;
			load.ignore(0, ' ');
			load >> fightCount;
			load.ignore(0, ' ');
		}
	}

	fightCount_ = fightCount;

	player.setHpMax(hpMax);
	player.setHp(hp);
	player.setAttack(attack);
	player.setDefence(defence);

	load.close();
}