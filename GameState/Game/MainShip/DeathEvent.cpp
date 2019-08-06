#include "DeathEvent.h"

DeathEvent::DeathEvent()
{
	rc_bang = new RenderComponent("Resources/Graphics/Bang.png");
	rc_smoke = new RenderComponent("Resources/Graphics/Smoke.png");
	death_event_active = false;
}

bool DeathEvent::DeathEventActive()
{
	return death_event_active;
}

void DeathEvent::Set(int n)
{
	if (n == 0)
		death_event_active = false;
	else
		death_event_active = true;
}