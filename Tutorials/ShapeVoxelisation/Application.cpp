#include "Application.h"

#include <raylib/raylib.h>

#include "GameStateManager.h"
#include "TutorialState.h"

Application::Application()
	: m_stateManager(nullptr)
{
	windowWidth = 640;
	windowHeight = 480;
}

void Application::Run()
{
	Load();

	while (!WindowShouldClose())
	{
		Update(GetFrameTime());

		BeginDrawing();
		ClearBackground(RAYWHITE);
		Draw();
		EndDrawing();
	}

	Unload();
}

void Application::Load()
{
	InitWindow(windowWidth, windowHeight, "Shape Voxelisation");
	SetTargetFPS(60);

	m_stateManager = new GameStateManager(this);

	m_stateManager->AddState(new TutorialState(m_stateManager));
	m_stateManager->ActivateState("Tut");
}

void Application::Update(float _dt)
{
	m_stateManager->Update(_dt);
}

void Application::Draw()
{
	m_stateManager->Draw();
}

void Application::Unload()
{
	CloseWindow();

	delete m_stateManager;
	m_stateManager = nullptr;
}