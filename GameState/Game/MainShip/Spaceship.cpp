#include "Spaceship.h"
#include "../../../Engine/AudioSystem/AudioSystem.h"

Spaceship::Spaceship() 
{
	CreateHitbox();
	hitbox.setPosition(sf::Vector2f(0.f, 250.f));

	render_component = new RenderComponent("Resources/Graphics/MainShip.png");

	speed = 2.5f;
	bullet = nullptr;
	double_shot = false;
	shoot_cooldown = false;
	sc_count = 0.f;
	Equip(Spaceship::GunType::Simple);
}

void Spaceship::Update()
{
	if (!this->death.DeathEventActive())
	{
		velocity.x = 0;
		velocity.y = 0;
		this->Control();
	}
	else
	{
		death.PlayBangAnimation();
		Fall();
	}
		
	render_component->CollectRenderData(velocity, hitbox.getPosition());

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

void Spaceship::DeathEventStart()
{
	if (!death.DeathEventActive())
		death.SetBangPosition(hitbox.getPosition());

	this->render_component->sprite.setRotation(50.f);
	death.Set(1);
}

void Spaceship::DeathEventStop()
{
	death.anim_bang.Restart();
	this->render_component->sprite.setRotation(0.f);
	death.Set(0);
}

void Spaceship::Control()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) this->Move(Spaceship::Direction::Up);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) this->Move(Spaceship::Direction::Back);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) this->Move(Spaceship::Direction::Down);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) this->Move(Spaceship::Direction::Forward);
}

void Spaceship::Fall()
{
	if (this->hitbox.getPosition().y < 700)
	{
		death.SetPosition(hitbox.getPosition());
		death.PlaySmokeAnimation();

		velocity.y = 4.5f;
		this->hitbox.move(sf::Vector2f(velocity.x, velocity.y));
		std::cout << this->hitbox.getPosition().y << std::endl;
	}
}


void Spaceship::Move(Spaceship::Direction dir)
{
	switch (dir)
	{
	case Up:
	{
		velocity.y -= speed;
		this->hitbox.move(sf::Vector2f(0.f, velocity.y));
		break; 
	}
	case Down:
	{
		velocity.y += speed;
		this->hitbox.move(sf::Vector2f(0.f, velocity.y));
		break;
	}
	case Forward:
	{
		velocity.x += speed;
		this->hitbox.move(sf::Vector2f(velocity.x, 0.f));
		break;
	}
	case Back:
	{
		velocity.x -= speed;
		this->hitbox.move(sf::Vector2f(velocity.x, 0.f));
		break;
	}
	}

	// Проверка, находится ли игрок в пределах экрана. 
	// Столкновение срабатывает уже при частичном выходе из игровой области.
	if (hitbox.getPosition().x < -75 || hitbox.getPosition().x > 975
		|| hitbox.getPosition().y < 0 || hitbox.getPosition().y > 550)
	{
		this->DeathEventStart();
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

// Выяснить где используются следующие функции
//=========================
Spaceship::GunType Spaceship::GetGunType()
{
	return gun_type;
}

bool Spaceship::HasDoubleGun()
{
	return double_shot;
}

void Spaceship::DoubleShootActived()
{
	double_shot = true;
}

void Spaceship::DoubleShootDeactived()
{
	double_shot = false;
}
//=========================

// Кулдаун выстрела
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

		AudioSystem::Instance().Play_Sound("Shoot.ogg");
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

		AudioSystem::Instance().Play_Sound("Shoot.ogg");
	}
}
