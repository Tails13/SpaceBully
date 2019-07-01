#include "GUI.h"

GUI::GUI()
{
	layer1 = new RenderComponent("Resources/Graphics/GUI_Layer_1.png");
	layer2 = new RenderComponent("Resources/Graphics/GUI_Layer_2.png");
	layer3 = new RenderComponent("Resources/Graphics/GUI_Layer_3.png");

	layer1->CollectRenderData(sf::Vector2f(0.f, 0.f), sf::Vector2f(15.f, 560.f));
	layer3->CollectRenderData(sf::Vector2f(0.f, 0.f), sf::Vector2f(15.f, 560.f));

	layer2->CollectRenderData(sf::Vector2f(0.f, 0.f), sf::Vector2f(-170.f, 565.f));

	//Настройки шрифта
	font.loadFromFile("Resources/Fonts/Delogy.ttf");
	txt_score.setFont(font);
	txt_score.setCharacterSize(20);
	txt_score.setFillColor(sf::Color::Color(189, 113, 225, 255));
	txt_score.setString("score  ");
	txt_score.setPosition(sf::Vector2f(755.f, 565.f));
}

void GUI::Update(int bonus)
{
	if (bonus > 0)
	{
		float temp_x = 22 + (bonus * 170) + (bonus * 8) - 170;
		layer2->CollectRenderData(sf::Vector2f(0.f, 0.f), sf::Vector2f(temp_x, 567.f));
	}
	else
		layer2->CollectRenderData(sf::Vector2f(0.f, 0.f), sf::Vector2f(-170.f, 565.f));
}

void GUI::RecordScore(int score)
{
	std::ostringstream ost_score;
	ost_score << score;
	txt_score.setString("score: " + ost_score.str());
}