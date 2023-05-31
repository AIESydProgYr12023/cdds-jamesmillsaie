#pragma once

#include "Enemy.h"

class Zombie : public Enemy
{
public:
	Zombie();

	void Draw() override;
	void Update(float _dt) override;

};