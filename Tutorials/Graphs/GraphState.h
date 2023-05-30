#pragma once
#include "IGameState.h"

class GraphState : public IGameState
{
public:
	GraphState(Application* _app);
	virtual void Start() override;
	virtual void Update(float _dt) override;
	virtual void Draw() override;
	virtual void OnDestroy() override;

private:

};