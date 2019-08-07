#pragma once
#include "Background.h"

class AnimationManager
{
public:
	AnimationManager();
	void SetAM(sf::Sprite* sprite, float width, float height);
	void SetNumberAnimation(int);
	void SetNumberFrame(int);
	void SetLastFrame(int);
	void SetLoop(bool);
	void Restart();
	void PlayAnimation();
	void ShowFrame(int);

private:
	sf::Sprite* sprite;
	float width;
	float height;
	float current_frame;
	int end_frame;
	int number_frame;
	int number_animation;	
	float speed_animation;
	bool end;
	bool loop;
};