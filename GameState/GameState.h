#pragma once

#include "../Engine/Engine.h"
#include "Game/CollisionHandler.h"
#include "Game/GameStuff.h"
#include "Game/GUI.h"

class Engine;

class GameState
{
public:
	virtual ~GameState() {}
	virtual void Update(Engine&) {}

private:
};


class Game : public GameState
{
public:
	Game();
	~Game();
	virtual void Update(Engine&);

	friend CollisionHandler;
private:
	void Restart();
	void EnemiesMove();
	void BulletsMove();
	void BonusMove();
	void Render(RenderWin&);
	void GameLogic();

	CollisionHandler collision_handler;
	Spaceship main_ship;
	EnemySpawner enemy_spawner_1;
	EnemySpawner enemy_spawner_2;
	EnemySpawner enemy_spawner_3;
	std::list<EnemyShip*> enemy_list;
	std::list<Gun*> bullet_list;
	std::list<Bonus*> bonus_list;

	GameStuff game_stuff;
	GUI gui;
};

class Menu : public GameState
{
public:
	Menu();
	~Menu();
	enum MenuOption {NewGame, LeaderBoard, Quit};
	virtual void Update(Engine&);

private:
	void Render(Engine&);

	MenuOption current_option;
	bool cursor_switch;
	float switch_cd;
	RenderComponent* menu_gui;
};

class LeaderBoard : public GameState
{
public:
	LeaderBoard();
	~LeaderBoard();
	virtual void Update(Engine&);
	void ReadRecords();

	std::vector<sf::Text> t_records;

private:
	void Render(Engine&);
	sf::Font font;
	std::string str;

};