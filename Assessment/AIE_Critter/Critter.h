#pragma once

#include <raylib/raylib.h>

class Critter
{
public:
	Critter();
	~Critter();

	void Init(Vector2 _position, Vector2 _velocity, float _radius, const char* _texture);
	void Destroy();
	void Update(float dt);
	void Draw();

	float GetX() { return m_position.x; }
	float GetY() { return m_position.y; }
	void SetX(float x) { m_position.x = x; }
	void SetY(float y) { m_position.y = y; }

	Vector2 GetPosition() { return m_position; }
	void SetPosition(Vector2 _position) { m_position = _position; }

	Vector2 GetVelocity() { return m_velocity; }
	void SetVelocity(Vector2 _velocity) { m_velocity = _velocity; }

	float GetRadius() { return m_radius; }

	bool IsDirty() { return m_isDirty; }
	void SetDirty() { m_isDirty = true; }

	bool IsDead() { return m_isLoaded == false; }

protected:
	Vector2 m_position;
	Vector2 m_velocity;
	float m_radius;

	Texture2D m_texture;

	bool m_isLoaded;
	bool m_isDirty;		// indicates if we've already processed a collision response for this critter

};

