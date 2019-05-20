#include "Gun.h"

Gun::~Gun()
{
	//std::cout << "destructor Bullet\n";
	delete render_component;
}

void Gun::Update()
{
	this->Move();
	render_component->CollectRenderData(velocity, hitbox.getPosition());
}

sf::Shape* Gun::GetHitbox()
{
	return &hitbox;
}

void Gun::Move()
{
	this->hitbox.move(sf::Vector2f(velocity.x, velocity.y));
}

// Проверка, находится ли пуля в пределах экрана
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

// Следующие функции используются для расчета коллизий
//==================
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
//==================


void Gun::CreateHitbox()
{
	hitbox.setSize(sf::Vector2f(width, height));
	this->hitbox.setFillColor(sf::Color::Yellow);

	float x = main_ship->hitbox.getPosition().x + 65.f;
	float y = main_ship->hitbox.getPosition().y + 20.f;

	hitbox.setPosition(sf::Vector2f(this->X() + x, this->Y() + y));
}
