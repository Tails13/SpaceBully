#pragma once
#include "../../../Engine/Graphics/AnimationManager.h"

class DeathEvent
{
public:
	DeathEvent();
	~DeathEvent();
	bool DeathEventActive();
	void Set(int n);
	void SetPosition(sf::Vector2f);
	void SetBangPosition(sf::Vector2f);
	void PlayBangAnimation();
	void PlaySmokeAnimation();
	void PlayGameOverMessageAnimation();
	RenderData GetBangRenderData();
	RenderData GetSmokeRenderData();
	RenderData GetGOMRenderData();

	RenderComponent* rc_bang;
	RenderComponent* rc_smoke;
	RenderComponent* rc_game_over;

	AnimationManager anim_bang;
	AnimationManager anim_smoke;

private:
	bool death_event_active;
	sf::Vector2f ship_pos;
	sf::Vector2f bang_pos;

	sf::Vector2f scale_GOM;
	bool scale_up;
};