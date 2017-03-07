#include "CenterLabel.hpp"
#include "../Core/Screen.hpp"
#include "../Resource/FontCache.hpp"
#include "../Render/Renderer.hpp"

CenterLabel::CenterLabel()
{
	m_label.setFont(*FontCache::Get().getFont("Monaco_Linux.ttf"));
	m_label.setCharacterSize(20);
	m_label.setOutlineThickness(1);
	m_label.setOutlineColor({0x00,0x00,0x00});
	m_label.setFillColor({0xff,0xff,0xff});

	m_label.setString("Test String Shows Up");
	m_label.setOrigin({static_cast<int>(m_label.getLocalBounds().width/2),
					   static_cast<int>(m_label.getLocalBounds().height/2)});
}

void CenterLabel::update(float deltaTime)
{
	m_timer += 1000 * deltaTime;

	if (!m_waitingLabels.empty())
	{
		m_label.setString(m_waitingLabels.front());
		m_label.setOrigin({static_cast<int>(m_label.getLocalBounds().width/2),
						   static_cast<int>(m_label.getLocalBounds().height/2)});
		m_label.setPosition(vec2i(m_position + vec2i(400, static_cast<int>(600 /3))).getSfVecf());
		Renderer::Get().submitOverlay(&m_label);

		if (m_timer >= 2000)
		{
			m_waitingLabels.pop_front();
			m_timer = 0;
		}
	}
}

void CenterLabel::addLabel(const std::string& label)
{
	m_waitingLabels.push_back(label);
	m_timer = 0;
}

void CenterLabel::setPosition(const vec2i& pos)
{
	m_position = pos;
}