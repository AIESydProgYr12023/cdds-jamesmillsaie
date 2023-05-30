#pragma once
#include "Application.h"
#include "Entity.h"

#include <vector>
using std::vector;

class EntityDisplayApp : public Application
{
public:
	EntityDisplayApp(int _screenWidth, int _screenHeight);
	virtual ~EntityDisplayApp();

	virtual void Startup();
	virtual void Shutdown();

	virtual void Update(float _deltaTime);
	virtual void Draw();

protected:
	// an array of an unknown number of entities
	vector<Entity> m_entities;

};

