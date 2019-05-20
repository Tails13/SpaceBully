#include "RenderComponent.h"

RenderComponent::RenderComponent(std::string texture_path)
{
	texture.loadFromFile(texture_path);
	sprite.setTexture(texture);
}

void RenderComponent::CollectRenderData(sf::Vector2f velocity, sf::Vector2f position)
{
	render_data.position = position;
	render_data.velocity = velocity;
	render_data.sprite_for_drawing = &sprite;
}

RenderData RenderComponent::GetRenderData()
{
	return render_data;
}