#include "StatePlaying.hpp"
#include "../Gameplay/Living.hpp"
#include "../Collision/CollisionHandler.hpp"
#include "../Input/InputHandler.hpp"
#include "../Gui/Gui.hpp"

StatePlaying::StatePlaying()
{
    GUI::Get().setPlayingState(this);
    m_type = StateType::Playing;
    m_loadFirst = "map_test.tmx";
    m_conMode = Level::InitMode::First;
}

StatePlaying::StatePlaying(const std::string& loadFirst)
{
    GUI::Get().setPlayingState(this);
    m_type = StateType::Playing;
    m_loadFirst = loadFirst;
    m_conMode = Level::InitMode::LoadCheckpoint;
}

void StatePlaying::init()
{
    setLevel(m_loadFirst, m_conMode);
}

void StatePlaying::update(float deltaTime)
{
    if (!m_considered)
    {
        setLevel(m_consider, m_conMode);
        m_considered = true;
    }

    m_level.update(deltaTime);
}

void StatePlaying::leave()
{
}

void StatePlaying::setLevel(const std::string& level, Level::InitMode mode)
{
    if (mode != Level::InitMode::First and mode != Level::InitMode::LoadCheckpoint)
        m_level.leave();
    m_level = Level();
    m_level.init(level, mode);
}

void StatePlaying::begForLevel(const std::string& level, Level::InitMode mode)
{
    m_consider = level;
    m_considered = false;
    m_conMode = mode;
}