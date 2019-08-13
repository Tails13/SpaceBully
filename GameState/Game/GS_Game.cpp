// ��������� ����.
// ������ � ���� ��������� ������ � ���������� ���� ������� �������.

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
	// ������� � �������� ���� ����.
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
	{
		Restart();
		engine.StateSwitch(0);
	}

	// ������� �������� ���������.
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::R))
	{
		Restart();
	}

	if (!main_ship.death.DeathEventActive())
	{
		// ��������
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::B))
		{
			if (main_ship.HasDoubleGun())
				main_ship.DoubleShoot(bullet_list);
			else
				main_ship.Shoot(bullet_list);
		}

		// ��������� �������.
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
				else if (game_stuff.ActiveBonus() == GameStuff::BonusType::LevelDown)
				{
					if (enemy_spawner_1.GetDelay() <= 320 &&
						enemy_spawner_2.GetDelay() <= 200 &&
						enemy_spawner_3.GetDelay() <= 800)
					{
						enemy_spawner_1.DownDelay(80.f);
						enemy_spawner_2.DownDelay(50.f);
						enemy_spawner_3.DownDelay(200.f);
					}
				}

				game_stuff.ClearBonus();
			}
		}
	}

	main_ship.Update();
	gui.Update(game_stuff.CurrentBonus());
	gui.RecordScore(game_stuff.Score());

	// �������� ��������.
	if (!enemy_list.empty())
		collision_handler.CheckCollisions();

	EnemiesMove();
	BulletsMove();
	BonusMove();

	GameLogic();

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

	game_stuff.ClearBonus();
	game_stuff.ClearScore();

	main_ship.Equip(Spaceship::GunType::Simple);
	main_ship.DoubleShootDeactived();

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
	main_ship.DeathEventStop();

	AudioSystem::Instance().StopMusic();
	AudioSystem::Instance().PlayMusic("Game_theme.ogg");
}

// ����������� ��������� ������. ��������� �� ��� �� ������, ���� �� � ��.
void Game::EnemiesMove()
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

					game_stuff.AddScore(50);
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

//���� ����� � ������ 
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

//���� ����� � ��������
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
					game_stuff.AddScore(200);
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

// �������� ����, ��������� � �������, �������� ��� �������.
void Game::Render(RenderWin& rw)
{

	if (!enemy_list.empty())
	{
		std::list<EnemyShip*>::iterator it;
		for (it = enemy_list.begin(); it != enemy_list.end(); ++it)
		{
			if ((*it)->IsShow())		// �������� ������� � RenderWin ��� ���������
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

	if (main_ship.death.DeathEventActive())
	{	
	rw.RecordRenderData(main_ship.death.GetBangRenderData());
	rw.RecordRenderData(main_ship.death.GetSmokeRenderData());
	rw.RecordRenderData(main_ship.death.GetGOMRenderData());
	}

	rw.RecordRenderData(gui.layer1->GetRenderData());
	rw.RecordRenderData(gui.layer2->GetRenderData());
	rw.RecordRenderData(gui.layer3->GetRenderData());
	rw.RenderText(&gui.txt_score);
}

void Game::GameLogic()
{
	if (game_stuff.Score() >= game_stuff.cost_of_level_up)
	{
		game_stuff.cost_of_level_up += 3000;

		if (enemy_spawner_1.GetDelay() > 40 &&
			enemy_spawner_2.GetDelay() > 25 &&
			enemy_spawner_3.GetDelay() > 100)
		{
			enemy_spawner_1.UpDelay(40.f);
			enemy_spawner_2.UpDelay(25.f);
			enemy_spawner_3.UpDelay(100.f);
		}
	}
}

Game::~Game()
{

}