#include "Bar.hpp"
#include "Renderer.hpp"
#include "../Resource/FontCache.hpp"

#ifdef _WIN32
#include "../Core/MinGWSucks.hpp"
#endif

void Bar::init(const vec2i& size, const sf::Color& color)
{
	m_bar.setSize(size.getSfVecf());
	m_bar.setFillColor(color);

	m_bcg.setSize(size.getSfVecf());
	m_bcg.setFillColor({0,0,0});
	m_bcg.setOutlineThickness(1);
	m_bcg.setOutlineColor({0,0,0});

	m_stats.setFont(*FontCache::Get().getFont("Monaco_Linux.ttf"));
	m_stats.setCharacterSize(10);
	m_stats.setOutlineThickness(1);
	m_stats.setOutlineColor({0,0,0});
}

void Bar::update()
{
	if (m_value > m_max)
		m_value = m_max;
	else if (m_value < 0)
		m_value = 0;

	float factor = static_cast<float>(m_value) / static_cast<float>(m_max);

	m_bar.setScale(factor, 1);

	m_bcg.setPosition(m_position.getSfVecf());
	m_bar.setPosition(m_position.getSfVecf());

	Renderer::Get().submitOverlay(&m_bcg);
	Renderer::Get().submitOverlay(&m_bar);

	if (m_showStats)
	{
		m_stats.setString(std::to_string(m_value) + "/" + std::to_string(m_max));
		m_stats.setOrigin(static_cast<int>(m_stats.getLocalBounds().width/2), 
			 			  static_cast<int>(m_stats.getLocalBounds().height/2));
		m_stats.setPosition(m_bcg.getPosition().x + m_bcg.getLocalBounds().width/2,
							m_bcg.getPosition().y + m_bcg.getLocalBounds().height/2 -2);
		Renderer::Get().submitOverlay(&m_stats);
	}
}

void Bar::setPosition(const vec2i& pos)
{
	m_position = pos;
	m_bar.setPosition(pos.getSfVecf());
	m_bcg.setPosition(pos.getSfVecf());
}

void Bar::setMaxValue(int max)
{
	m_max = max;
}

void Bar::setValue(int val)
{
	m_value = val;
}

void Bar::setShowStats(bool show)
{
	m_showStats = show;
}

int Bar::getMaxValue()
{
	return m_max;
}

int Bar::getValue()
{
	return m_value;
}

vec2i Bar::getPosition()
{
	return m_position;
}