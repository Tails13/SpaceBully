// Состояние Меню

#include "GameState.h"

Menu::Menu()
{
	menu_gui = new RenderComponent("Resources/Graphics/Main_menu.png");
	
	menu_gui->CollectRenderData(sf::Vector2f(0, 0), sf::Vector2f(270, 220));
	menu_gui->sprite.setTextureRect(sf::IntRect(0, 0, 460, 360));

	current_option = MenuOption::NewGame;

	cursor_switch = false;
	switch_cd = 0.f;
}

void Menu::Update(Engine& engine)
{
	if (!cursor_switch)
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) || sf::Keyboard::isKeyPressed(sf::Keyboard::S))
		{
			switch_cd = 0.f;
			if (current_option == MenuOption::NewGame)
			{
				current_option = MenuOption::LeaderBoard;
				cursor_switch = true;
				menu_gui->sprite.setTextureRect(sf::IntRect(0, 360, 460, 360));
				
			}
			else if (current_option == MenuOption::LeaderBoard)
			{
				current_option = MenuOption::Quit;
				cursor_switch = true;
				menu_gui->sprite.setTextureRect(sf::IntRect(0, 720, 460, 360));
			}
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) || sf::Keyboard::isKeyPressed(sf::Keyboard::W))
		{
			switch_cd = 0.f;
			if (current_option == MenuOption::Quit)
			{
				current_option = MenuOption::LeaderBoard;
				cursor_switch = true;
				menu_gui->sprite.setTextureRect(sf::IntRect(0, 360, 460, 360));
			}
			else if (current_option == MenuOption::LeaderBoard)
			{
				current_option = MenuOption::NewGame;
				cursor_switch = true;
				menu_gui->sprite.setTextureRect(sf::IntRect(0, 0, 460, 360));
			}
		}
	}

	// !!!!! Здесь добавить вход в таблицу лидеров
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
	{
		if (current_option == MenuOption::NewGame)
		{
			engine.StateSwitch(1);
		}
		else if (current_option == MenuOption::Quit)
		{
			exit(0);
		}
		else if (current_option == MenuOption::LeaderBoard)
		{
			engine.StateSwitch(2);
		}
	}

	// Задержка между переходами к следующему пункту меню
	switch_cd += 0.05f;
	if (switch_cd >= 1.f)
	{
		cursor_switch = false;
		switch_cd = 0.f;
	}

	Render(engine);
}

void Menu::Render(Engine& engine)
{
	engine.rw.RecordRenderData(menu_gui->GetRenderData());
}

Menu::~Menu()
{
	delete menu_gui;
}