#include "GUI.h"

GUI::GUI()
{
	layer1 = new RenderComponent("Graphics/GUI_Layer_1.png");
	layer2 = new RenderComponent("Graphics/GUI_Layer_2.png");
	layer3 = new RenderComponent("Graphics/GUI_Layer_3.png");
	score = new RenderComponent("Graphics/Score.png");

	layer1->CollectRenderData(sf::Vector2f(0.f, 0.f), sf::Vector2f(35.f, 560.f));
	layer3->CollectRenderData(sf::Vector2f(0.f, 0.f), sf::Vector2f(35.f, 560.f));

	layer2->CollectRenderData(sf::Vector2f(0.f, 0.f), sf::Vector2f(-170.f, 565.f));

	score->CollectRenderData(sf::Vector2f(0.f, 0.f), sf::Vector2f(780.f, 565.f));
}

void GUI::Update(int bonus)
{
	if (bonus > 0)
	{
		float temp_x = 42 + (bonus * 170) + (bonus * 8) - 170;
		layer2->CollectRenderData(sf::Vector2f(0.f, 0.f), sf::Vector2f(temp_x, 567.f));
	}
	else
		layer2->CollectRenderData(sf::Vector2f(0.f, 0.f), sf::Vector2f(-170.f, 565.f));
}