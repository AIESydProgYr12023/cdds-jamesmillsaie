#include "Application.h"

#include <raylib/raylib.h>

#include "EnemyFactory.h"
#include "Enemy.h"

#include "ObjectPool.h"

ObjectPool<Enemy, EnemyFactory>* pool;
vector<Enemy*> enemies;

Application::Application(int _width, int _height, const char* _title)
	: m_width(_width), m_height(_height), m_title(_title)
{
}

void Application::Run()
{
	InitWindow(m_width, m_height, m_title);
	SetTargetFPS(60);

	pool = new ObjectPool<Enemy, EnemyFactory>(20, (unsigned char)eEnemyType::GHOST);

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
	vector<Enemy*> dead;

	for (auto& e : enemies)
	{
		e->Update(_dt);
		if (!e->IsAlive())
			dead.push_back(e);
	}

	while (!dead.empty())
	{
		Enemy* e = dead[0];

		enemies.erase(std::ranges::find(enemies, e));
		pool->Return(e);
		dead.erase(std::ranges::find(dead, e));
	}

	if (IsKeyPressed(KEY_SPACE))
	{
		Enemy* newE = pool->Retrieve();
		if (newE != nullptr)
		{
			enemies.push_back(newE);
			newE->SetAlive(true);
		}
	}
}