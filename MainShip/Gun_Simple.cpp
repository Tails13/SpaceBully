#include "Gun.h"

Gun_Simple::Gun_Simple(Spaceship* ms)
{
	this->main_ship = ms;
	this->speed = 20.f;
	this->width = 50.f;
	this->height = 10.f;
	this->distruction = false;
}

Gun_Simple::Gun_Simple(const Gun_Simple& other)
{
	this->width = other.width;
	this->height = other.height;
	this->main_ship = other.main_ship;
	this->speed = other.speed;
	this->distruction = false;
	this->CreateHitbox();
}

Gun* Gun_Simple::Clone()
{
	return new Gun_Simple(*this);
}