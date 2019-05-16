#include "EnemyShip.h"

CircleShip::CircleShip()
{
	this->velocity.x = 5.f;

	this->width = 50.f;
	this->height = 50.f;
	this->hp = 30;
	this->dead = false;
}

CircleShip::CircleShip(const CircleShip& other)
{
	texture.loadFromFile("Graphics/Enemy_Circle_test.png");
	sprite.setTexture(texture);

	this->width = other.width;
	this->height = other.height;
	this->CreateHitbox();
	this->velocity = other.velocity;
	this->hp = other.hp;
	this->dead = other.dead;
	this->render_data = other.render_data; // Изменение в ближайших патчах!

	animator_manager.SetAM(&sprite, width, height);
	animator_manager.SetNumberAnimation(0);
	animator_manager.SetNumberFrame(0);
	animator_manager.SetLastFrame(4);
}

void CircleShip::SetPosition(float x, float y)
{
	hitbox.setPosition(sf::Vector2f(x, y));
}

void CircleShip::Move()
{
	float new_x = this->hitbox.getPosition().x - velocity.x;
	float new_y = this->hitbox.getPosition().y;
	SetPosition(new_x, new_y);
	CollectRenderData();	// Изменение в ближайших патчах!
	animator_manager.PlayAnimation();
}

CircleShip* CircleShip::Clone() const // Не забыть delete!
{
	return new CircleShip(*this);
}

void CircleShip::CreateHitbox()
{
	hitbox.setSize(sf::Vector2f(width, height));
	hitbox.setFillColor(sf::Color::Blue);
}

// ДУБЛИКАТ КОДА!
void CircleShip::CollectRenderData()
{
	render_data.position = hitbox.getPosition();
	render_data.velocity = velocity;
	render_data.sprite_for_drawing = &sprite;
}

