#include "RenderWin.h"

RenderWin::RenderWin() 
{
	window.create(sf::VideoMode(800, 600), "Space Bully");
}

void RenderWin::Render()
{
	window.clear();
	while (!sprite_list.empty()) 
	{
		window.draw(*sprite_list.front());
		sprite_list.pop_front(); 
	} 
	window.display();
}

void RenderWin::PutSprite(sf::Shape* sprite)
{
	sprite_list.push_back(sprite);
}