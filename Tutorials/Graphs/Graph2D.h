#pragma once

#include "Graph.h"
#include <raylib/raylib.h>

class Graph2D : public Graph<Vector2, float>
{
public:
	void GetNearbyNodes(Vector2 _pos, float _radius, vector<Graph2D::Node*>& _nearby);

};