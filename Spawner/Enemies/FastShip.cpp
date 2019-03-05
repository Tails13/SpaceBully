#include "EnemyShip.h"

FastShip::FastShip()
{
	CreateHitbox();
	swing_y = 0.f;
	direction_y = Down;
	up_moving = true;
}

FastShip::FastShip(const FastShip& other)
{
	CreateHitbox();
	this->swing_y = other.swing_y;
	this->direction_y = Down;
	this->up_moving = true;
}

void FastShip::SetPosition(float x, float y)
{
	hitbox.setPosition(sf::Vector2f(x, y));
}

void FastShip::Move()
{
	float new_x = this->hitbox.getPosition().x - 0.06f;
	float new_y = this->hitbox.getPosition().y;

	if (this->IsBehind())
	{
		swing_y += 0.01f;
		if (swing_y >= 50.f)
		{
			ChangeDirect();
			swing_y = 0.f;
		}

		if (direction_y == Up)
		{
			new_y = this->hitbox.getPosition().y - 0.01f;
		}
		else if (direction_y == Down)
		{
			new_y = this->hitbox.getPosition().y + 0.01f;
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