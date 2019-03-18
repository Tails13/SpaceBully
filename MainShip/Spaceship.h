#pragma once
#include "../Engine/RenderWin.h"
#include "Gun.h"

class Gun;

class Spaceship
{
public:
	enum GunType{Simple, Laser};

	Spaceship(); 
	sf::ConvexShape hitbox;
	void Draw(RenderWin* rw);
	void Update();
	void SpeedUp(float);

	void Equip(GunType);
	GunType GetGunType();
	bool HasDoubleGun();
	void Shoot(std::list<Gun*>&);
	void DoubleShoot(std::list<Gun*>&);

private:
	enum Direction { Up, Down, Forward, Back };

	void Control();
	void Move(Direction);
	void CreateHitbox();
	void Cooldown();

	float speed;
	Gun* bullet;
	GunType gun_type;
	bool double_shot;
	bool shoot_cooldown;
	float sc_count;
};


