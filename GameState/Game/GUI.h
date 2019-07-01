#pragma once
#include "../../Engine/RenderWin.h"
#include <sstream>

class GUI
{
public:
	GUI();
	void Update(int bonus);

	void RecordScore(int score);

	RenderComponent* layer1;
	RenderComponent* layer2;
	RenderComponent* layer3;

	sf::Font font;
	sf::Text txt_score;
private:

};