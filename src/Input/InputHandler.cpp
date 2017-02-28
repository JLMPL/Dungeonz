#include "InputHandler.hpp"

void InputHandler::init()
{
	m_keys[KeyBind::UP]        = sf::Keyboard::Up;
	m_keys[KeyBind::DOWN]      = sf::Keyboard::Down;
	m_keys[KeyBind::LEFT]      = sf::Keyboard::Left;
	m_keys[KeyBind::RIGHT]     = sf::Keyboard::Right;
	m_keys[KeyBind::ACTION]    = sf::Keyboard::E;
	m_keys[KeyBind::ATTACK]    = sf::Keyboard::F;
	m_keys[KeyBind::INV]       = sf::Keyboard::Tab;
	m_keys[KeyBind::RUN]	   = sf::Keyboard::LShift;
	m_keys[KeyBind::CAST]	   = sf::Keyboard::R;
	m_keys[KeyBind::SPELLBOOK] = sf::Keyboard::S;
}

bool InputHandler::isKeyPressed(sf::Keyboard::Key key)
{
	return sf::Keyboard::isKeyPressed(key);
}

bool InputHandler::isAnyKeyPressed()
{
	if (sf::Keyboard::isKeyPressed(m_keys[KeyBind::UP]) or
		sf::Keyboard::isKeyPressed(m_keys[KeyBind::DOWN]) or
		sf::Keyboard::isKeyPressed(m_keys[KeyBind::LEFT]) or
		sf::Keyboard::isKeyPressed(m_keys[KeyBind::RIGHT]) or
		sf::Keyboard::isKeyPressed(m_keys[KeyBind::ACTION]) or
		sf::Keyboard::isKeyPressed(m_keys[KeyBind::ATTACK]) or
		sf::Keyboard::isKeyPressed(m_keys[KeyBind::INV]) or
		sf::Keyboard::isKeyPressed(m_keys[KeyBind::CAST]) or
		sf::Keyboard::isKeyPressed(m_keys[KeyBind::SPELLBOOK]))
	{
		return true;
	}
	else return false;
}

void InputHandler::bindKey(KeyBind bind, sf::Keyboard::Key key)
{
	m_keys[bind] = key;
}

bool InputHandler::isUp()
{
	return sf::Keyboard::isKeyPressed(m_keys[KeyBind::UP]);
}

bool InputHandler::isDown()
{
	return sf::Keyboard::isKeyPressed(m_keys[KeyBind::DOWN]);
}

bool InputHandler::isLeft()
{
	return sf::Keyboard::isKeyPressed(m_keys[KeyBind::LEFT]);
}

bool InputHandler::isRight()
{
	return sf::Keyboard::isKeyPressed(m_keys[KeyBind::RIGHT]);
}

bool InputHandler::isAction()
{
	return sf::Keyboard::isKeyPressed(m_keys[KeyBind::ACTION]);
}

bool InputHandler::isAttack()
{
	return sf::Keyboard::isKeyPressed(m_keys[KeyBind::ATTACK]);
}

bool InputHandler::isInv()
{
	return sf::Keyboard::isKeyPressed(m_keys[KeyBind::INV]);
}

bool InputHandler::isRun()
{
	return sf::Keyboard::isKeyPressed(m_keys[KeyBind::RUN]);
}

bool InputHandler::isCast()
{
	return sf::Keyboard::isKeyPressed(m_keys[KeyBind::CAST]);
}

bool InputHandler::isSpellbook()
{
	return sf::Keyboard::isKeyPressed(m_keys[KeyBind::SPELLBOOK]);
}