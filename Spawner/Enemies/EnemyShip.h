#pragma once
#include "..\..\RenderWin.h"

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


class CircleShip : public EnemyShip
{
public:
	CircleShip();
	CircleShip(const CircleShip&);
	void SetPosition(float x, float y) override;
	void Move() override;
	CircleShip* Clone() const override;
private:
	void CreateHitbox() override;
};