#pragma once

#include <SFML/Graphics.hpp>

class Background
{
public:
	Background();

	void Update();
	sf::Sprite* GetSprite();
private:
	void MakeLoop();

	sf::Texture texture;
	sf::Sprite sprite;
};