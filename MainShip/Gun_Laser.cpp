#include "Gun.h"

Gun_Laser::Gun_Laser(Spaceship* ms)
{
	this->main_ship = ms;
	this->speed = 10.f;
}

Gun_Laser::Gun_Laser(const Gun_Laser& other)
{
	this->main_ship = other.main_ship;
	this->speed = other.speed;
	this->CreateHitbox();
}

Gun* Gun_Laser::Clone()
{
	return new Gun_Laser(*this);
}