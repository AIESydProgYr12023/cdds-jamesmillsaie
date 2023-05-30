#pragma once

class Application
{
public:
	Application(int _screenWidth, int _screenHeight, const char* _windowTitle);
	virtual ~Application();

	void Run();

	virtual void Startup() = 0;
	virtual void Shutdown() = 0;

	virtual void Update(float _deltaTime) = 0;
	virtual void Draw() = 0;

protected:
	int m_screenWidth;
	int m_screenHeight;
	const char* m_windowTitle;

};
