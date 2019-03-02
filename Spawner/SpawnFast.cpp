#include "SpawnTypes.h"

float SpawnFast::SetDelay()
{
	return 25.f;
}

void SpawnFast::SetSpawnPositions()
{
	int count = rand() % 9; 
	for (int i = 0; i < 10; i++)
	{
		if (i < count)
		{
			this->ship_positions[i].x = 1000 + (50 * i) + (10 * i); // a + b + c, a - начальная точка спавна, b - ширина корабля, с - шаг
			this->ship_positions[i].y = (rand() % 10 + 1) * 50;  // рандомная у координата
		}
		else 
		{
			this->ship_positions[i].x = 0;
			this->ship_positions[i].x = 0;
		}
		
	}
}