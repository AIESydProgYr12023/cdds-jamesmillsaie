#include "QuadTreeState.h"

#include "QuadTree.h"

QuadTreeState::QuadTreeState(GameStateManager* _stateManager)
	: IGameState("QTS", _stateManager), m_quadTree(nullptr)
{
}

void QuadTreeState::Load()
{
	Rectangle screenBounds
	{
		0,
		0,
		GetScreenWidth(),
		GetScreenHeight()
	};

	m_quadTree = new QuadTree<Vector2>(screenBounds);
}

void QuadTreeState::Update(float _dt)
{
	if (IsMouseButtonPressed(0))
	{
		const float DOT_SIZE = 5.f;
		const float DOT_HALF_SIZE = DOT_SIZE * 0.5f;

		Vector2 mousePos = GetMousePosition();
		Rectangle dotRect
		{
			mousePos.x - DOT_HALF_SIZE,
			mousePos.y - DOT_HALF_SIZE,
			DOT_SIZE,
			DOT_SIZE
		};

		m_quadTree->Insert(new QuadTreeData<Vector2>(new Vector2{ mousePos.x, mousePos.y }, dotRect));
	}
}

void QuadTreeState::Draw()
{
	// Purely for debug visualisation
	m_quadTree->Draw();
}

void QuadTreeState::Unload()
{
}
