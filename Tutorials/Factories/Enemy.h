#pragma once

#include <raylib/raylib.h>

enum class eEnemyType : unsigned char
{
	GHOST,
	ZOMBIE
};

class Enemy
{
public:
	Enemy(eEnemyType _type) : m_type(_type), m_position({ 0, 0 }) {}

	const eEnemyType& GetType() const { return m_type; }

	virtual void Draw() = 0;

protected:
	eEnemyType m_type;
	Vector2 m_position;

};