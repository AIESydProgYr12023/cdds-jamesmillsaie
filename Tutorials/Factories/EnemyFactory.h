#pragma once

#include "Enemy.h"

class EnemyFactory
{
public:
	EnemyFactory();

	Enemy* Create(eEnemyType _type);

};