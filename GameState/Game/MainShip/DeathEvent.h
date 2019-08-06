#pragma once
#include "../../../Engine/Graphics/AnimationManager.h"

class DeathEvent
{
public:
	DeathEvent();
	bool DeathEventActive();
	void Set(int n);

private:
	bool death_event_active;

	RenderComponent* rc_bang;
	RenderComponent* rc_smoke;

	AnimationManager anim_bang;
	AnimationManager anim_smoke;
};