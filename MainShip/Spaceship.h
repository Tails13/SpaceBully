#pragma once
#include "../Engine/RenderWin.h"
#include "Gun.h"

class Gun;

class Spaceship
{
public:
	enum Guns{Simple, Double, Laser, DoubleLaser};

	Spaceship(); 
	sf::ConvexShape hitbox;
	void Draw(RenderWin* rw);
	void Control();
	void SpeedUp(float);

	void Equip(Guns);
	Gun* Shoot();
private:
	enum Direction { Up, Down, Forward, Back };
	void Move(Direction);
	void CreateHitbox();

	float speed;
	Gun* gun;

};


