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

	rw.RenderListClear();
	rw.ShapeListClear();

	background.Update();
	rw.RecordRenderData(background.render_component->GetRenderData());

	state->Update(*this);

	
}

// Смена сосотояний игры (меню, игра и тд)
// Желательно изменить принемаемый аргумент с инта на enum. @@@
void Engine::StateSwitch(int i)
{
	if (i == 0) state = menu;
	else if (i == 1) state = game;
}

void Engine::Render(float interpolation)
{
	if (!rw.RenderListIsEmpty() || !rw.ShapeListIsEmpty())
		rw.Render(interpolation);
}

Engine::~Engine()
{
	
}