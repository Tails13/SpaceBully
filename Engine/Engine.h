#pragma once
#include "../MainShip/Spaceship.h"
#include "../Spawner/EnemySpawner.h"

class Engine
{
public:
	Engine();
	~Engine();
	void Update();
	void Render();
private:
	void EnemiesMove();
	void BulletsMove();
	void DoubleShot();
	
	RenderWin rw;
	Spaceship main_ship;
	EnemySpawner enemy_spawner_1;
	EnemySpawner enemy_spawner_2;
	EnemySpawner enemy_spawner_3;
	std::list<EnemyShip*> enemy_list;
	std::list<Gun*> bullet_list;
};