#pragma once
#include "Character.h"
#include <iostream>

class Enemy : public Character
{
public:

	Enemy();


	void showStats();
	void upgradeStats();
	void strikePoint(int);


	int getHp() { return hp_; }
	int getHpMax() { return hpMax_; }
	int getAttack() { return attack_; }
	int getDefence() { return defence_; }

	void setHp(int hp) { hp_ = hp; }

private:

	int hpMax_;
	int hp_;
	int attack_;
	int defence_;
};

