#pragma once

#include "CollisionHandler.h"

class Engine
{
public:
	Engine();
	~Engine();
	void Update();
	void Render();

	friend CollisionHandler;
private:
	void Restart();
	void EnemiesMove();
	void BulletsMove();
	void BonusMove();
	
	RenderWin rw;
	CollisionHandler collision_handler;
	Spaceship main_ship;
	EnemySpawner enemy_spawner_1;
	EnemySpawner enemy_spawner_2;
	EnemySpawner enemy_spawner_3;
	std::list<EnemyShip*> enemy_list;
	std::list<Gun*> bullet_list;
	std::list<Bonus*> bonus_list;
};