#pragma once
#include "../MainShip/Spaceship.h"
#include "../Spawner/EnemySpawner.h"
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
	void EnemiesMove();
	void BulletsMove();
	
	RenderWin rw;
	CollisionHandler collision_handler;
	Spaceship main_ship;
	EnemySpawner enemy_spawner_1;
	EnemySpawner enemy_spawner_2;
	EnemySpawner enemy_spawner_3;
	std::list<EnemyShip*> enemy_list;
	std::list<Gun*> bullet_list;
};