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
	this->hitbox.setPointCount(4);
	this->hitbox.setPoint(0, sf::Vector2f(0.f, 0.f));
	this->hitbox.setPoint(1, sf::Vector2f(width, 0.f));
	this->hitbox.setPoint(2, sf::Vector2f(width, height));
	this->hitbox.setPoint(3, sf::Vector2f(0.f, height));
	this->hitbox.setFillColor(sf::Color::Yellow);

	float x = main_ship->hitbox.getPosition().x + 65.f;
	float y = main_ship->hitbox.getPosition().y + 20.f;

	hitbox.setPosition(sf::Vector2f(this->X() + x, this->Y() + y));
}