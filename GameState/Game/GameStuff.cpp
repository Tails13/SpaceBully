#include "GameStuff.h"

GameStuff::GameStuff()
{
	score = 0;
	bonus_count = 0;
	current_bonus = 0;
	active_bonus = BonusType::Disabled;
	cost_of_level_up = 3000;
	record_list.resize(7);
	open_for_record = true;
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

void GameStuff::SortRecordList(int score)
{
	if (score > record_list[6])
	{
		record_list[6] = score;
		std::sort(record_list.rbegin(), record_list.rend());

		// Вместо этого запись в файл
		for (int i = 0; i < 6; i++)
		{
			std::cout << record_list[i] << std::endl;
		}

		std::ofstream ofs;
		ofs.open("Resources/records.txt");
		for (int i = 0; i < 6; i++)
		{
			int temp = i + 1;
			ofs << temp << ". " << record_list[i] << std::endl;
		}
		ofs.close();
	}
}