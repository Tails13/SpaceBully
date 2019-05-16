#include "CollisionHandler.h"

// Принимает параметром все списки с объектами для которых нужно расчитать коллизию.
CollisionHandler::CollisionHandler(std::list<EnemyShip*>* enemies, std::list<Gun*>* bullets, 
									std::list<Bonus*>* bonus, Spaceship* mship)
{
	this->enemy_list = enemies;
	this->bullet_list = bullets;
	this->bonus_list = bonus;
	this->main_ship = mship;
}

// Расчет коллизий пули с вражеским кораблём.
bool CollisionHandler::CheckBulletsColision(Gun* bullet, EnemyShip* enemy)
{
	if (bullet->X() + bullet->Width() >= enemy->X()
		&& bullet->X() <= enemy->X() + enemy->Width()
		&& bullet->Y() + bullet->Height() >= enemy->Y()
		&& bullet->Y() <= enemy->Y() + enemy->Height()
		)
		return true;
	else
		return false;
}

// Расчет коллизий игрока с вражеским кораблём.
bool CollisionHandler::CheckMainShipCollision(Spaceship* mp, EnemyShip* enemy)
{
	for (int i = 0; i < mp->hitbox.getPointCount(); i++)
	{
		if ((mp->hitbox.getPosition().x + mp->hitbox.getPoint(i).x) >= enemy->X()
			&& (mp->hitbox.getPosition().x + mp->hitbox.getPoint(i).x) <= enemy->X() + enemy->Width()
			&& (mp->hitbox.getPosition().y + mp->hitbox.getPoint(i).y) >= enemy->Y()
			&& (mp->hitbox.getPosition().y + mp->hitbox.getPoint(i).y) <= enemy->Y() + enemy->Height()
			)
		{
			return true;
		}
	}
	return false;
}

// Расчет коллизий игрока с бонусом.
bool CollisionHandler::CheckBonusCollision(Spaceship* mp, Bonus* bonus)
{
	for (int i = 0; i < mp->hitbox.getPointCount(); i++)
	{
		if ((mp->hitbox.getPosition().x + mp->hitbox.getPoint(i).x) >= bonus->X()
			&& (mp->hitbox.getPosition().x + mp->hitbox.getPoint(i).x) <= bonus->X() + bonus->Width()
			&& (mp->hitbox.getPosition().y + mp->hitbox.getPoint(i).y) >= bonus->Y()
			&& (mp->hitbox.getPosition().y + mp->hitbox.getPoint(i).y) <= bonus->Y() + bonus->Height()
			)
		{
			return true;
		}
	}
	return false;
}

// Основная проверка. Перебирает все элементы списков и
// выполняет соответствующую логику, если с помощью
// вышеописанных функций обнаружено столкновение.
void CollisionHandler::CheckCollisions()
{
	std::list<EnemyShip*>::iterator enemy;
	std::list<Gun*>::iterator bullet;
	std::list<Bonus*>::iterator bonus;
	for (bullet = (*bullet_list).begin(); bullet != (*bullet_list).end(); bullet++)
	{
		for (enemy = (*enemy_list).begin(); enemy != (*enemy_list).end(); enemy++)
		{
			if (CheckBulletsColision(*bullet, *enemy))
			{
				//std::cout << "Damage deal!!" << std::endl;

				(*enemy)->TakeDamage((*bullet)->DealDamage());
				(*bullet)->distruction = true;
			}
		}
	}

	for (enemy = (*enemy_list).begin(); enemy != (*enemy_list).end(); enemy++)
	{
		if (CheckMainShipCollision(main_ship, *enemy))
		{
			main_ship->dead = true;
		}
	}

	for (bonus = (*bonus_list).begin(); bonus != (*bonus_list).end(); bonus++)
	{
		if (CheckBonusCollision(main_ship, *bonus))
		{
			std::cout << "Bonus catched!!" << std::endl;

			(*bonus)->distruction = true;
		}
	}
}