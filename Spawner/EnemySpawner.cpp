#include "EnemySpawner.h"

EnemySpawner::EnemySpawner(ShipType ship, std::list<EnemyShip*>* e_list)
{
	enemies_list = e_list;

	switch (ship)
	{
	case Slow:
	{
		_prototype_ship = new SlowShip;
		spawn_type = new SpawnSlow;
		break;
	}
	case Fast:
	{
		_prototype_ship = new FastShip;
		spawn_type = new SpawnFast;
		break;
	}
	case Circle:
	{
		_prototype_ship = new CircleShip;
		spawn_type = new SpawnCircle;
		break;
	}
	}

	current_time = 0;
	delay = spawn_type->SetDelay();
}

void EnemySpawner::Update()
{
	current_time += 0.001;
	if (current_time > delay)
	{
		spawn_type->SetSpawnPositions();
		this->Spawn();
		current_time = 0;
	}
}

void EnemySpawner::Spawn()
{
	for (int i = 0; i < 10; i++)
	{
		if (spawn_type->ship_positions[i].x != 0)
		{
			enemies_list->push_front(MakeShip(spawn_type->ship_positions[i].x, spawn_type->ship_positions[i].y));
		}
	}
}

EnemyShip* EnemySpawner::MakeShip(int x, int y) const
{
	EnemyShip* temp = _prototype_ship->Clone();
	temp->SetPosition(x, y);
	return temp;
}

