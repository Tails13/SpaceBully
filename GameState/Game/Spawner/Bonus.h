#pragma once
#include "../MainShip/Spaceship.h"

class Bonus
{
public:
	~Bonus();
	//Bonus(const Bonus&);
	void Update();
	bool IsInBounds();
	float Width();
	float Height();
	float X();
	float Y();

	static Bonus* Create(float x, float y);

	RenderComponent* render_component;
	sf::RectangleShape hitbox;
	bool distruction;
	
private:
	Bonus();
	//Bonus* Clone() const;);
	void CreateHitbox();

	float width;
	float height;
	sf::Vector2f velocity;
};

