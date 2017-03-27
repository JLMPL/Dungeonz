#include "StatePlaying.hpp"
#include "../Gameplay/Living.hpp"
#include "../Collision/CollisionHandler.hpp"
#include "../Input/InputHandler.hpp"
#include "../Gui/Gui.hpp"

StatePlaying::StatePlaying()
{
    GUI::Get().setPlayingState(this);
    m_type = StateType::Playing;
    // m_level = nullptr;
    m_loadFirst = "map_test.tmx";
}

StatePlaying::StatePlaying(const std::string& loadFirst)
{
    GUI::Get().setPlayingState(this);
    m_type = StateType::Playing;
    // m_level = nullptr;
    m_loadFirst = loadFirst;
}

void StatePlaying::init()
{
    setLevel(m_loadFirst, true);
}

void StatePlaying::update(float deltaTime)
{
    if (!m_considered)
    {
        setLevel(m_consider, false);
        m_considered = true;
    }

    m_level.update(deltaTime);
}

void StatePlaying::leave()
{
}

void StatePlaying::setLevel(const std::string& level, bool first)
{
    // if (m_level)
        // m_level->leave();
    // m_level.reset(new Level());
    // m_level->init(level, first);

    if (!first)
        m_level.leave();
    m_level = Level();
    m_level.init(level, first);
}

void StatePlaying::begForLevel(const std::string& level)
{
    m_consider = level;
    m_considered = false;
}