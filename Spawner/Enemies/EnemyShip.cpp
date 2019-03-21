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

void EnemyShip::TakeDamage(int dmg)
{
	this->hp -= dmg;
	if (this->hp <= 0)
	{
		this->dead = true;
		//std::cout << "Ship destroyed!" << std::endl;
	}
}

bool EnemyShip::IsDead()
{
	return this->dead;
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