#pragma once
#include "RenderWin.h"

class EnemyShip
{
public: 
	sf::ConvexShape hitbox;
	~EnemyShip();
	virtual EnemyShip* Clone() const = 0;
	virtual void SetPosition(float x, float y) = 0;
	virtual void Move() = 0;
	bool IsInBounds();
private:
	virtual void CreateHitbox() = 0;
};
