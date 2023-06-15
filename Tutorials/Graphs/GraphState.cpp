#include "GraphState.h"

#include "Graph2D.h"
#include "GraphEditor.h"

#include <raylib/raymath.h>

GraphState::GraphState(Application* _app) : IGameState(_app)
{

}

void GraphState::Start()
{
	m_graph = new Graph2D();
	m_editor = new GraphEditor(m_graph);

	int numRows = 4;
	int numCols = 6;
	float xOffset = 100;
	float yOffset = 100;
	float spacing = 50;

	for (int y = 0; y < numRows; y++)
	{
		for (int x = 0; x < numCols; x++)
		{
			m_graph->AddNode(
				{
					x * spacing + xOffset,
					y * spacing + yOffset
				});
		}
	}

	for (auto& node : m_graph->GetNodes())
	{
		vector<Graph2D::Node*> nearby;
		m_graph->GetNearbyNodes(node->data, 60.f, nearby);

		for (auto& conn : nearby)
		{
			if (conn == node)
				continue;

			float dist = Vector2Distance(node->data, conn->data);
			m_graph->AddEdge(node, conn, dist);
			m_graph->AddEdge(conn, node, dist);
		}
	}
}

void GraphState::Update(float _dt)
{
	m_editor->Update(_dt);
}

void GraphState::Draw()
{
	m_editor->Draw();
}

void GraphState::OnDestroy()
{

}