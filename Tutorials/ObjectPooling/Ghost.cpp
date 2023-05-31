#include "Ghost.h"

#include <raylib/raylib.h>

Ghost::Ghost() : Enemy(eEnemyType::GHOST)
{
	m_position = { (float)GetRandomValue(0, GetScreenWidth()), (float)GetRandomValue(0, GetScreenHeight()) };
}

void Ghost::Draw()
{
	DrawCircleV(m_position, 10.f, GRAY);
}

void Ghost::Update(float _dt)
{
	if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
	{
		if (CheckCollisionPointCircle(GetMousePosition(), m_position, 10.f))
		{
			SetAlive(false);
		}
	}
}