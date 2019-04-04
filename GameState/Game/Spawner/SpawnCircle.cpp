#include "SpawnTypes.h"

float SpawnCircle::SetDelay()
{
	return 1000.f;
}

void SpawnCircle::SetSpawnPositions()
{
	int temp_y = (rand() % 10 + 1) * 50;  // ��������� � ����������
	for (int i = 0; i < 10; i++)
	{
			this->ship_positions[i].x = 1000 + (50 * i) + (10 * i); // a + b + c, a - ��������� ����� ������, b - ������ �������, � - ���
			this->ship_positions[i].y = temp_y;
	}
}