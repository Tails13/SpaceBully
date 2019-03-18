#pragma once
#include "Engine.h"

class CollisionHandler
{
public:
	CollisionHandler(std::list<EnemyShip*>*, std::list<Gun*>*, Spaceship*);
	void CheckCollisions();
private:
	std::list<EnemyShip*>* enemy_list;
	std::list<Gun*>* bullet_list;
	Spaceship* main_ship;

	bool CheckBulletsColision(Gun*, EnemyShip*);
	bool CheckMainShipCollision(Spaceship*, EnemyShip*);
};