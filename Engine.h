#pragma once
#include "Spaceship.h"
#include "Spawner/EnemySpawner.h"

class Engine
{
public:
	Engine();
	~Engine();
	void Update();
	void Render();
private:
	void EnemiesSpawn(EnemySpawner&, EnemyShip*);
	void EnemiesMove();
	void EnemiesDraw();

	RenderWin rw;
	Spaceship sp_ship;
	SlowShip* slow_ship;
	FastShip* fast_ship;
	EnemySpawner enemy_spawner_1;
	EnemySpawner enemy_spawner_2;
	std::list<EnemyShip*> enemy_list;
};