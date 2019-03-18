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

bool CollisionHandler::CheckMainShipCollision(Spaceship*, EnemyShip*)
{
	return true;
}

void CollisionHandler::CheckCollisions()
{
	
}