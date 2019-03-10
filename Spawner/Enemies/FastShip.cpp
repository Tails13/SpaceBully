#include "EnemyShip.h"

FastShip::FastShip()
{
	CreateHitbox();
	swing_y = 0.f;
	direction_y = Down;
	up_moving = true;
	this->speed_x = 6.f;
	this->speed_y = 1.f;
}

FastShip::FastShip(const FastShip& other)
{
	CreateHitbox();
	this->swing_y = other.swing_y;
	this->direction_y = Down;
	this->up_moving = true;
	this->speed_x = other.speed_x;
	this->speed_y = other.speed_y;
}

void FastShip::SetPosition(float x, float y)
{
	hitbox.setPosition(sf::Vector2f(x, y));
}

void FastShip::Move()
{
	float new_x = this->hitbox.getPosition().x - speed_x;
	float new_y = this->hitbox.getPosition().y;

	if (this->IsShow())
	{
		swing_y += speed_y;
		if (swing_y >= 50.f)
		{
			ChangeDirect();
			swing_y = 0.f;
		}

		if (direction_y == Up)
		{
			new_y = this->hitbox.getPosition().y - speed_y;
		}
		else if (direction_y == Down)
		{
			new_y = this->hitbox.getPosition().y + speed_y;
		}
	}

	SetPosition(new_x, new_y);
}

void FastShip::ChangeDirect()
{
	if (direction_y == Up)
	{
		direction_y = Down;
	}
	else if (direction_y == Down)
	{
		direction_y = Up;
	}
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