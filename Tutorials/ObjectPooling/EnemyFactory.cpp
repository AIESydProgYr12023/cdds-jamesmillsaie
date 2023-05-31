#include "EnemyFactory.h"

#include "Enemy.h"
#include "Ghost.h"
#include "Zombie.h"

#include <iostream>

EnemyFactory::EnemyFactory() = default;

Enemy* EnemyFactory::Create(eEnemyType _type)
{
	if (_type == eEnemyType::GHOST)
		return new Ghost();

	if (_type == eEnemyType::ZOMBIE)
		return new Zombie();

	std::cout << "Unknown enemy type!" << std::endl;
	return nullptr;
}