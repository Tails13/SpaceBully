#include "GameStuff.h"

GameStuff::GameStuff()
{
	score = 0;
	bonus_count = 0;
	current_bonus = 0;
	active_bonus = BonusType::Disabled;
	cost_of_level_up = 3000;
}

void GameStuff::AddScore(int n)
{
	score += n;
}

void GameStuff::AddBonus()
{
	bonus_count++;
	current_bonus = 0;
	current_bonus = bonus_count / 4;
	std::cout << current_bonus << std::endl;

	if (current_bonus <= 4)
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
	current_bonus = 0;
}

void GameStuff::ClearScore()
{
	score = 0;
}

int GameStuff::Score()
{
	return score;
}

int GameStuff::CurrentBonus()
{
	return current_bonus;
}

GameStuff::BonusType GameStuff::ActiveBonus()
{
	return active_bonus;
}