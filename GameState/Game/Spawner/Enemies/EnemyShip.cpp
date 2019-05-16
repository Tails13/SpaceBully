#include "EnemyShip.h"

EnemyShip::~EnemyShip()
{
	std::cout << "destructor Ship\n";
}

// ��������, ��� ������� ������� �����.
bool EnemyShip::IsInBounds()
{
	return this->hitbox.getPosition().x > -50.f;
}

// ��������, ��� ������� �������� �� ������.
bool EnemyShip::IsShow()
{
	return this->hitbox.getPosition().x < 1000;
}

void EnemyShip::TakeDamage(int dmg)
{
	this->hp -= dmg;
	if (this->hp <= 0)
	{
		this->dead = true;
	}
}

bool EnemyShip::IsDead()
{
	return this->dead;
}

// ��������� ������� ������������ ��� ������� ��������
//==================
float EnemyShip::Width()
{
	return this->width;
}

float EnemyShip::Height()
{
	return this->height;
}

float EnemyShip::X()
{
	return this->hitbox.getPosition().x;
}

float EnemyShip::Y()
{
	return this->hitbox.getPosition().y;
}
//==================

// �������� ����!
RenderData EnemyShip::GetRenderData()
{
	return this->render_data;
}