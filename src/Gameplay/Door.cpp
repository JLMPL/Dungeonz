#include "Door.hpp"
#include "Inventory.hpp"
#include "../Collision/CollisionHandler.hpp"
#include "../Render/AnimatedSprite.hpp"
#include "../Render/IndicationHandler.hpp"
#include "../Resource/AnimationCache.hpp"

Door::Door()
{
    m_type = Entity::Type::Door;

    m_sprite = Sprite::Ptr(new AnimatedSprite());
    m_sprite->loadFromFile("door_idle.ani");
    m_sprite->setOrigin({16,32});

    m_box = Box::Ptr(new Box());
    m_box->rect = Rectf(736,350,32,32);
    m_box->type = Box::Type::Static;

    CollisionHandler::Get().addBody(m_box);
}

void Door::update(float deltaTime)
{
    m_sprite->setPosition({m_box->rect.x + m_box->rect.w/2, m_box->rect.y + m_box->rect.h});
    m_sprite->update(deltaTime);
}

void Door::tryOpening(Inventory* inv)
{
    vec2f the_pos = vec2f(m_box->rect.x + m_box->rect.w/2, m_box->rect.y + m_box->rect.h/2);
    if (inv->hasItem(m_requiredKey) and !m_isOpen)
    {
        m_isOpen = true;
        m_box->enabled = false;
        inv->removeItem(m_requiredKey);

        m_sprite->setAnimation(AnimationCache::Get().getAnimation("door_open.ani"));
        IndicationHandler::Get().addIndication("Key used", sf::Color(0,255,0), the_pos + vec2f(0,-50));
    }
    else
    {
        if (!m_isOpen)
            IndicationHandler::Get().addIndication("Locked", sf::Color(255,0,0), the_pos + vec2f(0,-50));
    }
}

void Door::open()
{
    m_isOpen = true;
    m_box->enabled = false;
    m_sprite->setAnimation(AnimationCache::Get().getAnimation("door_open.ani"));
}

void Door::setRequiredItem(const std::string& code)
{
    m_requiredKey = code;
}