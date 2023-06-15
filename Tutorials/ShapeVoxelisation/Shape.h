#pragma once

#include <vector>

#include <glm/vec2.hpp>

#include <raylib/raylib.h>

using std::vector;

using glm::vec2;

struct Shape
{
public:
	Shape(Color _color, float _lineWidth);

	void Draw();

	void AddVert(vec2 _vert);

	const int GetVertCount() const;
	const vec2 GetVertAt(int _id) const;

	vector<vec2> Voxelise(int _density);

private:
	vector<vec2> m_verts;

	Color m_color;
	float m_lineWidth;

private:
	bool Contains(const vec2& _point) const;
	void ComputeBounds(vec2& _min, vec2& _max) const;

};

extern Vector2 Convert(vec2 _vec);
extern vec2 Convert(Vector2 _vec);