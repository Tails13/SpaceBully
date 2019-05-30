#pragma once
#include <iostream>

class GameStuff
{
public:
	GameStuff();
	enum BonusType
	{
		Disabled,
		Speed,
		Double,
		Laser,
		Return
	};

	void AddScore(int);
	void AddBonus();
	void ClearBonus();
	void ClearScore();
	int Score();
	BonusType ActiveBonus();

private:
	int score;
	int bonus_count;
	BonusType active_bonus;
};
