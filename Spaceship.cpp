#include "Spaceship.h"

Spaceship::Spaceship() 
{
	CreateHitbox();
}

void Spaceship::CreateHitbox()
{
	hitbox.setPointCount(3);
	hitbox.setPoint(0, sf::Vector2f(0.f, 0.f));
	hitbox.setPoint(1, sf::Vector2f(150.f, 50.f));
	hitbox.setPoint(2, sf::Vector2f(0.f, 100.f));
	hitbox.setFillColor(sf::Color::Blue);
}

void Spaceship::Draw(RenderWin* rm)
{
	rm->PutSprite(&hitbox);
}