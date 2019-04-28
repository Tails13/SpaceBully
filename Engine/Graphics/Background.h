#pragma once

#include "RenderData.h"

class Background
{
public:
	Background();

	void Update();
	RenderData GetRenderData();
private:
	void MakeLoop();
	void CollectRenderData();

	sf::Texture texture;
	sf::Sprite sprite;
	sf::Vector2f velocity;
	RenderData render_data;
};