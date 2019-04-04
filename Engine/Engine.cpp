#include "Engine.h"

Engine::Engine()
{
	this->game = new Game;
	state = game;
}

void Engine::Update()
{
	sf::Event event;
	while (rw.window.pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
			rw.window.close();
	}

	state->Update(*this);
}

void Engine::Render()
{
	if (!rw.RenderListIsEmpty())
		rw.Render();
}

Engine::~Engine()
{
	
}