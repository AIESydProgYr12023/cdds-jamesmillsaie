#include "Graph2D.h"

#include <raylib/raymath.h>

void Graph2D::GetNearbyNodes(Vector2 _pos, float _radius, vector<Graph2D::Node*>& _nearby)
{
	for (auto& node : m_nodes)
	{
		float dist = Vector2Distance(_pos, node->data);
		if (dist < _radius)
			_nearby.push_back(node);
	}
}
