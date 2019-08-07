#include "AnimationManager.h"


AnimationManager::AnimationManager()
{
	this->sprite = nullptr;
	this->width = 0;
	this->height = 0;
	this->current_frame = 0.f;
	this->end_frame = 0;
	this->number_animation = 0;
	this->number_frame = 0;
	this->speed_animation = 0.1f; 
	this->end = false;
	this->loop = true;
}

// �������� ����������� ��� �������� ���������
void AnimationManager::SetAM(sf::Sprite* sprite, float width, float height)
{
	this->sprite = sprite;
	this->width = width;
	this->height = height;
}

// ��������� ������ �������� (������� � ������-�����)
void AnimationManager::SetNumberAnimation(int n)
{
	this->number_animation = n;
}

// ��������� ������ ����� (���� � ������-�����)
void AnimationManager::SetNumberFrame(int n)
{
	this->number_frame = n;
}

// ��������� ����� ���� ����� ��������� � ������� ��������
void AnimationManager::SetLastFrame(int n)
{
	this->end_frame = n;
}

void AnimationManager::SetLoop(bool b)
{
	loop = b;
}

void AnimationManager::Restart()
{
	end = false;
	current_frame = 0;
}

// ������������ ������� �������� �� ���������� �����, ����� ��������������� � ������.
// �������� �������� ������� ��� ������������� ���������������.
void AnimationManager::PlayAnimation()
{
	if (!end)
	{
		current_frame += speed_animation;
		if (current_frame > end_frame)
		{
			if (loop)
				current_frame -= end_frame;
			else
				end = true;
		}
		sprite->setTextureRect(sf::IntRect((number_animation * width), (int(current_frame) * height), width, height));
	}
}

// ����� ���������� �����. �� ������������ ��������� � PlayAnimation()
void AnimationManager::ShowFrame(int n)
{
	sprite->setTextureRect(sf::IntRect((number_animation * width), (n * height), width, height));
}