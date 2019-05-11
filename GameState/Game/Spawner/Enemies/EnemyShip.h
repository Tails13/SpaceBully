#pragma once
#include "../Bonus.h"

class EnemyShip
{
public: 
	enum Direction
	{ Up, Down, Forward};

	sf::RectangleShape hitbox;
	~EnemyShip();
	virtual EnemyShip* Clone() const = 0;
	virtual void Move() = 0;
	virtual void SetPosition(float x, float y) = 0;
	bool IsInBounds();  // Вышел ли корабль за пределы экрана.
	bool IsShow();	// Появился ли корабль на экране.
	float Width();
	float Height();
	float X();
	float Y();
	RenderData GetRenderData();

	void TakeDamage(int);
	bool IsDead();
protected:
	float width;
	float height;
	int hp;
	bool dead;

	sf::Vector2f velocity;
	RenderData render_data;
private:
	virtual void CreateHitbox() = 0;
};


class FastShip : public EnemyShip
{
public:
	FastShip();
	FastShip(const FastShip&);
	void Move();
	void SetPosition(float x, float y);
	FastShip* Clone() const override;
private:
	void CreateHitbox() override;
	void ChangeDirect();

	float swing_y;		// Колебания движения вверх-вниз
	Direction direction_y;
	bool up_moving;

	sf::Texture texture;
	sf::Sprite sprite;
	void CollectRenderData();
	AnimationManager animator_manager;
};


class SlowShip : public EnemyShip
{
public:
	SlowShip();
	SlowShip(const SlowShip&);
	void Move();
	void SetPosition(float x, float y);
	SlowShip* Clone() const override;
private:
	void CreateHitbox() override;
	void ChangeDirect();

	float swing_y;
	Direction direction_y;
	bool up_moving;

	sf::Texture texture;
	sf::Sprite sprite;
	void CollectRenderData();
	AnimationManager animator_manager;
};


class CircleShip : public EnemyShip
{
public:
	CircleShip();
	CircleShip(const CircleShip&);
	void Move();
	void SetPosition(float x, float y);
	CircleShip* Clone() const override;

private:
	void CreateHitbox() override;

	sf::Texture texture;
	sf::Sprite sprite;
	void CollectRenderData();
	AnimationManager animator_manager;
};