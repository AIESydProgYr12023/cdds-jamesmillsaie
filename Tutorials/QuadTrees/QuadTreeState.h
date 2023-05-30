#pragma once

#include "IGameState.h"

class GameStateManager;

class QuadTreeState : public IGameState
{
public:
	QuadTreeState(GameStateManager* _stateManager);

	// Inherited via IGameState
	virtual void Load() override;
	virtual void Update(float _dt) override;
	virtual void Draw() override;
	virtual void Unload() override;

private:

};

