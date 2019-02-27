#include "Engine.h"

Engine::Engine() : sp_ship()
{
	slow_ship = new SlowShip;
	fast_ship = new FastShip;
}

void Engine::Update()
{
	sf::Event event;
	while (rw.window.pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
			rw.window.close();
	}

	EnemiesSpawn(enemy_spawner_1, fast_ship);
	EnemiesSpawn(enemy_spawner_2, slow_ship);

	EnemiesMove();
	EnemiesDraw();

	sp_ship.Draw(&rw);
}

void Engine::Render()
{
	rw.Render();
}

void Engine::EnemiesSpawn(EnemySpawner& spawner, EnemyShip* prototype) //****
{
	if (!spawner.HasAPrototype())  //  Задаем прототип для спавна + рандомный прототип спавна
		spawner.SetPrototype(prototype);

	if (!spawner.bCreate)		// Здесь будет задержка между спавнами 
	{
		spawner.bCreate = true;
		std::cout << "Spawn begin!\n";
	}

	if (spawner.bCreate)
		spawner.Spawn(enemy_list);
}

void Engine::EnemiesMove()
{
	std::list<EnemyShip*>::iterator it;
	if (!enemy_list.empty())
	{
		for (it = enemy_list.begin(); it != enemy_list.end(); it++)
		{
			if ((*it)->IsInBounds())	// Если корабль в грагицах экрана выполняем перемещение
				(*it)->Move();
			else  // Или удляем корабль, если он покинул экран
			{
				EnemyShip* temp = *it;
				it = enemy_list.erase(it);
				delete (temp);	
				std::cout << "Ship destroy\n";
			}
		}
	}
}

void Engine::EnemiesDraw()
{
	std::list<EnemyShip*>::iterator it;
	if (!enemy_list.empty())
	{
		for (it = enemy_list.begin(); it != enemy_list.end(); it++)
		{
			rw.PutSprite(&(*it)->hitbox);	// Передаем все корабли в RenderWin для отрисовки
		}
	}
}

Engine::~Engine()
{
	
}