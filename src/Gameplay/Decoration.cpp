#include "Decoration.hpp"
#include "../Resource/AnimationCache.hpp"

Decoration::Decoration()
{
}

void Decoration::init(const std::string& path)
{
    m_sprite.loadFromFile(path);
}

void Decoration::update(float deltaTime)
{
    m_sprite.update(deltaTime);
}

void Decoration::setPosition(const vec2f& pos)
{
    m_sprite.setPosition(pos);
}
