#include "Engine.h"

Engine::Engine() :
	main_ship(),
	enemy_spawner_1(EnemySpawner::ShipType::Slow, &enemy_list),
	enemy_spawner_2(EnemySpawner::ShipType::Fast, &enemy_list),
	enemy_spawner_3(EnemySpawner::ShipType::Circle, &enemy_list)
{
	main_ship.Equip(Spaceship::Guns::Simple);
}

void Engine::Update()
{
	sf::Event event;
	while (rw.window.pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
			rw.window.close();
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::B)) bullet_list.push_back(main_ship.Shoot());

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
			if ((*it)->IsInBounds())	// ���� ������� � �������� ������ ��������� �����������
			{
				(*it)->Move();
				if ((*it)->IsShow())		// �������� ������� � RenderWin ��� ���������
					rw.PutSprite(&(*it)->hitbox);  
			}
			else  // ��� ������ �������, ���� �� ������� �����
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