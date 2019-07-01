#include "EnemyShip.h"

CircleShip::CircleShip()
{
	this->velocity.x = 5.f;

	this->width = 50.f;
	this->height = 50.f;
	this->hp = 30;
	this->dead = false;
}

CircleShip::CircleShip(const CircleShip& other)
{
	render_component = new RenderComponent("Resources/Graphics/Enemy_Circle.png");

	this->width = other.width;
	this->height = other.height;
	this->CreateHitbox();
	this->velocity = other.velocity;
	this->hp = other.hp;
	this->dead = other.dead;

	render_component->CollectRenderData(velocity, hitbox.getPosition());

	animator_manager.SetAM(render_component->GetRenderData().sprite_for_drawing, width, height); 
	animator_manager.SetNumberAnimation(0);
	animator_manager.SetNumberFrame(0);
	animator_manager.SetLastFrame(4);
}

void CircleShip::SetPosition(float x, float y)
{
	hitbox.setPosition(sf::Vector2f(x, y));
}

void CircleShip::Move()
{
	float new_x = this->hitbox.getPosition().x - velocity.x;
	float new_y = this->hitbox.getPosition().y;
	SetPosition(new_x, new_y);
	render_component->CollectRenderData(velocity, hitbox.getPosition());
	animator_manager.PlayAnimation();
}

CircleShip* CircleShip::Clone() const 
{
	return new CircleShip(*this);
}

void CircleShip::CreateHitbox()
{
	hitbox.setSize(sf::Vector2f(width, height));
	hitbox.setFillColor(sf::Color::Blue);
}


