#include "Background.h"

Background::Background()
{
	texture.loadFromFile("Graphics/StarrySky.png");
	sprite.setTexture(texture);
	velocity.x = -2.5f;
	MakeLoop();
}

void Background::Update()
{
	sprite.move(velocity);
	if (sprite.getPosition().x <= -1000)
		MakeLoop();

	CollectRenderData();
}

void Background::CollectRenderData()
{
	render_data.position = sprite.getPosition();
	render_data.velocity = this->velocity;
	render_data.sprite_for_drawing = &sprite;
}

RenderData Background::GetRenderData()
{
	return render_data;
}

void Background::MakeLoop()
{
	sprite.setPosition(sf::Vector2f(0.f, 0.f));
}