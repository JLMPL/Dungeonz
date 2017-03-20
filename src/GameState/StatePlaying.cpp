#include "StatePlaying.hpp"
#include "../Gameplay/Living.hpp"
#include "../Collision/CollisionHandler.hpp"
#include "../Input/InputHandler.hpp"
#include "../Gui/Gui.hpp"

StatePlaying::StatePlaying()
{
	GUI::Get().setPlayingState(this);
	m_type = StateType::Playing;
	m_level = nullptr;
}

void StatePlaying::init()
{
	if (m_level)
		m_level->leave();
	m_level.reset(new Level());
	m_level->init("map_test.tmx", true);
}

void StatePlaying::update(float deltaTime)
{
	if (!m_considered)
	{
		setLevel(m_consider);
		m_considered = true;
	}

	m_level->update(deltaTime);
}

void StatePlaying::leave()
{
}

void StatePlaying::setLevel(const std::string& level)
{
	m_level->leave();
	m_level.reset(new Level());
	m_level->init(level, false);
}

void StatePlaying::begForLevel(const std::string& level)
{
	m_consider = level;
	m_considered = false;
}