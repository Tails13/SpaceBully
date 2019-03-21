#include "EnemyShip.h"

CircleShip::CircleShip()
{
	CreateHitbox();
	this->speed_x = 5.f;
	this->speed_y = 0.f;
	this->width = 50.f;
	this->height = 50.f;
	this->hp = 30;
	this->dead = false;
}

CircleShip::CircleShip(const CircleShip& other)
{
	this->width = other.width;
	this->height = other.height;
	this->CreateHitbox();
	this->speed_x = other.speed_x;
	this->speed_y = other.speed_y;
	this->hp = other.hp;
	this->dead = other.dead;
}

void CircleShip::SetPosition(float x, float y)
{
	hitbox.setPosition(sf::Vector2f(x, y));
}

void CircleShip::Move()
{
	float new_x = this->hitbox.getPosition().x - speed_x;
	float new_y = this->hitbox.getPosition().y;
	SetPosition(new_x, new_y);
}

CircleShip* CircleShip::Clone() const // Не забыть delete!
{
	return new CircleShip(*this);
}

void CircleShip::CreateHitbox()
{
	hitbox.setPointCount(4);
	hitbox.setPoint(0, sf::Vector2f(0.f, 0.f));
	hitbox.setPoint(1, sf::Vector2f(width, 0.f));
	hitbox.setPoint(2, sf::Vector2f(width, height));
	hitbox.setPoint(3, sf::Vector2f(0.f, height));
	hitbox.setFillColor(sf::Color::Blue);
}