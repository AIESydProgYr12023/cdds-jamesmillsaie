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
	Enemy(eEnemyType _type) : m_type(_type), m_position({ 0, 0 }), m_alive(false) {}

	const eEnemyType& GetType() const { return m_type; }

	virtual void Draw() = 0;
	virtual void Update(float _dt) = 0;

	const bool IsAlive() const { return m_alive; }
	void SetAlive(bool _isAlive) { m_alive = _isAlive; }

protected:
	eEnemyType m_type;
	Vector2 m_position;
	bool m_alive;

};