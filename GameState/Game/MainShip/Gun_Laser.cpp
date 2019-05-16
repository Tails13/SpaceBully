#include "Gun.h"

Gun_Laser::Gun_Laser(Spaceship* ms)
{
	this->main_ship = ms;
	this->velocity.x = 20.f;
	this->width = 30.f;
	this->height = 10.f;
	this->damage = 15;
	this->distruction = false;
}

Gun_Laser::Gun_Laser(const Gun_Laser& other)
{
	this->width = other.width;
	this->height = other.height;
	this->main_ship = other.main_ship;
	this->velocity = other.velocity;
	this->damage = other.damage;
	this->distruction = false;
	this->CreateHitbox();
}

Gun* Gun_Laser::Clone()
{
	return new Gun_Laser(*this);
}

// ÄÓÁËÈÊÀÒ ÊÎÄÀ!
RenderData Gun_Laser::GetRenderData()
{
	return this->render_data;
}