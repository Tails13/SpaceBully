#include "Engine.h"



int main()
{
	Engine engine;
	bool bIsDone = false;


	sf::Clock clock;

	float previous = clock.getElapsedTime().asMicroseconds();
	float lag = 0.0f;
	const int MS_PER_UPDATE = 15000;

	//int count = 0;

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
			//count++;
		}
		
		//std::cout << count << "  ";
		//count = 0;

		engine.Render(lag / MS_PER_UPDATE);
	}
	
	return 0;
}