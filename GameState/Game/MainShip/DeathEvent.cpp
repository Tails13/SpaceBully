#include "DeathEvent.h"

DeathEvent::DeathEvent()
{
	death_event_active = false;
	ship_pos = sf::Vector2f(0.f, 0.f);
	scale_GOM = sf::Vector2f(1.f, 1.f);
	scale_up = true;

	rc_bang = new RenderComponent("Resources/Graphics/Bang.png");
	rc_smoke = new RenderComponent("Resources/Graphics/Smoke.png");
	rc_game_over = new RenderComponent("Resources/Graphics/Game_over_message.png");

	rc_bang->CollectRenderData(sf::Vector2f(0.f, 0.f), ship_pos);
	rc_smoke->CollectRenderData(sf::Vector2f(0.f, 0.f), ship_pos);
	rc_game_over->CollectRenderData(sf::Vector2f(0.f, 0.f), sf::Vector2f(150.f, 160.f));

	anim_bang.SetAM(rc_bang->GetRenderData().sprite_for_drawing, 90, 120);
	anim_bang.SetNumberAnimation(0);
	anim_bang.SetNumberFrame(0);
	anim_bang.SetLastFrame(7);
	anim_bang.SetLoop(false);

	anim_smoke.SetAM(rc_smoke->GetRenderData().sprite_for_drawing, 60, 60);
	anim_smoke.SetNumberAnimation(0);
	anim_smoke.SetNumberFrame(0);
	anim_smoke.SetLastFrame(4);
	anim_smoke.SetLoop(true);
}

DeathEvent::~DeathEvent()
{
	delete rc_bang;
	delete rc_smoke;
	delete rc_game_over;
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

void DeathEvent::SetPosition(sf::Vector2f pos)
{
	ship_pos = pos;
}

void DeathEvent::SetBangPosition(sf::Vector2f pos)
{
	bang_pos = pos;
}

void DeathEvent::PlayBangAnimation()
{
	rc_bang->CollectRenderData(sf::Vector2f(0.f, 0.f), sf::Vector2f(bang_pos.x - 15, bang_pos.y - 20));
	anim_bang.PlayAnimation();
}

void DeathEvent::PlaySmokeAnimation()
{
	rc_smoke->CollectRenderData(sf::Vector2f(0.f, 0.f), sf::Vector2f(ship_pos.x - 40, ship_pos.y - 10));
	anim_smoke.PlayAnimation();
}

void DeathEvent::PlayGameOverMessageAnimation()
{
	if (scale_up)
	{
		scale_GOM.x += 0.02f;
		scale_GOM.y += 0.02f;
		if (scale_GOM.x >= 1.8f) scale_up = false;
	}
	else if (!scale_up)
	{
		if (scale_GOM.x <= 1) scale_up = true;
		scale_GOM.x -= 0.02f;
		scale_GOM.y -= 0.02f;
	}
	rc_game_over->sprite.setScale(scale_GOM);
}

RenderData DeathEvent::GetBangRenderData()
{
	return rc_bang->GetRenderData();
}

RenderData DeathEvent::GetSmokeRenderData()
{
	return rc_smoke->GetRenderData();
}

RenderData DeathEvent::GetGOMRenderData()
{
	return rc_game_over->GetRenderData();
}