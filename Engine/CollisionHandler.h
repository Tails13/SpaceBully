#pragma once
#include "../MainShip/Spaceship.h"
#include "../Spawner/EnemySpawner.h"

class CollisionHandler
{
public:
	CollisionHandler(std::list<EnemyShip*>*, std::list<Gun*>*, std::list<Bonus*>*, Spaceship*);
	void CheckCollisions();
private:
	std::list<EnemyShip*>* enemy_list;
	std::list<Gun*>* bullet_list;
	std::list<Bonus*>* bonus_list;
	Spaceship* main_ship;

	bool CheckBulletsColision(Gun*, EnemyShip*);
	bool CheckMainShipCollision(Spaceship*, EnemyShip*);
	bool CheckBonusCollision(Spaceship*, Bonus*);
};