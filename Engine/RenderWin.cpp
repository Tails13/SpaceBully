#include "RenderWin.h"

RenderWin::RenderWin() 
{
	window.create(sf::VideoMode(1000, 600), "Space Bully");
	window.setVerticalSyncEnabled(true);
}

void RenderWin::Render(float interpolation)
{
	window.clear();

	// ÷икл перебирает все элементы рендер_листа и отрисовывает 
	// спрайты в позиции, расчитанной с учетом интерпол€ции.
	while (!render_list.empty()) 
	{
		RenderData temp = render_list.front();

		sf::Vector2f render_position;
		render_position.x = temp.position.x + (temp.velocity.x * interpolation);
		render_position.y = temp.position.y + (temp.velocity.y * interpolation);

		temp.sprite_for_drawing->setPosition(render_position);

		window.draw(*temp.sprite_for_drawing);
		render_list.pop_front();
	} 

	while (!shape_list.empty())
	{
		window.draw(*shape_list.front());

		shape_list.pop_front();
	}

	window.display();
}

void RenderWin::RecordRenderData(RenderData render_data)
{
	render_list.push_back(render_data);
}

void RenderWin::PutShape(sf::Shape* shape)
{
	shape_list.push_back(shape);
}

bool RenderWin::RenderListIsEmpty()
{
	return render_list.empty();
}

bool RenderWin::ShapeListIsEmpty()
{
	return shape_list.empty();
}

void RenderWin::RenderListClear()
{
	render_list.clear();
}

void RenderWin::ShapeListClear()
{
	shape_list.clear();
}