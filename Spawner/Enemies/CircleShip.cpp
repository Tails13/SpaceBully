#include "EnemyShip.h"

CircleShip::CircleShip()
{
	CreateHitbox();
}

CircleShip::CircleShip(const CircleShip& other)
{
	this->CreateHitbox();
}

void CircleShip::SetPosition(float x, float y)
{
	hitbox.setPosition(sf::Vector2f(x, y));
}

void CircleShip::Move()
{
	float new_x = this->hitbox.getPosition().x - 0.05f;
	float new_y = this->hitbox.getPosition().y;
	SetPosition(new_x, new_y);
}

CircleShip* CircleShip::Clone() const // �� ������ delete!
{
	return new CircleShip(*this);
}

void CircleShip::CreateHitbox()
{
	hitbox.setPointCount(4);
	hitbox.setPoint(0, sf::Vector2f(0.f, 0.f));
	hitbox.setPoint(1, sf::Vector2f(50.f, 0.f));
	hitbox.setPoint(2, sf::Vector2f(50.f, 50.f));
	hitbox.setPoint(3, sf::Vector2f(0.f, 50.f));
	hitbox.setFillColor(sf::Color::Blue);
}