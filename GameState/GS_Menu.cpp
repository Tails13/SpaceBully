// Состояние Меню

#include "GameState.h"

// Создает кнопки и курсор

Menu::Menu()
{
	cursor.setSize(sf::Vector2f(250.f, 80.f));
	cursor.setPosition(sf::Vector2f(375.f, 160.f));
	cursor.setFillColor(sf::Color::Blue);

	sf::RectangleShape temp(sf::Vector2f(200.f, 50.f));
	temp.setFillColor(sf::Color::Yellow);

	option_1 = temp;
	option_1.setPosition(sf::Vector2f(400.f, 175.f));

	option_2 = temp;
	option_2.setPosition(sf::Vector2f(400.f, 275.f));

	option_3 = temp;
	option_3.setPosition(sf::Vector2f(400.f, 375.f));

	current_option = MenuOption::NewGame;
	cursor_new_position = 0.f;
	cursor_switch = false;
}

void Menu::Update(Engine& engine)
{
	if (!cursor_switch)
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) || sf::Keyboard::isKeyPressed(sf::Keyboard::S))
		{
			
			if (current_option == MenuOption::NewGame)
			{
				cursor_new_position = 260.f;
				current_option = MenuOption::LeaderBoard;
				cursor_switch = true;
			}
			else if (current_option == MenuOption::LeaderBoard)
			{
				cursor_new_position = 360.f;
				current_option = MenuOption::Quit;
				cursor_switch = true;
			}
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) || sf::Keyboard::isKeyPressed(sf::Keyboard::W))
		{
			if (current_option == MenuOption::Quit)
			{
				cursor_new_position = 260.f;
				current_option = MenuOption::LeaderBoard;
				cursor_switch = true;
			}
			else if (current_option == MenuOption::LeaderBoard)
			{
				cursor_new_position = 160.f;
				current_option = MenuOption::NewGame;
				cursor_switch = true;
			}
		}
	}

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
	}

	if (cursor_new_position != 0.f)
		CursorMove();

	Render(engine);
}

void Menu::CursorMove()
{
	if (cursor_new_position > cursor.getPosition().y)  cursor.move(sf::Vector2f(0.f, 20));
	else if (cursor_new_position < cursor.getPosition().y)  cursor.move(sf::Vector2f(0.f, -20));
	else if (cursor_new_position == cursor.getPosition().y)
	{
		cursor_new_position = 0.f;
		cursor_switch = false;
	}
}

void Menu::Render(Engine& engine)
{
	engine.rw.PutShape(&cursor);
	engine.rw.PutShape(&option_1);
	engine.rw.PutShape(&option_2);
	engine.rw.PutShape(&option_3);
}
