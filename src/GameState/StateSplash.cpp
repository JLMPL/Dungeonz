#include "StateSplash.hpp"
#include "../Resource/TextureCache.hpp"
#include "../Render/Renderer.hpp"
#include "../Core/Vec2.hpp"

StateSplash::StateSplash()
{
}

void StateSplash::init()
{
	m_timer.restart();

	m_sfmlLogo.setTexture(*TextureCache::Get().getTexture("sfml-logo-small.png"));
	m_sfmlLogo.setOrigin(m_sfmlLogo.getLocalBounds().width/2, m_sfmlLogo.getLocalBounds().height/2);
	m_sfmlLogo.setPosition({400,250});

	Renderer::Get().setCameraPos({400,300});
}

void StateSplash::update(float deltaTime)
{
	switch (m_stage)
	{
		case 0:
		{
			float color = lerp(0, 255, m_timer.getElapsedTime().asSeconds());
			if (color > 255) color = 255;

			m_sfmlLogo.setColor({255,255,255, static_cast<int>(color)});

			if (m_timer.getElapsedTime().asSeconds() > 1)
			{
				m_stage++;
				m_timer.restart();
			}
		}
		break;
		case 1:
		{
			if (m_timer.getElapsedTime().asSeconds() >= 1)
			{
				m_stage++;
				m_timer.restart();
			}
		}
		break;
		case 2:
		{
			float color = lerp(255, 0, m_timer.getElapsedTime().asSeconds());
			if (color < 0) color = 0;

			m_sfmlLogo.setColor({255,255,255, static_cast<int>(color)});

			if (m_timer.getElapsedTime().asSeconds() > 1)
			{
				m_stage++;
				m_timer.restart();
			}
		}
		break;
		case 3:
		{
			leave();
		}
		break;
	}

	Renderer::Get().submitBackground(&m_sfmlLogo);
}

void StateSplash::leave()
{
	m_exitFunction();
}
