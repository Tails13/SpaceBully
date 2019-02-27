#include "EnemySpawner.h"

EnemySpawner::EnemySpawner()
{
	_prototype_ship = nullptr;
	bCreate = false;
	fCurrentTime = 0.f;
	fStepTime = 2.f;
	nObjectCount = 0;
	nObjectOrdered = 0;
}



void EnemySpawner::Spawn(std::list<EnemyShip*>& _sprite_list)
{
	if (nObjectOrdered == 0)	// Рандомим сколько будет спавниться мобов
		nObjectOrdered = rand() % 5 + 1;

	if (nObjectCount < nObjectOrdered)  
	{
		fCurrentTime += 0.001f;		// Считаем время между спавном отдельных мобов
		if (fCurrentTime >= fStepTime)
		{
			_sprite_list.push_back(MakeShip());  // Непосредственно спавн
			fCurrentTime = 0;
			nObjectCount++;
		}
	}

	if (nObjectCount == nObjectOrdered)  // Завершаем цикл спавна.
	{
		SetPrototype(nullptr);
		bCreate = false;
		nObjectCount = 0;
		nObjectOrdered = 0;
	}

	//std::cout << nObjectOrdered << " - " << nObjectCount << '\n';
}

EnemyShip* EnemySpawner::MakeShip() const
{
	float temp_y = rand() % 55 * 10; 
	EnemyShip* temp = _prototype_ship->Clone();
	temp->SetPosition(700.f, temp_y);
	return temp;
}

bool EnemySpawner::HasAPrototype()
{
	return _prototype_ship != nullptr;
}

void EnemySpawner::SetPrototype(EnemyShip* prot)
{
	_prototype_ship = prot;
}