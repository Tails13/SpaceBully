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

	sf::ConvexShape hitbox;
protected:
	void Move();
	void CreateHitbox();

	const Spaceship* main_ship;
	float speed;
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