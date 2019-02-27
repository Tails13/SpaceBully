#pragma once
#include "EnemyShip.h"

class SlowShip : public EnemyShip
{
public:
	SlowShip();
	SlowShip(const SlowShip&);
	void SetPosition(float x, float y) override;
	void Move() override;
	SlowShip* Clone() const override;
private:
	void CreateHitbox() override;
};