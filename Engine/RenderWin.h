#pragma once
#include "Header.h"
#include "Graphics/AnimationManager.h"

class RenderWin
{
public:
	RenderWin(); 
	void Render(float);   // ������ � ���� ��� �������� �� sprite_list
	void RenderText(sf::Text* text); // � ���-�� �����

	void PutShape(sf::Shape* shape);
	void RecordRenderData(RenderData);

	bool ShapeListIsEmpty();
	bool RenderListIsEmpty();
	void ShapeListClear();
	void RenderListClear();

	
	sf::RenderWindow window;
private:

	std::list<sf::Shape*> shape_list;
	std::list<sf::Text*> text_list;
	std::list<RenderData> render_list;
};