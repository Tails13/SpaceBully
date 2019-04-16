#include "Spaceship.h"

Spaceship::Spaceship() 
{
	CreateHitbox();
	hitbox.setPosition(sf::Vector2f(0.f, 250.f));
	dead = false;
	speed = 4.f;
	bullet = nullptr;
	double_shot = false;
	shoot_cooldown = false;
	sc_count = 0.f;
	Equip(Spaceship::GunType::Simple);
}

void Spaceship::Update()
{
	this->Control();

	if (shoot_cooldown == true) this->Cooldown();
}

void Spaceship::CreateHitbox()
{
	hitbox.setPointCount(6);
	hitbox.setPoint(0, sf::Vector2f(0.f, 25.f));
	hitbox.setPoint(1, sf::Vector2f(0.f, 0.f));
	hitbox.setPoint(2, sf::Vector2f(50.f, 12.5f));
	hitbox.setPoint(3, sf::Vector2f(100.f, 25.f));
	hitbox.setPoint(4, sf::Vector2f(50.f, 37.5f));
	hitbox.setPoint(5, sf::Vector2f(0.f, 50.f));
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

	if (hitbox.getPosition().x < -75 || hitbox.getPosition().x > 975
		|| hitbox.getPosition().y < 0 || hitbox.getPosition().y > 550)
	{
		dead = true;
	}
}

void Spaceship::SpeedUp(float boost)
{
	speed += boost;
}

void Spaceship::Equip(Spaceship::GunType gt)
{
	gun_type = gt;

	if (gun_type == GunType::Simple)
	{
		bullet = new Gun_Simple(this);
	}
	else if (gun_type == GunType::Laser)
	{
		bullet = new Gun_Laser(this);
	}
}

Spaceship::GunType Spaceship::GetGunType()
{
	return gun_type;
}

bool Spaceship::HasDoubleGun()
{
	return double_shot;
}

void Spaceship::Cooldown()
{
	sc_count -= 0.1f;
	if (sc_count <= 0) shoot_cooldown = false;
}

void Spaceship::Shoot(std::list<Gun*>& bullet_list)
{
	if (shoot_cooldown == false)
	{
		Gun* temp_bullet = bullet->Clone();
		bullet_list.push_back(temp_bullet);

		shoot_cooldown = true;
		sc_count = 1.f;
	}
}

void Spaceship::DoubleShoot(std::list<Gun*>& bullet_list)
{
	if (shoot_cooldown == false)
	{
		Gun* temp_bullet_1 = bullet->Clone();
		Gun* temp_bullet_2 = bullet->Clone();
		temp_bullet_1->hitbox.move(sf::Vector2f(0.f, -10.f));
		temp_bullet_2->hitbox.move(sf::Vector2f(0.f, 10.f));
		bullet_list.push_back(temp_bullet_1);
		bullet_list.push_back(temp_bullet_2);

		shoot_cooldown = true;
		sc_count = 1.f;
	}
}

void Spaceship::Draw(RenderWin* rm)
{
	rm->PutShape(&hitbox);
}