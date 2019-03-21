#pragma once
#include "Header.h"

class RenderWin
{
public:
	RenderWin(); 
	void Render();   // ������ � ���� ��� �������� �� sprite_list
	void PutSprite(sf::Shape* sprite);  // ������� � sprite_list ���������� ���������� ������
	bool RenderListIsEmpty();
	sf::RenderWindow window;
private:
	std::list<sf::Shape*> sprite_list;
};