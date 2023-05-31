#pragma once

#include "Factory.h"
#include "Enemy.h"

class EnemyFactory : public Factory<Enemy>
{
public:
	EnemyFactory();

	Enemy* Create(unsigned char _type) override;

};