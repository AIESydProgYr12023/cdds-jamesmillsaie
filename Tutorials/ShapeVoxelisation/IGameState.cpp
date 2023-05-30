#include "IGameState.h"

IGameState::IGameState(const char* _id, GameStateManager* _manager)
    : id(_id), m_stateManager(_manager)
{

}

IGameState::~IGameState()
{
    m_stateManager = nullptr;
}
