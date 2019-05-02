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
	virtual RenderData GetRenderData() = 0;

	sf::RectangleShape hitbox;
	bool distruction;
protected:
	void Move();
	void CreateHitbox();
	void CollectRenderData();	

	const Spaceship* main_ship;
	float width;
	float height;
	int damage;

	sf::Texture texture;
	sf::Sprite sprite;
	sf::Vector2f velocity;
	RenderData render_data;
};


class Gun_Simple : public Gun
{
public:
	Gun_Simple(Spaceship*);
	Gun_Simple(const Gun_Simple&);
	virtual Gun* Clone() override;
	RenderData GetRenderData() override;
};

class Gun_Laser : public Gun
{
public:
	Gun_Laser(Spaceship*);
	Gun_Laser(const Gun_Laser&);
	virtual Gun* Clone() override;
	RenderData GetRenderData() override;
};