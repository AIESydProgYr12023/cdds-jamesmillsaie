#pragma once

#include "IGameState.h"

#include <raylib/raylib.h>

#include <glm/vec2.hpp>

#include <vector>

using glm::vec2;
using std::vector;

class GameStateManager;
struct Shape;

class TutorialState : public IGameState
{
public:
	TutorialState(GameStateManager* _stateManager);

	// Inherited via IGameState
	virtual void Load() override;
	virtual void Update(float _dt) override;
	virtual void Draw() override;
	virtual void Unload() override;

private:
	Shape* m_shape;
	vector<vec2> m_voxels;

};

