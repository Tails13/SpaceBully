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
	texture.loadFromFile("Graphics/SimpleShoot.png");
	sprite.setTexture(texture);

	this->width = other.width;
	this->height = other.height;
	this->main_ship = other.main_ship;
	this->velocity = other.velocity;
	this->damage = other.damage;
	this->distruction = false;

	this->render_data = other.render_data;
	this->CreateHitbox();
}

Gun* Gun_Simple::Clone()
{
	return new Gun_Simple(*this);
}



RenderData Gun_Simple::GetRenderData()
{
	return this->render_data;
}