#include "Engine.h"

Engine::Engine()
{
	this->game = new Game;
	this->menu = new Menu;
	state = menu;
	AudioSystem::Instance().PlayMusic("Main_theme.ogg"); //******
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

// ����� ���������� ���� (����, ���� � ��)
// ���������� �������� ����������� �������� � ���� �� enum. @@@
void Engine::StateSwitch(int i)
{
	if (i == 0)
	{
		state = menu;
		AudioSystem::Instance().StopMusic();
		AudioSystem::Instance().PlayMusic("Main_theme.ogg"); //******
	}
	else if (i == 1)
	{
		state = game;
		AudioSystem::Instance().StopMusic();
		AudioSystem::Instance().PlayMusic("Game_theme.ogg"); //**********
	}
}

void Engine::Render(float interpolation)
{
	if (!rw.RenderListIsEmpty() || !rw.ShapeListIsEmpty())
		rw.Render(interpolation);
}

Engine::~Engine()
{
	
}