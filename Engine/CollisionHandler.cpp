#include "CollisionHandler.h"

CollisionHandler::CollisionHandler(std::list<EnemyShip*>* enemies, std::list<Gun*>* bullets, Spaceship* mship)
{
	this->enemy_list = enemies;
	this->bullet_list = bullets;
	this->main_ship = mship;
}

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

bool CollisionHandler::CheckMainShipCollision(Spaceship* mp, EnemyShip* enemy)
{
	for (int i = 0; i < mp->hitbox.getPointCount(); i++)
	{
		//std::cout << "index " << i << ": x - " << mainship->hitbox.getPoint(i).x
			//<< ", y - " << mainship->hitbox.getPoint(i).y << std::endl;

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

void CollisionHandler::CheckCollisions()
{
	std::list<EnemyShip*>::iterator enemy;
	std::list<Gun*>::iterator bullet;
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
			std::cout << "Mainship Destoyed!!" << std::endl;
						
		}
	}
}