#include "Engine.h"



int main()
{
	std::srand(time(NULL));

	Engine engine;
	bool bIsDone = false;

	while (!bIsDone)
	{
		// Input
		
		// Update
		engine.Update();
		// Render
		engine.Render();
	}
	
	return 0;
}