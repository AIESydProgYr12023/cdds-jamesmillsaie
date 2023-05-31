#include "Application.h"

#include <raylib/raylib.h>

#include <vector>

#include "Enemy.h"
#include "EnemyFactory.h"

using std::vector;

vector<Enemy*> enemies;
EnemyFactory* factory;

Application::Application(int _width, int _height, const char* _title)
	: m_width(_width), m_height(_height), m_title(_title)
{
	factory = new EnemyFactory();

	
}

void Application::Run()
{
	InitWindow(m_width, m_height, m_title);
	SetTargetFPS(60);

	for (int i = 0; i < 20; i++)
	{
		eEnemyType type = i % 2 == 0 ? eEnemyType::GHOST : eEnemyType::ZOMBIE;
		enemies.push_back(factory->Create(type));
	}

	while (!WindowShouldClose())
	{
		Update(GetFrameTime());

		BeginDrawing();
		ClearBackground(RAYWHITE);

		Draw();

		EndDrawing();
	}

	CloseWindow();
}

void Application::Draw()
{
	for (auto& e : enemies)
		e->Draw();
}

void Application::Update(float _dt)
{

}