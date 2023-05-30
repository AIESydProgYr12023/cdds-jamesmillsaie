#pragma once

class GameStateManager;

class Application
{
public:
	Application();

	void Run();

	int windowWidth;
	int windowHeight;

private:
	GameStateManager* m_stateManager;

private:
	void Load();
	void Update(float _dt);
	void Draw();
	void Unload();

};