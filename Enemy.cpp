#include "Enemy.h"


Enemy::Enemy()
{
	hpMax_ = 70;
	hp_ = hpMax_;
	attack_ = 7;
	defence_ = 5;
}

void Enemy::showStats()
{
	std::cout << "=== ENEMY'S STATS ===" << std::endl;
	std::cout << "HP: " << hp_ << " / " << hpMax_ << std::endl;
	std::cout << "Attack: " << attack_ << std::endl;
	std::cout << "Defence: " << defence_ << std::endl << std::endl;
}

void Enemy::upgradeStats()
{
	hpMax_ += 10;
	attack_ += 3;
	hp_ = hpMax_;
}

void Enemy::strikePoint(int hitPoint)
{
	setHp(getHp() - hitPoint);
}