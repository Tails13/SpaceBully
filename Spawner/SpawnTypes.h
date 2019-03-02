#pragma once
#include "..\Header.h"

struct Point
{
	int x = 0;
	int y = 0;
};

class SpawnType
{
public:
	virtual float SetDelay() = 0;	// Задержка между спавном пачек
	virtual void SetSpawnPositions() = 0;  // Возвращает массив с координатами для спавна
	Point ship_positions[10];
};

class SpawnSlow : public SpawnType
{
	float SetDelay() override;
	void SetSpawnPositions() override;
};

class SpawnFast : public SpawnType
{
	float SetDelay() override;
	void SetSpawnPositions() override;
};

class SpawnCircle : public SpawnType
{
	virtual float SetDelay() override;
	virtual void SetSpawnPositions() override;
};