// Состояние Игра.
// Именно в этом состоянии описан и происходит весь игровой процесс.

#include "../GameState.h"

Game::Game() :
	main_ship(),
	enemy_spawner_1(EnemySpawner::ShipType::Slow, &enemy_list),
	enemy_spawner_2(EnemySpawner::ShipType::Fast, &enemy_list),
	enemy_spawner_3(EnemySpawner::ShipType::Circle, &enemy_list),
	collision_handler(&enemy_list, &bullet_list, &bonus_list, &main_ship)
{
}

void Game::Update(Engine& engine)
{
	// Стрельба
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::B))
	{
		if (main_ship.HasDoubleGun())
			main_ship.DoubleShoot(bullet_list);
		else
			main_ship.Shoot(bullet_list);
	}

	// Возврат к главному меню игры.
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
	{
		Restart();
		engine.StateSwitch(0);
	}

	// Рестарт игрового состояния.
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::R))
	{
		Restart();
	}

	// Активация бонусов.
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
	{
		if (game_stuff.ActiveBonus() != GameStuff::BonusType::Disabled)
		{
			if (game_stuff.ActiveBonus() == GameStuff::BonusType::Speed)
			{
				main_ship.SpeedUp(0.5f);
			}
			else if (game_stuff.ActiveBonus() == GameStuff::BonusType::Double)
			{
				main_ship.DoubleShootActived();
			}
			else if (game_stuff.ActiveBonus() == GameStuff::BonusType::Laser)
			{
				main_ship.DoubleShootDeactived();
				main_ship.Equip(Spaceship::GunType::Laser);
			}

			game_stuff.ClearBonus();
		}

	}

	main_ship.Update();
	gui.Update(game_stuff.CurrentBonus());

	// Проверка коллизий.
	if (!enemy_list.empty())
		collision_handler.CheckCollisions();

	// Проверка, не умер ли ГГ.
	// В следующих патчах рестарт должен срабатывать по окончании анимации смерти главного корабля
	if (main_ship.dead)
		Restart();

	EnemiesMove();
	BulletsMove();
	BonusMove();

	engine.rw.RecordRenderData(main_ship.render_component->GetRenderData());
	Render(engine.rw);

	enemy_spawner_1.Update();
	enemy_spawner_2.Update();
	enemy_spawner_3.Update();
}

void Game::Restart()
{
	enemy_spawner_1.Restart();
	enemy_spawner_2.Restart();
	enemy_spawner_3.Restart();

	while (!enemy_list.empty())
	{
		std::list<EnemyShip*>::iterator it;
		it = enemy_list.begin();
		EnemyShip* temp = *it;
		it = enemy_list.erase(it);
		delete (temp);
	}

	while (!bullet_list.empty())
	{
		std::list<Gun*>::iterator it;
		it = bullet_list.begin();
		Gun* temp = *it;
		it = bullet_list.erase(it);
		delete (temp);
	}

	while (!bonus_list.empty())
	{
		std::list<Bonus*>::iterator it;
		it = bonus_list.begin();
		Bonus* temp = *it;
		it = bonus_list.erase(it);
		delete (temp);
	}

	main_ship.hitbox.setPosition(sf::Vector2f(0.f, 250.f));
	main_ship.dead = false;
}

// Проверяются состояния врагов. Находятся ли они на экране, живы ли и тд.
void Game::EnemiesMove()
{
	if (!enemy_list.empty())
	{
		std::list<EnemyShip*>::iterator it;
		for (it = enemy_list.begin(); it != enemy_list.end(); ++it)
		{
			if (!(*it)->IsInBounds() || (*it)->IsDead())
			{
				if ((*it)->IsDead())	//Создаем бонус 
				{
					int r = rand() % 10;
					if (r <= 1)
						bonus_list.push_back(Bonus::Create((*it)->X() + 15, (*it)->Y() + 15));

					game_stuff.AddScore(50);
					// @@@@@
					//std::cout << game_stuff.Score() << std::endl;
				}

				EnemyShip * temp = *it;
				it = enemy_list.erase(it);
				delete (temp);
				if (it == enemy_list.end()) break;
			}
			else
			{
				(*it)->Move();
			}
		}
	}
}

//Тоже самое с пулями 
void Game::BulletsMove()  
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
			}
			(*it)->Update();
		}
	}
}

//Тоже самое с бонусами
void Game::BonusMove()
{
	if (!bonus_list.empty())
	{
		std::list<Bonus*>::iterator it;
		for (it = bonus_list.begin(); it != bonus_list.end(); ++it)
		{
			if (!(*it)->IsInBounds() || (*it)->distruction)
			{
				if ((*it)->distruction)
				{
					game_stuff.AddBonus();
					game_stuff.AddScore(500);
					//std::cout << game_stuff.Score() << std::endl;
				}

				Bonus* temp = *it;
				it = bonus_list.erase(it);
				delete (temp);
				if (it == bonus_list.end()) break;
			}
			else
			{
				(*it)->Update();
			}
		}
	}
}

// Передача всех, имеющихся в списках, объектов для рендера.
void Game::Render(RenderWin& rw)
{

	if (!enemy_list.empty())
	{
		std::list<EnemyShip*>::iterator it;
		for (it = enemy_list.begin(); it != enemy_list.end(); ++it)
		{
			if ((*it)->IsShow())		// Передаем корабли в RenderWin для отрисовки
				rw.RecordRenderData((*it)->render_component->GetRenderData());
		}
	}

	if (!bullet_list.empty())
	{
		std::list<Gun*>::iterator it;
		for (it = bullet_list.begin(); it != bullet_list.end(); it++)
		{
			rw.RecordRenderData((*it)->render_component->GetRenderData());
		}
	}

	if (!bonus_list.empty())
	{
		std::list<Bonus*>::iterator it;
		for (it = bonus_list.begin(); it != bonus_list.end(); ++it)
		{
			rw.RecordRenderData((*it)->render_component->GetRenderData());
		}
	}

	rw.RecordRenderData(gui.layer1->GetRenderData());
	rw.RecordRenderData(gui.layer2->GetRenderData());
	rw.RecordRenderData(gui.layer3->GetRenderData());
	rw.RecordRenderData(gui.score->GetRenderData());
}

Game::~Game()
{

}