#include "FastShip.h"

FastShip::FastShip()
{
	CreateHitbox();
}

FastShip::FastShip(const FastShip& other)
{
	CreateHitbox();
}

void FastShip::SetPosition(float x, float y)
{
	hitbox.setPosition(sf::Vector2f(x, y));
}

void FastShip::Move()
{
	float new_x = this->hitbox.getPosition().x - 0.06f;
	float new_y = this->hitbox.getPosition().y;
	SetPosition(new_x, new_y);
}

FastShip* FastShip::Clone() const // Не забыть delete!
{
	return new FastShip(*this);
}

void FastShip::CreateHitbox()
{
	hitbox.setPointCount(4);
	hitbox.setPoint(0, sf::Vector2f(0.f, 0.f));
	hitbox.setPoint(1, sf::Vector2f(50.f, 0.f));
	hitbox.setPoint(2, sf::Vector2f(50.f, 30.f));
	hitbox.setPoint(3, sf::Vector2f(0.f, 30.f));
	hitbox.setFillColor(sf::Color::Green);
}