#include "Engine.h"

Engine::Engine() :
	main_ship(),
	enemy_spawner_1(EnemySpawner::ShipType::Slow, &enemy_list),
	enemy_spawner_2(EnemySpawner::ShipType::Fast, &enemy_list),
	enemy_spawner_3(EnemySpawner::ShipType::Circle, &enemy_list),
	collision_handler(&enemy_list, &bullet_list, &main_ship)
{
}

void Engine::Update()
{
	sf::Event event;
	while (rw.window.pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
			rw.window.close();
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::B)) 
	{
		if (main_ship.HasDoubleGun())
			main_ship.DoubleShoot(bullet_list);
		else
			main_ship.Shoot(bullet_list);
	}

	main_ship.Update();

	if (!enemy_list.empty() && !bullet_list.empty())
		collision_handler.CheckCollisions();

	EnemiesMove();
	BulletsMove();

	enemy_spawner_1.Update();
	enemy_spawner_2.Update();
	enemy_spawner_3.Update();

	main_ship.Draw(&rw);
}

void Engine::Render()
{
	if (!rw.RenderListIsEmpty())
		rw.Render();
}

void Engine::EnemiesMove()
{
	std::list<EnemyShip*>::iterator it;
	if (!enemy_list.empty())
	{
		for (it = enemy_list.begin(); it != enemy_list.end(); ++it)
		{
			if (!(*it)->IsInBounds() || (*it)->IsDead())	
			{
				EnemyShip* temp = *it;
				it = enemy_list.erase(it);
				delete (temp);
				if (it == enemy_list.end()) break;
			}
			else
			{
				(*it)->Move();
				if ((*it)->IsShow())		// Передаем корабли в RenderWin для отрисовки
					rw.PutSprite(&(*it)->hitbox);
			}
		}
	}
}

void Engine::BulletsMove()  //Тоже самое с пулями 
{
	std::list<Gun*>::iterator it;
	for (it = bullet_list.begin(); it != bullet_list.end(); ++it)
	{
		if ((*it)->IsOutSide() || (*it)->distruction)
		{
			Gun* temp = *it;
			it = bullet_list.erase(it);
			delete (temp);
			if (it == bullet_list.end()) break;
		}
		else
		{
			(*it)->Update();
			rw.PutSprite(&(*it)->hitbox);
		}
	}
}

Engine::~Engine()
{
	
}