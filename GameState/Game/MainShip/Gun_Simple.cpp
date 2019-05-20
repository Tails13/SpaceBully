#include "Gun.h"

Gun_Simple::Gun_Simple(Spaceship* ms)
{
	this->main_ship = ms;
	this->velocity.x = 20.f;
	this->width = 30.f;
	this->height = 10.f;
	this->damage = 10;
	this->distruction = false;
}

Gun_Simple::Gun_Simple(const Gun_Simple& other)
{
	render_component = new RenderComponent("Graphics/SimpleShoot.png");

	this->width = other.width;
	this->height = other.height;
	this->main_ship = other.main_ship;
	this->velocity = other.velocity;
	this->damage = other.damage;
	this->distruction = false;

	this->CreateHitbox();
}

Gun* Gun_Simple::Clone()
{
	return new Gun_Simple(*this);
}
