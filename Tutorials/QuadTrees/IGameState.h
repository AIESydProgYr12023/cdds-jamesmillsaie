#pragma once

class GameStateManager;

class IGameState
{
public:
    const char* id;
    IGameState(const char* _id, GameStateManager* _manager);
    ~IGameState();

    virtual void Load() = 0;
    virtual void Update(float _dt) = 0;
    virtual void Draw() = 0;
    virtual void Unload() = 0;

protected:
    GameStateManager* m_stateManager;

};

