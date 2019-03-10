#include "EnemyShip.h"

EnemyShip::~EnemyShip()
{
	std::cout << "destructor\n";
}

bool EnemyShip::IsInBounds()
{
	return this->hitbox.getPosition().x > -50.f;
}

bool EnemyShip::IsShow()
{
	return this->hitbox.getPosition().x < 1000;
}

float EnemyShip::GetSpeedX()
{
	return this->speed_x;
}

float EnemyShip::GetSpeedY()
{
	return this->speed_y;
}