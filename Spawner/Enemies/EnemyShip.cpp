#include "EnemyShip.h"

EnemyShip::~EnemyShip()
{
	std::cout << "destructor Ship\n";
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

float EnemyShip::Width()
{
	return this->width;
}

float EnemyShip::Height()
{
	return this->height;
}

float EnemyShip::X()
{
	return this->hitbox.getPosition().x;
}

float EnemyShip::Y()
{
	return this->hitbox.getPosition().y;
}