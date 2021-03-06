#include "EnemyShip.h"

SlowShip::SlowShip()
{
	swing_y = 0.f;
	direction_y = Down;
	up_moving = true;
	this->velocity.x = 3.f;
	this->velocity.y = 1.f;
	this->width = 50.f;
	this->height = 50.f;
	this->hp = 50;
	this->dead = false;
}

SlowShip::SlowShip(const SlowShip& other)
{
	render_component = new RenderComponent("Resources/Graphics/Enemy_Slow.png");

	this->width = other.width;
	this->height = other.height;
	this->CreateHitbox();
	this->swing_y = other.swing_y;
	this->direction_y = Down;
	this->up_moving = true;
	this->velocity = other.velocity;
	this->hp = other.hp;
	this->dead = other.dead;

	render_component->CollectRenderData(velocity, hitbox.getPosition());

	animator_manager.SetAM(render_component->GetRenderData().sprite_for_drawing, width, height);
	animator_manager.SetNumberAnimation(0);
	animator_manager.ShowFrame(1);
}

void SlowShip::SetPosition(float x, float y)
{
	hitbox.setPosition(sf::Vector2f(x, y));
}

void SlowShip::Move()
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
}

// ��������� ������������� �����������
void SlowShip::ChangeDirect()
{
	if (direction_y == Up)
	{
		direction_y = Forward;
		animator_manager.ShowFrame(1);
		up_moving = true;
	}
	else if (direction_y == Down)
	{
		direction_y = Forward;
		animator_manager.ShowFrame(1);
		up_moving = false;
	}
	else if (direction_y == Forward)
	{
		if (up_moving)
		{
			direction_y = Down;
			animator_manager.ShowFrame(2);
		}
		else
		{
			direction_y = Up;
			animator_manager.ShowFrame(0);
		}
	}
}

SlowShip* SlowShip::Clone() const 
{
	return new SlowShip(*this);
}

void SlowShip::CreateHitbox()
{
	hitbox.setSize(sf::Vector2f(width, height));
	hitbox.setFillColor(sf::Color::Red);
}
