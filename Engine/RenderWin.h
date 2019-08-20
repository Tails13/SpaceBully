#pragma once
#include "Header.h"
#include "Graphics/AnimationManager.h"

class RenderWin
{
public:
	RenderWin(); 
	void Render(float);   // –исует в окне все элементы из sprite_list
	void RenderText(sf::Text* text); // и кол-во очков

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