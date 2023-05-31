#pragma once

#include "Enemy.h"

class Ghost : public Enemy
{
public:
	Ghost();

	void Draw() override;

};