#include "StatePlaying.hpp"
#include "../Gameplay/Living.hpp"
#include "../Collision/CollisionHandler.hpp"
#include "../Input/InputHandler.hpp"

StatePlaying::StatePlaying()
{
}

void StatePlaying::init()
{
	m_level = std::unique_ptr<Level>(new Level());
	m_level->init("map_test.tmx");
}

void StatePlaying::update(float deltaTime)
{
	if (InputHandler::Get().isKeyPressed(sf::Keyboard::P))
		setLevel("second_test.tmx");

	m_level->update(deltaTime);
}

void StatePlaying::leave()
{
}

void StatePlaying::setLevel(const std::string& level)
{
	m_level.reset(new Level());
	m_level->init(level);
}