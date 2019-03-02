#pragma once
#include "Enemies/EnemyShip.h"

class EnemySpawner
{
public:
	EnemySpawner();
	void Spawn(std::list<EnemyShip*>&);
	bool HasAPrototype();
	void SetPrototype(EnemyShip*);

	bool bCreate;
private:
	EnemyShip* MakeShip() const;

	EnemyShip* _prototype_ship;
	float fCurrentTime;
	float fStepTime;
	int nObjectCount;
	int nObjectOrdered;
};

