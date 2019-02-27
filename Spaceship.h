#pragma once
#include "RenderWin.h"

class Spaceship
{
public:
	Spaceship(); 
	sf::ConvexShape hitbox;
	void Draw(RenderWin* rw);
private:
	void CreateHitbox();
};