#include "GraphEditor.h"

#include "Graph2D.h"

#include <raylib/raymath.h>

GraphEditor::GraphEditor(Graph2D* _graph, float _radius)
	: m_graph(_graph), m_radius(_radius)
{
}

void GraphEditor::Update(float _dt)
{
}

void GraphEditor::Draw()
{
	for (auto& node : m_graph->GetNodes())
	{
		for (auto& conn : node->connections)
		{
			DrawLineV(node->data, conn.to->data, GRAY);
		}
	}

	for (auto& node : m_graph->GetNodes())
	{
		DrawCircleV(node->data, 8.f, LIGHTGRAY);
		DrawCircleLines(node->data.x, node->data.y, 8.f, GRAY);
	}

	Vector2 mousePos = GetMousePosition();
	DrawCircleV(mousePos, 6.f, LIGHTGRAY);

	vector<Graph2D::Node*> nearby;
	m_graph->GetNearbyNodes(mousePos, 60.f, nearby);

	for (auto& node : nearby)
		DrawLineV(mousePos, node->data, LIGHTGRAY);
}

const Graph2D* GraphEditor::GetGraph()
{
	return m_graph;
}

void GraphEditor::SetGraph(Graph2D* _graph)
{
	m_graph = _graph;
}
