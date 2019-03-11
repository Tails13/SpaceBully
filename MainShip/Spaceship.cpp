#include "Spaceship.h"

Spaceship::Spaceship() 
{
	CreateHitbox();
	speed = 4.f;
	gun = nullptr;
	Equip(Spaceship::GunType::DoubleLaser);
}

void Spaceship::CreateHitbox()
{
	hitbox.setPointCount(3);
	hitbox.setPoint(0, sf::Vector2f(0.f, 0.f));
	hitbox.setPoint(1, sf::Vector2f(100.f, 25.f));
	hitbox.setPoint(2, sf::Vector2f(0.f, 50.f));
	hitbox.setFillColor(sf::Color::Blue);
}

void Spaceship::Control()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) this->Move(Spaceship::Direction::Up);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) this->Move(Spaceship::Direction::Back);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) this->Move(Spaceship::Direction::Down);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) this->Move(Spaceship::Direction::Forward);
}

void Spaceship::Move(Spaceship::Direction dir)
{
	switch (dir)
	{
	case Up:
	{
		this->hitbox.move(sf::Vector2f(0.f, -speed));
		break; 
	}
	case Down:
	{
		this->hitbox.move(sf::Vector2f(0.f, speed));
		break;
	}
	case Forward:
	{
		this->hitbox.move(sf::Vector2f(speed, 0.f));
		break;
	}
	case Back:
	{
		this->hitbox.move(sf::Vector2f(-speed, 0.f));
		break;
	}
	}
}

void Spaceship::SpeedUp(float boost)
{
	speed += boost;
}

void Spaceship::Equip(Spaceship::GunType gt)
{
	gun_type = gt;

	if (gun_type == GunType::Simple || gun_type == GunType::Double)
	{
		gun = new Gun_Simple(this);
	}
	else if (gun_type == GunType::Laser || gun_type == GunType::DoubleLaser)
	{
		gun = new Gun_Laser(this);
	}
}

Spaceship::GunType Spaceship::GetGunType()
{
	return gun_type;
}

Gun* Spaceship::Shoot()
{
	return gun->Clone();
}


void Spaceship::Draw(RenderWin* rm)
{
	rm->PutSprite(&hitbox);
}