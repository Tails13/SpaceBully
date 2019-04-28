#pragma once
#include "Header.h"
#include "Graphics/RenderData.h"

class RenderWin
{
public:
	RenderWin(); 
	void Render(float);   // Рисует в окне все элементы из sprite_list

	void PutShape(sf::Shape* shape);
	void RecordRenderData(RenderData);

	bool ShapeListIsEmpty();
	bool RenderListIsEmpty();

	sf::RenderWindow window;
private:

	std::list<sf::Shape*> shape_list;
	std::list<RenderData> render_list;
};