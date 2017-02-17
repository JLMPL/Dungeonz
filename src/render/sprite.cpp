#include "sprite.hpp"
#include "renderer.hpp"
#include "../resource/texture_cache.hpp"

void Sprite::loadFromFile(const std::string& path)
{
	m_sprite.setTexture(*TextureCache::Get().getTexture(path));
}

void Sprite::setSize(vec2i size)
{
}

void Sprite::setRect(Recti rect)
{
	m_sprite.setTextureRect({rect.x, rect.y, rect.w, rect.h});
}

void Sprite::setOrigin(vec2i origin)
{
	m_sprite.setOrigin(origin.getSfVecf());
}

void Sprite::setPosition(const vec2i& pos)
{
	m_sprite.setPosition(pos.getSfVecf());
}

void Sprite::setDirection(Direction_t dir)
{
	m_direction = dir;
}

void Sprite::draw()
{
	Renderer::Get().submitSorted(&m_sprite);
}

vec2i Sprite::getPosition() const
{
	return vec2i(m_sprite.getPosition().x, m_sprite.getPosition().y);
}
