#pragma once
#include "RenderData.h"

class RenderComponent
{
public:
	RenderComponent(std::string texture_path);
	void CollectRenderData(sf::Vector2f velocity, sf::Vector2f position);
	RenderData GetRenderData(); 
	sf::Sprite sprite;

private:
	sf::Texture texture;
	
	RenderData render_data;
};
