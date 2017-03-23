#include "InputHandler.hpp"

void InputHandler::init()
{
    m_keys[KeyBind::Up]        = sf::Keyboard::Up;
    m_keys[KeyBind::Down]      = sf::Keyboard::Down;
    m_keys[KeyBind::Left]      = sf::Keyboard::Left;
    m_keys[KeyBind::Right]     = sf::Keyboard::Right;
    m_keys[KeyBind::Action]    = sf::Keyboard::E;
    m_keys[KeyBind::Attack]    = sf::Keyboard::F;
    m_keys[KeyBind::Inv]       = sf::Keyboard::Tab;
    m_keys[KeyBind::Run]       = sf::Keyboard::LShift;
    m_keys[KeyBind::Cast]      = sf::Keyboard::R;
    m_keys[KeyBind::Spellz]    = sf::Keyboard::S;
    m_keys[KeyBind::Escape]    = sf::Keyboard::Escape;
    m_keys[KeyBind::Roll]      = sf::Keyboard::D;
    m_keys[KeyBind::Shoot]     = sf::Keyboard::W;
}

bool InputHandler::isKeyPressed(sf::Keyboard::Key key)
{
    return sf::Keyboard::isKeyPressed(key);
}

bool InputHandler::isAnyKeyPressed()
{
    if (sf::Keyboard::isKeyPressed(m_keys[KeyBind::Up])     or
        sf::Keyboard::isKeyPressed(m_keys[KeyBind::Down])   or
        sf::Keyboard::isKeyPressed(m_keys[KeyBind::Left])   or
        sf::Keyboard::isKeyPressed(m_keys[KeyBind::Right])  or
        sf::Keyboard::isKeyPressed(m_keys[KeyBind::Action]) or
        sf::Keyboard::isKeyPressed(m_keys[KeyBind::Attack]) or
        sf::Keyboard::isKeyPressed(m_keys[KeyBind::Inv])    or
        sf::Keyboard::isKeyPressed(m_keys[KeyBind::Cast])   or
        sf::Keyboard::isKeyPressed(m_keys[KeyBind::Spellz]) or
        sf::Keyboard::isKeyPressed(m_keys[KeyBind::Roll])   or
        sf::Keyboard::isKeyPressed(m_keys[KeyBind::Shoot]))
    {
        return true;
    }
    return false;
}

void InputHandler::bindKey(KeyBind bind, sf::Keyboard::Key key)
{
    m_keys[bind] = key;
}

bool InputHandler::isUp()
{
    return sf::Keyboard::isKeyPressed(m_keys[KeyBind::Up]);
}

bool InputHandler::isDown()
{
    return sf::Keyboard::isKeyPressed(m_keys[KeyBind::Down]);
}

bool InputHandler::isLeft()
{
    return sf::Keyboard::isKeyPressed(m_keys[KeyBind::Left]);
}

bool InputHandler::isRight()
{
    return sf::Keyboard::isKeyPressed(m_keys[KeyBind::Right]);
}

bool InputHandler::isAction()
{
    return sf::Keyboard::isKeyPressed(m_keys[KeyBind::Action]);
}

bool InputHandler::isAttack()
{
    return sf::Keyboard::isKeyPressed(m_keys[KeyBind::Attack]);
}

bool InputHandler::isInv()
{
    return sf::Keyboard::isKeyPressed(m_keys[KeyBind::Inv]);
}

bool InputHandler::isRun()
{
    return sf::Keyboard::isKeyPressed(m_keys[KeyBind::Run]);
}

bool InputHandler::isCast()
{
    return sf::Keyboard::isKeyPressed(m_keys[KeyBind::Cast]);
}

bool InputHandler::isSpellbook()
{
    return sf::Keyboard::isKeyPressed(m_keys[KeyBind::Spellz]);
}

bool InputHandler::isEscape()
{
    return sf::Keyboard::isKeyPressed(m_keys[KeyBind::Escape]);
}

bool InputHandler::isRoll()
{
    return sf::Keyboard::isKeyPressed(m_keys[KeyBind::Roll]);
}

bool InputHandler::isShoot()
{
    return sf::Keyboard::isKeyPressed(m_keys[KeyBind::Shoot]);
}