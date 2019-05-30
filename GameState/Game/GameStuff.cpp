#include "GameStuff.h"

GameStuff::GameStuff()
{
	score = 0;
	bonus_count = 0;
	active_bonus = BonusType::Disabled;
}

void GameStuff::AddScore(int n)
{
	score += n;
}

void GameStuff::AddBonus()
{
	bonus_count++;
	int current_bonus = bonus_count / 3;
	std::cout << current_bonus << std::endl;

	if (current_bonus < 5)
	{
		active_bonus = BonusType(current_bonus);
	}
	else
	{
		bonus_count = 0;
	}
}

void GameStuff::ClearBonus()
{
	active_bonus = GameStuff::BonusType::Disabled;
	bonus_count = 0;
	std::cout << "Bonus Counter Test: " << active_bonus << std::endl;
}

void GameStuff::ClearScore()
{
	score = 0;
}

int GameStuff::Score()
{
	return score;
}

GameStuff::BonusType GameStuff::ActiveBonus()
{
	return active_bonus;
}