#pragma once
#include "Character.h"
#include <iostream>
#include <string>


class Player : public Character
{
public:
	Player();
	
	void showStats() override;
	void upgradeStats() override;
	void strikePoint(int)override;

	void addHp();
	void addAttack();
	std::string getAsString() const;

	int getHp() { return hp_; }
	int getHpMax() { return hpMax_; }
	int getAttack() { return attack_; }
	int getDefence() { return defence_; }

	void setHp(int hp) { hp_ = hp; }
	void setHpMax(int hpMax) { hpMax_ = hpMax; }
	void setAttack(int attack) { attack_ = attack; }
	void setDefence(int defence) { defence_ = defence; }

private:
	
	int choice_;
	int hpMax_{ 100 };
	int hp_{ hpMax_ };
	int attack_{ 100 };
	int defence_{ 5 };
};

