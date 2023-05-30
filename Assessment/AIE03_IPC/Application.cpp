#include "Application.h"

#include <raylib/raylib.h>

Application::Application(int _screenWidth, int _screenHeight, const char* _windowTitle) :
	m_screenWidth(_screenWidth), m_screenHeight(_screenHeight), m_windowTitle(_windowTitle)
{

}

Application::~Application()
{

}

void Application::Run()
{
	InitWindow(m_screenWidth, m_screenHeight, "EntityDisplayApp");
	SetTargetFPS(60);
	Startup();
	while (!WindowShouldClose())
	{
		Update(GetFrameTime());
		Draw();
	}
	Shutdown();
	CloseWindow();
}