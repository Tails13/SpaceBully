#include "Engine.h"

Engine::Engine() :
	main_ship(),
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

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::B)) 
	{
		if (main_ship.GetGunType() == Spaceship::GunType::Double || 
			main_ship.GetGunType() == Spaceship::GunType::DoubleLaser)
		{
			DoubleShot();
		}
		else
			bullet_list.push_back(main_ship.Shoot());
	}

	main_ship.Control();
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
			if ((*it)->IsInBounds())	// Если корабль в грагицах экрана выполняем перемещение
			{
				(*it)->Move();
				if ((*it)->IsShow())		// Передаем корабли в RenderWin для отрисовки
					rw.PutSprite(&(*it)->hitbox);  
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

void Engine::DoubleShot()
{
	Gun* temp_bullet_1 = main_ship.Shoot();
	Gun* temp_bullet_2 = main_ship.Shoot();
	temp_bullet_1->hitbox.move(sf::Vector2f(0.f, -10.f));
	temp_bullet_2->hitbox.move(sf::Vector2f(0.f, 10.f));
	bullet_list.push_back(temp_bullet_1);
	bullet_list.push_back(temp_bullet_2);
}

void Engine::BulletsMove()
{
	std::list<Gun*>::iterator it;
	for (it = bullet_list.begin(); it != bullet_list.end(); ++it)
	{
		(*it)->Update();
		rw.PutSprite(&(*it)->hitbox);
	}
}

Engine::~Engine()
{
	
}