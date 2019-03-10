#include "Gun.h"

Gun_Simple::Gun_Simple(Spaceship* ms)
{
	this->main_ship = ms;
	this->speed = 10.f;
}

Gun_Simple::Gun_Simple(const Gun_Simple& other)
{
	this->main_ship = other.main_ship;
	this->speed = other.speed;
	this->CreateHitbox();
}

Gun* Gun_Simple::Clone()
{
	return new Gun_Simple(*this);
}