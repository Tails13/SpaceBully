#include "Background.h"

Background::Background()
{
	//sf::Texture texture;
	texture.loadFromFile("Graphics/StarrySky.png");
	sprite.setTexture(texture);
	MakeLoop();
}

sf::Sprite* Background::GetSprite()
{
	return &sprite;
}

void Background::Update()
{
	sprite.move(sf::Vector2f(-5.f, 0.f));
	if (sprite.getPosition().x <= -1000)
		MakeLoop();
}

void Background::MakeLoop()
{
	sprite.setPosition(sf::Vector2f(0.f, 0.f));
}