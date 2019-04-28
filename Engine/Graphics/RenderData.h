#pragma once

#include <SFML/Graphics.hpp>

struct RenderData
{
	RenderData()
	{
		sprite_for_drawing = nullptr;
	}
	sf::Vector2f velocity;
	sf::Vector2f position;
	sf::Sprite* sprite_for_drawing;
};