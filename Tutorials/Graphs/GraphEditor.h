#pragma once

class Graph2D;

class GraphEditor
{
public:
	GraphEditor(Graph2D* _graph, float _radius = 1.f);

	void Update(float _dt);
	void Draw();

	const Graph2D* GetGraph();
	void SetGraph(Graph2D* _graph);

protected:
	Graph2D* m_graph;
	float m_radius;

};

