#include "Application.h"

#include <raylib/raylib.h>

#include "GameStateManager.h"

#include "GraphState.h"

Application::Application()
{
	windowWidth = 640;
	windowHeight = 480;
}

void Application::Run()
{
	Start();

	while (!WindowShouldClose())
	{
		Update(GetFrameTime());

		BeginDrawing();
		ClearBackground(RAYWHITE);
		Draw();
		EndDrawing();
	}

	OnDestroy();
}

void Application::Start()
{
	InitWindow(windowWidth, windowHeight, "Graphs");
	SetTargetFPS(60);

	stateManager = new GameStateManager();

	stateManager->SetState("graph", new GraphState(this));
	stateManager->PushState("graph");
}

void Application::Update(float _dt)
{
	stateManager->Update(_dt);
}

void Application::Draw()
{
	stateManager->Draw();
}

void Application::OnDestroy()
{
	CloseWindow();

	delete stateManager;
}