#pragma once
#include "Enemies/EnemyShip.h"
#include "SpawnTypes.h"

class EnemySpawner
{
public:
	enum ShipType
	{
		Slow,
		Fast,
		Circle
	};

	EnemySpawner(ShipType, std::list<EnemyShip*>*);
	void Update();

private:
	EnemyShip* MakeShip(int x, int y) const;
	void Spawn();

	std::list<EnemyShip*>* enemies_list;
	SpawnType* spawn_type = nullptr;
	EnemyShip* _prototype_ship = nullptr;
	
	float current_time;
	float delay;
};

