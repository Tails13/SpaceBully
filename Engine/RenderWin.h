#pragma once
#include "Header.h"

class RenderWin
{
public:
	RenderWin(); 
	void Render();   // ������ � ���� ��� �������� �� sprite_list
	void PutSprite(sf::Sprite* sprite);  // ������� � sprite_list ���������� ���������� ������
	void PutShape(sf::Shape* shape);

	bool SpriteListIsEmpty();
	bool ShapeListIsEmpty();
	sf::RenderWindow window;
private:
	std::list<sf::Shape*> shape_list;
	std::list<sf::Sprite*> sprite_list;
};