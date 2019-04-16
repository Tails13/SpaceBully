#include "RenderWin.h"

RenderWin::RenderWin() 
{
	window.create(sf::VideoMode(1000, 600), "Space Bully");
}

void RenderWin::Render()
{
	window.clear();
	while (!sprite_list.empty()) 
	{
		window.draw(*sprite_list.front());
		sprite_list.pop_front(); 
	} 
	while (!shape_list.empty())
	{
		window.draw(*shape_list.front());
		shape_list.pop_front();
	}
	window.display();
}

void RenderWin::PutSprite(sf::Sprite* sprite)
{
	sprite_list.push_back(sprite);
}

void RenderWin::PutShape(sf::Shape* shape)
{
	shape_list.push_back(shape);
}

bool RenderWin::SpriteListIsEmpty()
{
	return sprite_list.empty();
}

bool RenderWin::ShapeListIsEmpty()
{
	return shape_list.empty();
}