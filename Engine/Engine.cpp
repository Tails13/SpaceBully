#include "Engine.h"

Engine::Engine() :
	main_ship(),
	enemy_spawner_1(EnemySpawner::ShipType::Slow, &enemy_list),
	enemy_spawner_2(EnemySpawner::ShipType::Fast, &enemy_list),
	enemy_spawner_3(EnemySpawner::ShipType::Circle, &enemy_list),
	collision_handler(&enemy_list, &bullet_list, &bonus_list, &main_ship)
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

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::R))
	{
		Restart();
	}

	main_ship.Update();

	if (!enemy_list.empty())
		collision_handler.CheckCollisions();

	if (main_ship.dead)
		Restart();

	EnemiesMove();
	BulletsMove();
	BonusMove();

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

void Engine::Restart()
{
	main_ship.hitbox.setPosition(sf::Vector2f(0.f, 250.f));
	main_ship.dead = false;

	enemy_spawner_1.Restart();
	enemy_spawner_2.Restart();
	enemy_spawner_3.Restart();

	if (!enemy_list.empty())
	{
		std::list<EnemyShip*>::iterator it;
		for (it = enemy_list.begin(); it != enemy_list.end(); ++it)
		{
			EnemyShip* temp = *it;
			it = enemy_list.erase(it);
			delete (temp);
			if (it == enemy_list.end()) break;
		}
	}

	if (!bullet_list.empty())
	{
		std::list<Gun*>::iterator it;
		for (it = bullet_list.begin(); it != bullet_list.end(); ++it)
		{
			Gun* temp = *it;
			it = bullet_list.erase(it);
			delete (temp);
			if (it == bullet_list.end()) break;
		}
	}

	if (!bonus_list.empty())
	{
		std::list<Bonus*>::iterator it;
		for (it = bonus_list.begin(); it != bonus_list.end(); ++it)
		{
			Bonus* temp = *it;
			it = bonus_list.erase(it);
			delete (temp);
			if (it == bonus_list.end()) break;
		}
	}
}

void Engine::EnemiesMove()
{
	if (!enemy_list.empty())
	{
		std::list<EnemyShip*>::iterator it;
		for (it = enemy_list.begin(); it != enemy_list.end(); ++it)
		{
			if (!(*it)->IsInBounds() || (*it)->IsDead())	
			{
				if ((*it)->IsDead())	//������� ����� 
				{
					int r = rand() % 10;
					if (r <= 1)
						bonus_list.push_back(Bonus::Create((*it)->X() + 15, (*it)->Y() + 15));
				}

				EnemyShip* temp = *it;
				it = enemy_list.erase(it);
				delete (temp);
				if (it == enemy_list.end()) break;
			}
			else
			{
				(*it)->Move();
				if ((*it)->IsShow())		// �������� ������� � RenderWin ��� ���������
					rw.PutSprite(&(*it)->hitbox);
			}
		}
	}
}

void Engine::BulletsMove()  //���� ����� � ������ 
{
	if (!bullet_list.empty())
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
}

void Engine::BonusMove()
{
	if (!bonus_list.empty())
	{
		std::list<Bonus*>::iterator it;
		for (it = bonus_list.begin(); it != bonus_list.end(); ++it)
		{
			if (!(*it)->IsInBounds() || (*it)->distruction)
			{
				Bonus* temp = *it;
				it = bonus_list.erase(it);
				delete (temp);
				if (it == bonus_list.end()) break;
			}
			else
			{
				(*it)->Update();
				rw.PutSprite(&(*it)->hitbox);
			}
		}
	}
}

Engine::~Engine()
{
	
}