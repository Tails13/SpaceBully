#include "EnemyShip.h"

FastShip::FastShip()
{
	swing_y = 0.f;
	direction_y = Down;
	up_moving = true;
	this->velocity.x = 6.f;
	this->velocity.y = 1.f;
	this->width = 50.f;
	this->height = 30.f;
	this->hp = 40;
	this->dead = false;
}

FastShip::FastShip(const FastShip& other)
{
	render_component = new RenderComponent("Graphics/Enemy_Fast.png");

	this->width = other.width;
	this->height = other.height;
	CreateHitbox();
	this->swing_y = other.swing_y;
	this->direction_y = Down;
	this->up_moving = true;
	this->velocity = other.velocity;
	this->hp = other.hp;
	this->dead = other.dead;

	render_component->CollectRenderData(velocity, hitbox.getPosition());

	animator_manager.SetAM(render_component->GetRenderData().sprite_for_drawing, width, height);
	animator_manager.SetNumberAnimation(0);
	animator_manager.SetNumberFrame(0);
	animator_manager.SetLastFrame(4);
}

void FastShip::SetPosition(float x, float y)
{
	hitbox.setPosition(sf::Vector2f(x, y));
}

void FastShip::Move()
{
	float new_x = this->hitbox.getPosition().x - velocity.x;
	float new_y = this->hitbox.getPosition().y;

	if (this->IsShow())
	{
		swing_y += velocity.y;
		if (swing_y >= 50.f)
		{
			ChangeDirect();
			swing_y = 0.f;
		}

		if (direction_y == Up)
		{
			new_y = this->hitbox.getPosition().y - velocity.y;
		}
		else if (direction_y == Down)
		{
			new_y = this->hitbox.getPosition().y + velocity.y;
		}
	}

	SetPosition(new_x, new_y);
	render_component->CollectRenderData(velocity, hitbox.getPosition());
	animator_manager.PlayAnimation();
}


// Изменение вертикального направления.
void FastShip::ChangeDirect()
{
	if (direction_y == Up)
	{
		direction_y = Down;
	}
	else if (direction_y == Down)
	{
		direction_y = Up;
	}
}

FastShip* FastShip::Clone() const 
{
	return new FastShip(*this);
}

void FastShip::CreateHitbox()
{
	hitbox.setSize(sf::Vector2f(width, height));
	hitbox.setFillColor(sf::Color::Green);
}
