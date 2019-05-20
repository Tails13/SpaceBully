#pragma once

#include "RenderComponent.h"

class Background
{
public:
	Background();
	void Update();

	RenderComponent* render_component;
private:
	sf::Vector2f velocity;
};