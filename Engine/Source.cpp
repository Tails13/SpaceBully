#include "Engine.h"



int main()
{
	Engine engine;
	bool bIsDone = false;

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
			std::cout << next_game_tick << std::endl;
		}

		interpolation = float(GetTickCount64() + SKIP_TICKS - next_game_tick) / float(SKIP_TICKS);
		
		engine.Render(); // Передать параметром interpolation
	}
	
	return 0;
}