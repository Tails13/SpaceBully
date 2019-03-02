#include "EnemyShip.h"

SlowShip::SlowShip()
{
	CreateHitbox();
}

SlowShip::SlowShip(const SlowShip& other)
{
	this->CreateHitbox();
}

void SlowShip::SetPosition(float x, float y)
{
	hitbox.setPosition(sf::Vector2f(x, y));
}

void SlowShip::Move()
{
	float new_x = this->hitbox.getPosition().x - 0.03f;
	float new_y = this->hitbox.getPosition().y;
	SetPosition(new_x, new_y);
}

SlowShip* SlowShip::Clone() const // Не забыть delete!
{
	return new SlowShip(*this);
}

void SlowShip::CreateHitbox()
{
	hitbox.setPointCount(4);
	hitbox.setPoint(0, sf::Vector2f(0.f, 0.f));
	hitbox.setPoint(1, sf::Vector2f(50.f, 0.f));
	hitbox.setPoint(2, sf::Vector2f(50.f, 50.f));
	hitbox.setPoint(3, sf::Vector2f(0.f, 50.f));
	hitbox.setFillColor(sf::Color::Red);
}