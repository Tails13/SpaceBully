#include "Engine.h"



int main()
{
	std::srand(time(NULL));
	sf::Clock clock;
	sf::Time fps = sf::microseconds(1000 / 30);

	Engine engine;
	bool bIsDone = false;

	while (!bIsDone)
	{
		sf::Time start = clock.getElapsedTime();
		// Input
		
		// Update
		engine.Update();
		// Render
		engine.Render();

		sf::sleep(start + fps - clock.getElapsedTime());
	}
	
	return 0;
}