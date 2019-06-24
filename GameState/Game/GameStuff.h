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
	int CurrentBonus();
	BonusType ActiveBonus();

private:
	int score;
	int bonus_count;
	int current_bonus;
	BonusType active_bonus;
};
