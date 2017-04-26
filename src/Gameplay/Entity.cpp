#include "Entity.hpp"

Entity::~Entity()
{
}

void Entity::update(float deltaTime)
{

}

void Entity::move(vec2f offset)
{
    // m_pos += offset;
    m_box->rect.x += offset.x;
    m_box->rect.y += offset.y;
}

void Entity::destroy()
{
    m_destroy = true;
}

void Entity::setId(uint id)
{
    m_id = id;
}

void Entity::setCode(const std::string& code)
{
    m_code = code;
}

void Entity::setLevel(Level* level)
{
    m_level = level;
}

void Entity::setPosition(const vec2f& pos)
{
    //m_pos = pos;
    if (m_box)
    {
        m_box->rect.x = pos.x;
        m_box->rect.y = pos.y;
    }
}

uint Entity::getId() const
{
    return m_id;
}

const std::string& Entity::getCode() const
{
    return m_code;
}

Entity::Type Entity::getType() const
{
    return m_type;
}

vec2f Entity::getPosition() const
{
    //return m_pos;
    if (m_box)
        return vec2f(m_box->rect.x, m_box->rect.y);
}

Level* Entity::getLevel() const
{
    return m_level;
}

vec2i Entity::getFakePos() const
{
    return vec2i(m_box->rect.x + m_box->rect.w/2,
                 m_box->rect.y + m_box->rect.h/2);
}

bool Entity::isDestroyed()
{
    return m_destroy;
}