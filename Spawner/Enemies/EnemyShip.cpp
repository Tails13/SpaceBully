#include "EnemyShip.h"

EnemyShip::~EnemyShip()
{
	std::cout << "destructor\n";
}

bool EnemyShip::IsInBounds()
{
	return this->hitbox.getPosition().x > 100.f;
}