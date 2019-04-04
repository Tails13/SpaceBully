#include "SpawnTypes.h"

float SpawnSlow::SetDelay()
{
	return 400.f;
}

void SpawnSlow::SetSpawnPositions()
{
	int count = rand() % 5;
	for (int i = 0; i < count; i++)
	{
		if (i < count)
		{
			this->ship_positions[i].x = 1000 + (50 * i) + (10 * i); // a + b + c, a - ��������� ����� ������, b - ������ �������, � - ���
			this->ship_positions[i].y = (rand() % 10 + 1) * 50;  // ��������� � ����������
		}
		else 
		{
			this->ship_positions[i].x = 0;
			this->ship_positions[i].x = 0;
		}
	}
}