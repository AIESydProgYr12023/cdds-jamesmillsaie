#include "Zombie.h"

Zombie::Zombie() : Enemy(eEnemyType::ZOMBIE)
{
	m_position = { (float)GetRandomValue(0, GetScreenWidth()), (float)GetRandomValue(0, GetScreenHeight()) };
}

void Zombie::Draw()
{
	DrawRectangleV(m_position, { 15.f, 15.f }, DARKGREEN);
}

void Zombie::Update(float _dt)
{
	if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
	{
		if (CheckCollisionPointRec(GetMousePosition(), { m_position.x, m_position.y, 15.f, 15.f }))
		{
			SetAlive(false);
		}
	}
}