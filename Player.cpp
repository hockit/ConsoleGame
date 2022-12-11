#include "Player.h"


Player::Player()
{
	choice_ = 0;
}

void Player::showStats()
{
	std::cout << "=== YOUR STATS ===" << std::endl;
	std::cout << "HP: " << hp_ << " / " << getHpMax() << std::endl;
	std::cout << "Attack: " << attack_ << std::endl;
	std::cout << "Defence: " << defence_ << std::endl << std::endl;
}

void Player::upgradeStats()
{
	do
	{
		std::cout << "Choose your upgrade:" << std::endl;
		std::cout << "[1] Health points +20" << std::endl;
		std::cout << "[2] Attack points +5" << std::endl;

		std::cout << "->";
		std::cin >> choice_;

		switch (choice_)
		{
		case 1:
			addHp();
			break;
		case 2:
			addAttack();
			break;
		default:
			std::cout << "Invalid input" << std::endl;
		}
	} while (choice_ < 1 || choice_ > 2);

	system("cls");
}

void Player::addHp()
{
	std::cout << "Health points upgraded" << std::endl;
	hpMax_ += 20;
	hp_ = hpMax_;
}

void Player::addAttack()
{
	std::cout << "Attack upgraded" << std::endl;
	attack_ += 5;
}

void Player::strikePoint(int hitPoint)
{
	setHp(getHp() - hitPoint);
}

std::string Player::getAsString() const
{
	return std::to_string(hpMax_) + " "
		+ std::to_string(hp_) + " "
		+ std::to_string(attack_) + " "
		+ std::to_string(defence_) + " ";
}