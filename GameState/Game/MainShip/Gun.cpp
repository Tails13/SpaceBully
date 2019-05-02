#include "Gun.h"

Gun::~Gun()
{
	//std::cout << "destructor Bullet\n";
}

void Gun::Update()
{
	this->Move();
	this->CollectRenderData();
}

sf::Shape* Gun::GetHitbox()
{
	return &hitbox;
}

void Gun::Move()
{
	this->hitbox.move(sf::Vector2f(velocity.x, velocity.y));
}

bool Gun::IsOutSide()
{
	if (this->hitbox.getPosition().x > 1000.f)
		return true;
	else
		return false;
}

int Gun::DealDamage()
{
	return this->damage;
}

float Gun::Width()
{
	return this->width;
}

float Gun::Height()
{
	return this->height;
}

float Gun::X()
{
	return this->hitbox.getPosition().x;
}

float Gun::Y()
{
	return this->hitbox.getPosition().y;
}

void Gun::CreateHitbox()
{
	hitbox.setSize(sf::Vector2f(width, height));
	this->hitbox.setFillColor(sf::Color::Yellow);

	float x = main_ship->hitbox.getPosition().x + 65.f;
	float y = main_ship->hitbox.getPosition().y + 20.f;

	hitbox.setPosition(sf::Vector2f(this->X() + x, this->Y() + y));
}

void Gun::CollectRenderData()
{
	render_data.position = hitbox.getPosition();
	render_data.velocity = velocity;
	render_data.sprite_for_drawing = &sprite;
}