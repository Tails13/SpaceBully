#include "Gun.h"

Gun::~Gun()
{
	std::cout << "destructor Bullet\n";
}

void Gun::Update()
{
	this->Move();
}

sf::Shape* Gun::GetHitbox()
{
	return &hitbox;
}

void Gun::Move()
{
	this->hitbox.move(sf::Vector2f(this->speed, 0.f));
}

bool Gun::IsOutSide()
{
	if (this->hitbox.getPosition().x > 1000.f)
		return true;
	else
		return false;
}

float Gun::Width()
{
	return this->width;
}

float Gun::Height()
{
	return this->height;
}

float Gun::X()
{
	return this->hitbox.getPosition().x;
}

float Gun::Y()
{
	return this->hitbox.getPosition().y;
}

void Gun::CreateHitbox()
{
	float x = main_ship->hitbox.getPosition().x + 75.f;
	float y = main_ship->hitbox.getPosition().y + 20.f;

	this->hitbox.setPointCount(4);
	this->hitbox.setPoint(0, sf::Vector2f(x, y));
	this->hitbox.setPoint(1, sf::Vector2f(x + width, y));
	this->hitbox.setPoint(2, sf::Vector2f(x + width, y + height));
	this->hitbox.setPoint(3, sf::Vector2f(x, y + height));
	this->hitbox.setFillColor(sf::Color::Yellow);
}