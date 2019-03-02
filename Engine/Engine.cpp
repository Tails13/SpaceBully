#include "Engine.h"

Engine::Engine() :
	sp_ship(),
	enemy_spawner_1(EnemySpawner::ShipType::Slow, &enemy_list),
	enemy_spawner_2(EnemySpawner::ShipType::Fast, &enemy_list),
	enemy_spawner_3(EnemySpawner::ShipType::Circle, &enemy_list)
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


	EnemiesMove();

	enemy_spawner_1.Update();
	enemy_spawner_2.Update();
	enemy_spawner_3.Update();

	sp_ship.Draw(&rw);
}

void Engine::Render()
{
	rw.Render();
}

void Engine::EnemiesMove()
{
	std::list<EnemyShip*>::iterator it;
	if (!enemy_list.empty())
	{
		for (it = enemy_list.begin(); it != enemy_list.end(); ++it)
		{
			if ((*it)->IsInBounds())	// Если корабль в грагицах экрана выполняем перемещение
			{
				(*it)->Move();
				rw.PutSprite(&(*it)->hitbox);  // Передаем все корабли в RenderWin для отрисовки
			}
			else  // Или удляем корабль, если он покинул экран
			{
				EnemyShip* temp = *it;
				it = enemy_list.erase(it);
				delete (temp);	
				std::cout << "Ship destroy\n";
				if (it == enemy_list.end()) break;
			}
		}
	}
}

Engine::~Engine()
{
	
}