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
	RenderComponent* render_component;

	bool IsOutSide();
	int DealDamage();
	float Width();
	float Height();
	float X();
	float Y();

	sf::RectangleShape hitbox;
	bool distruction;
protected:
	void Move();
	void CreateHitbox();

	const Spaceship* main_ship;
	float width;
	float height;
	int damage;

	sf::Vector2f velocity;
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