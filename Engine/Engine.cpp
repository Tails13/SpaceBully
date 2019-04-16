#include "Engine.h"

Engine::Engine()
{
	this->game = new Game;
	this->menu = new Menu;
	state = menu;
}

void Engine::Update()
{
	sf::Event event;
	while (rw.window.pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
			rw.window.close();
	}

	rw.PutSprite(background.GetSprite());
	background.Update();

	state->Update(*this);
}

void Engine::StateSwitch(int i)
{
	if (i == 0) state = menu;
	else if (i == 1) state = game;
}

void Engine::Render()
{
	if (!rw.SpriteListIsEmpty() || !rw.ShapeListIsEmpty())
		rw.Render();
}

Engine::~Engine()
{
	
}