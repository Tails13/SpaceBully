#include "Background.h"

Background::Background()
{
	render_component = new RenderComponent("Graphics/StarrySky.png");
	velocity.x = -2.5f;
	render_component->CollectRenderData(velocity, sf::Vector2f(0.f, 0.f));
}

void Background::Update()
{
	render_component->GetRenderData().sprite_for_drawing->move(velocity);
	
	if (render_component->GetRenderData().sprite_for_drawing->getPosition().x <= -1000)
		render_component->GetRenderData().sprite_for_drawing->setPosition(sf::Vector2f(0.f, 0.f));

	render_component->CollectRenderData(velocity, render_component->GetRenderData().sprite_for_drawing->getPosition());
}
