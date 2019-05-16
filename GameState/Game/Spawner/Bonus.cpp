#include "Bonus.h"

Bonus::Bonus()
{
	width = 20;
	height = 20;
	CreateHitbox();
	distruction = false;
}

Bonus::~Bonus()
{
	std::cout << "Bonus destructor!!" << std::endl;
}

Bonus* Bonus::Create(float x, float y)
{
	Bonus* bonus = new Bonus();
	bonus->hitbox.setPosition(sf::Vector2f(x, y));
	return bonus;
}

void Bonus::Update()
{
	hitbox.move(sf::Vector2f(-8.f, 0.f));
}

bool Bonus::IsInBounds()
{
	return !(hitbox.getPosition().x <= -25);
}

// Следующие функции нужны для расчета коллизий
//==================
float Bonus::Width()
{
	return width;
}

float Bonus::Height()
{
	return height;
}

float Bonus::X()
{
	return hitbox.getPosition().x;
}

float Bonus::Y()
{
	return hitbox.getPosition().y;
}
//==================

void Bonus::CreateHitbox()
{
	hitbox.setSize(sf::Vector2f(width, height));
	hitbox.setFillColor(sf::Color::Yellow);
}