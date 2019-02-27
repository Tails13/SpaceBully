#pragma once
#include "Header.h"

class RenderWin
{
public:
	RenderWin(); 
	void Render(); // Рисует в окне все элементы из sprite_list
	void PutSprite(sf::Shape* sprite);  // Пушапит в sprite_list переданный параметром объект
	sf::RenderWindow window;
private:
	std::list<sf::Shape*> sprite_list;
};