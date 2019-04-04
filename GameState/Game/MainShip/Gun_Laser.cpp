#include "Gun.h"

Gun_Laser::Gun_Laser(Spaceship* ms)
{
	this->main_ship = ms;
	this->speed = 20.f;
	this->width = 50.f;
	this->height = 10.f;
	this->damage = 15;
	this->distruction = false;
}

Gun_Laser::Gun_Laser(const Gun_Laser& other)
{
	this->width = other.width;
	this->height = other.height;
	this->main_ship = other.main_ship;
	this->speed = other.speed;
	this->damage = other.damage;
	this->distruction = false;
	this->CreateHitbox();
}

Gun* Gun_Laser::Clone()
{
	return new Gun_Laser(*this);
}