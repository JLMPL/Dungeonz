#include "GameState.hpp"

void GameState::setExitFunc(std::function<void ()> func)
{
    m_exitFunction = func;
}

GameState::Type GameState::getType()
{
    return m_type;
}