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
}

// Основные необходимые для анимации установки
void AnimationManager::SetAM(sf::Sprite* sprite, float width, float height)
{
	this->sprite = sprite;
	this->width = width;
	this->height = height;
}

// Установка номера анимации (Столбцы в спрайт-листе)
void AnimationManager::SetNumberAnimation(int n)
{
	this->number_animation = n;
}

// Установка номера кадра (Ряды в спрайт-листе)
void AnimationManager::SetNumberFrame(int n)
{
	this->number_frame = n;
}

// Установка какой кадр будет последним в текущей анимации
void AnimationManager::SetLastFrame(int n)
{
	this->end_frame = n;
}

// Проигрывание текущей анимации до последнего кадра, потом воспроизводится с начала.
// Возможно добавить функцию для единоразового воспроизведения.
void AnimationManager::PlayAnimation()
{
	current_frame += speed_animation;
	if (current_frame > end_frame)
		current_frame -= end_frame;
	sprite->setTextureRect(sf::IntRect((number_animation * width), (int(current_frame) * height), width, height));
}

// Выбор статичного кадра. Не используется совместно с PlayAnimation()
void AnimationManager::ShowFrame(int n)
{
	sprite->setTextureRect(sf::IntRect((number_animation * width), (n * height), width, height));
}