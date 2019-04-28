#include "Engine.h"



int main()
{
	Engine engine;
	bool bIsDone = false;


	sf::Clock clock;

	float previous = clock.getElapsedTime().asMicroseconds();
	float lag = 0.0f;
	const int MS_PER_UPDATE = 25000;

	while (!bIsDone)
	{
		float current_time = clock.getElapsedTime().asMicroseconds();
		float elapsed = current_time - previous;
		previous = current_time;
		lag += elapsed;

		while (lag >= MS_PER_UPDATE)
		{
			engine.Update();
			lag -= MS_PER_UPDATE;
		}
		
		engine.Render(lag / MS_PER_UPDATE);
	}


	/*
	const int TICK_PER_SECOND = 60;
	const int SKIP_TICKS = 1000 / TICK_PER_SECOND;
	const int MAX_FRAMESKIP = 5;

	DWORD next_game_tick = GetTickCount64();
	int loops;
	float interpolation;

	while (!bIsDone)
	{
		loops = 0;

		while (GetTickCount64() > next_game_tick && loops < MAX_FRAMESKIP)
		{
			engine.Update();

			next_game_tick += SKIP_TICKS;
			loops++;
			//std::cout << next_game_tick << std::endl;

			
			interpolation = float(GetTickCount64() + SKIP_TICKS - next_game_tick) / float(SKIP_TICKS);
			if (interpolation < 1.f)
				engine.Render(interpolation); // Передать параметром interpolation
		}

	
	}
	*/

	
	return 0;
}