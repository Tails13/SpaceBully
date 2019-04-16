#pragma once
#include "Header.h"

class RenderWin
{
public:
	RenderWin(); 
	void Render();   // Рисует в окне все элементы из sprite_list
	void PutSprite(sf::Sprite* sprite);  // Пушапит в sprite_list переданный параметром объект
	void PutShape(sf::Shape* shape);

	bool SpriteListIsEmpty();
	bool ShapeListIsEmpty();
	sf::RenderWindow window;
private:
	std::list<sf::Shape*> shape_list;
	std::list<sf::Sprite*> sprite_list;
};