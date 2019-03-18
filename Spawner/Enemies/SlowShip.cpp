#include "EnemyShip.h"

SlowShip::SlowShip()
{
	CreateHitbox();
	swing_y = 0.f;
	direction_y = Down;
	up_moving = true;
	this->speed_x = 3.f;
	this->speed_y = 1.f;
	this->width = 50.f;
	this->height = 50.f;
}

SlowShip::SlowShip(const SlowShip& other)
{
	this->width = other.width;
	this->height = other.height;
	this->CreateHitbox();
	this->swing_y = other.swing_y;
	this->direction_y = Down;
	this->up_moving = true;
	this->speed_x = other.speed_x;
	this->speed_y = other.speed_y;
}

void SlowShip::SetPosition(float x, float y)
{
	hitbox.setPosition(sf::Vector2f(x, y));
}

void SlowShip::Move()
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

void SlowShip::ChangeDirect()
{
	if (direction_y == Up)
	{
		direction_y = Forward;
		up_moving = true;
	}
	else if (direction_y == Down)
	{
		direction_y = Forward;
		up_moving = false;
	}
	else if (direction_y == Forward)
	{
		if (up_moving) direction_y = Down;
		else direction_y = Up;
	}
}

SlowShip* SlowShip::Clone() const // Не забыть delete!
{
	return new SlowShip(*this);
}

void SlowShip::CreateHitbox()
{
	hitbox.setPointCount(4);
	hitbox.setPoint(0, sf::Vector2f(0.f, 0.f));
	hitbox.setPoint(1, sf::Vector2f(width, 0.f));
	hitbox.setPoint(2, sf::Vector2f(width, height));
	hitbox.setPoint(3, sf::Vector2f(0.f, height));
	hitbox.setFillColor(sf::Color::Red);
}