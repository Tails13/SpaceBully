#pragma once
#include "SlowShip.h"

class FastShip : public EnemyShip
{
public:
	FastShip();
	FastShip(const FastShip&); 
	void SetPosition(float x, float y) override;
	void Move() override;
	FastShip* Clone() const override;
private:
	void CreateHitbox() override;
};

