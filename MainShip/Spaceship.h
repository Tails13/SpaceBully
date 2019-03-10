#pragma once
#include "../Engine/RenderWin.h"

class Spaceship
{
public:
	

	Spaceship(); 
	sf::ConvexShape hitbox;
	void Draw(RenderWin* rw);
	void Control();
	void SpeedUp(float);
private:
	enum Direction { Up, Down, Forward, Back };
	void Move(Direction);

	void CreateHitbox();
	float speed;
};