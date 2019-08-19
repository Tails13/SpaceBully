#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

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
		LevelDown,
		Return
	};

	void AddScore(int);
	void AddBonus();
	void ClearBonus();
	void ClearScore();
	int Score();
	int CurrentBonus();
	BonusType ActiveBonus();
	void SortRecordList(int score);

	bool open_for_record;
	int cost_of_level_up;

private:
	int score;
	int bonus_count;
	int current_bonus;
	BonusType active_bonus;
	std::vector<int> record_list;
};
