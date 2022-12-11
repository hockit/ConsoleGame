#pragma once
class Character
{
public:

	// Pure virtual function
	virtual void showStats() = 0;
	virtual void upgradeStats() = 0;
	virtual void strikePoint(int) = 0;

protected:

	int hpMax_ = 0;
	int hp_ = 0;
	int attack_ = 0;
	int defence_ = 0;
};

