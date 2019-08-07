#pragma once
#include "../../../Engine/Graphics/AnimationManager.h"

class DeathEvent
{
public:
	DeathEvent();
	bool DeathEventActive();
	void Set(int n);
	void SetPosition(sf::Vector2f);
	void SetBangPosition(sf::Vector2f);
	void PlayBangAnimation();
	void PlaySmokeAnimation();
	RenderData GetBangRenderData();
	RenderData GetSmokeRenderData();

	RenderComponent* rc_bang;
	RenderComponent* rc_smoke;

	AnimationManager anim_bang;
	AnimationManager anim_smoke;

private:
	bool death_event_active;
	sf::Vector2f ship_pos;
	sf::Vector2f bang_pos;
};