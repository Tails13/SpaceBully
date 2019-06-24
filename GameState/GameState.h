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
	enum MenuOption {NewGame, LeaderBoard, Quit};
	virtual void Update(Engine&);

private:
	void Render(Engine&);
	void CursorMove();

	sf::RectangleShape cursor;
	sf::RectangleShape option_1;
	sf::RectangleShape option_2;
	sf::RectangleShape option_3;
	MenuOption current_option;
	float cursor_new_position;
	bool cursor_switch;

};