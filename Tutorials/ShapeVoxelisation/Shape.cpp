#include "Shape.h"

#include <glm/gtx/vector_angle.hpp>

Shape::Shape(Color _color, float _lineWidth)
	: m_color(_color), m_lineWidth(_lineWidth)
{
}

void Shape::Draw()
{
	if (m_verts.size() < 2)
		return;

	DrawLineEx(
		Convert(m_verts[0]),
		Convert(m_verts[m_verts.size() - 1]),
		m_lineWidth,
		m_color);

	for (int i = 0; i < m_verts.size() - 1; i++)
	{
		DrawLineEx(
			Convert(m_verts[i]),
			Convert(m_verts[i + 1]),
			m_lineWidth,
			m_color
		);
	}
}

void Shape::AddVert(vec2 _vert)
{
	m_verts.push_back(_vert);
}

const int Shape::GetVertCount() const
{
	return m_verts.size();
}

const vec2 Shape::GetVertAt(int _id) const
{
	if (_id >= m_verts.size())
		return {};

	return m_verts[_id];
}

vector<vec2> Shape::Voxelise(int _density)
{
	vec2 bMin = {}, bMax = {};
	ComputeBounds(bMin, bMax);

	vector<vec2> voxels;

	for (int x = (int)bMin.x; x < (int)bMax.x; x += _density)
	{
		for (int y = (int)bMin.y; y < (int)bMax.y; y += _density)
		{
			vec2 point = { x, y };
			if (Contains(point))
				voxels.push_back(point);
		}
	}

	return voxels;
}

bool Shape::Contains(const vec2& _point) const
{
	vec2 a = glm::normalize(m_verts[0] - _point);
	vec2 b = glm::normalize(m_verts[m_verts.size() - 1] - _point);

	float angle = glm::angle(a, b);
	for (int i = 0; i < m_verts.size() - 1; i++)
	{
		a = glm::normalize(m_verts[i] - _point);
		b = glm::normalize(m_verts[i + 1] - _point);

		angle += glm::angle(a, b);
	}

	const float EPSILON = 1E-5;
	return abs(angle - 2.f * PI) < EPSILON;
}

void Shape::ComputeBounds(vec2& _min, vec2& _max) const
{
	float xMin = FLT_MAX, yMin = FLT_MAX;
	float xMax = FLT_MIN, yMax = FLT_MIN;

	for (auto& vert : m_verts)
	{
		xMin = fminf(xMin, vert.x);
		yMin = fminf(yMin, vert.y);
		xMax = fmaxf(xMax, vert.x);
		yMax = fmaxf(yMax, vert.y);
	}

	_min.x = xMin;
	_min.y = yMin;
	_max.x = xMax;
	_max.y = yMax;
}

Vector2 Convert(vec2 _vec)
{
	return { _vec.x, _vec.y };
}

vec2 Convert(Vector2 _vec)
{
	return { _vec.x, _vec.y };
}
