#include "Critter.h"

Critter::Critter()
{
	m_position = Vector2{ 0, 0 };
	m_velocity = Vector2{ 0, 0 };
	m_radius = 0;
	m_isLoaded = false;
	m_isDirty = false;
}

Critter::~Critter()
{
	UnloadTexture(m_texture);
	m_isLoaded = false;
}

void Critter::Init(Vector2 _position, Vector2 _velocity, float _radius, const char* _texture)
{
	m_position = _position;
	m_velocity = _velocity;
	m_radius = _radius;

	m_texture = LoadTexture(_texture);

	m_isLoaded = true;
}

void Critter::Destroy()
{
	UnloadTexture(m_texture);
	m_isLoaded = false;
}

void Critter::Update(float _dt)
{
	if (!m_isLoaded)
		return;

	m_position.x += m_velocity.x * _dt;
	m_position.y += m_velocity.y * _dt;

	m_isDirty = false;
}

void Critter::Draw()
{
	if (!m_isLoaded)
		return;

	DrawTexture(m_texture, m_position.x, m_position.y, WHITE);
}
