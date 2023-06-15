#include "TutorialState.h"

#include "Shape.h"

const int DENSITY = 2;
const float LINE_THICKNESS = 1.5f;

TutorialState::TutorialState(GameStateManager* _stateManager)
	: IGameState("Tut", _stateManager),
	m_shape(new Shape(BLUE, LINE_THICKNESS))
{
}

void TutorialState::Load()
{
	
}

void TutorialState::Update(float _dt)
{
	if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
		m_shape->AddVert(Convert(GetMousePosition()));

	if (IsKeyPressed(KEY_SPACE))
		m_voxels = m_shape->Voxelise(DENSITY);
}

void TutorialState::Draw()
{
	DrawCircleV(GetMousePosition(), 5.f, BLUE);

	if (m_shape->GetVertCount() > 0)
	{
		vec2 pos = m_shape->GetVertAt(m_shape->GetVertCount() - 1);
		DrawLineEx(Convert(pos), GetMousePosition(),
			LINE_THICKNESS, BLUE);
	}

	for (auto& voxel : m_voxels)
	{
		Rectangle rect
		{
			voxel.x + 1 - (DENSITY * 0.5f),
			voxel.y + 1 - (DENSITY * 0.5f),
			DENSITY - 1,
			DENSITY - 1
		};

		DrawRectangleLinesEx(
			rect, 
			LINE_THICKNESS, 
			GREEN);
	}

	m_shape->Draw();
}

void TutorialState::Unload()
{
	
}
