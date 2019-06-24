#pragma once
#include "../../Engine/RenderWin.h"

class GUI
{
public:
	GUI();
	void Update(int bonus);

	RenderComponent* layer1;
	RenderComponent* layer2;
	RenderComponent* layer3;
	RenderComponent* score;

private:

};