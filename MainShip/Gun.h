#pragma once
#include "Spaceship.h" 
class Spaceship;

class Gun
{
public:
	~Gun();
	virtual Gun* Clone() = 0;
	void Update();
	sf::Shape* GetHitbox();
	bool IsOutSide();
	int DealDamage();
	float Width();
	float Height();
	float X();
	float Y();

	//sf::ConvexShape hitbox;
	sf::RectangleShape hitbox;
	bool distruction;
protected:
	void Move();
	void CreateHitbox();

	const Spaceship* main_ship;
	float speed;
	float width;
	float height;
	int damage;
};


class Gun_Simple : public Gun
{
public:
	Gun_Simple(Spaceship*);
	Gun_Simple(const Gun_Simple&);
	virtual Gun* Clone() override;
};

class Gun_Laser : public Gun
{
public:
	Gun_Laser(Spaceship*);
	Gun_Laser(const Gun_Laser&);
	virtual Gun* Clone() override;
};