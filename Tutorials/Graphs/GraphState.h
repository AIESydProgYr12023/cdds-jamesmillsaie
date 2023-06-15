#pragma once
#include "IGameState.h"

class Graph2D;
class GraphEditor;

class GraphState : public IGameState
{
public:
	GraphState(Application* _app);
	virtual void Start() override;
	virtual void Update(float _dt) override;
	virtual void Draw() override;
	virtual void OnDestroy() override;

private:
	GraphEditor* m_editor = nullptr;
	Graph2D* m_graph = nullptr;

};