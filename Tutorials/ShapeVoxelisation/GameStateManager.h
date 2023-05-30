#pragma once

#include <vector>
#include <map>
#include <functional>

using std::vector;
using std::map;
using std::function;

class Application;
class IGameState;

class GameStateManager
{
public:
    GameStateManager(Application* _app);
    ~GameStateManager();

    void Update(float _dt);
    void Draw();

    void ActivateState(const char* _id);
    void DeactivateState(const char* _id);
    void AddState(IGameState* _state);

    Application* GetApp();

private:
    vector<IGameState*> m_active;
    vector<function<void()>> m_updates;
    map<const char*, IGameState*> m_states;



    Application* m_app;
};

