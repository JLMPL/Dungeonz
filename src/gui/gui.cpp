#include "gui.hpp"
#include "../resource/font_cache.hpp"
#include "../resource/texture_cache.hpp"
#include "../render/renderer.hpp"
#include "../gameplay/living.hpp"
#include "../input/input_handler.hpp"

constexpr int _BookWidth = 256*1.5;
constexpr int _BookHeight = 512;

void GUI::init()
{
	m_mode = GUIMode::OFF;
	m_focusLabel.setFont(*FontCache::Get().getFont("data/Monaco_Linux.ttf"));
	m_focusLabel.setCharacterSize(10);

	m_sight.setTexture(*TextureCache::Get().getTexture("data/sight.png"));

	m_health.init({128,10}, {192,0,0});
	m_magicka.init({128,10}, {0,0,192});

	m_focusHealth.init({32,4}, {192,0,0});

	m_bookBack.setSize({_BookWidth, _BookHeight});
	m_bookBack.setFillColor({0x20,0x20,0x20});
	m_bookPos = vec2i(400 - _BookWidth/2, 300 - _BookHeight/2);

	m_bookText.setFont(*FontCache::Get().getFont("data/Monaco_Linux.ttf"));
	m_bookText.setCharacterSize(16);
}

void GUI::update()
{
	m_camera = Renderer::Get().getCameraPos();
	m_sight.setPosition(m_camera.getSfVecf());
	// Renderer::Get().submitOverlay(RenderData(&m_sight), RenderAttribute::OVERLAY);

	switch(m_mode)
	{
		case GUIMode::OFF:
		{
			if(InputHandler::Get().isInv() and m_timer.getElapsedTime().asMilliseconds() > 200)
			{
				m_mode = GUIMode::INV;
				m_target->setBusy(true);
				m_timer.restart();
			}

			if(m_showLabel)
			{
				Renderer::Get().submitOverlay(&m_focusLabel);
				m_showLabel = false;

				if(m_showHealthbar)
				{
					m_focusHealth.update();
					m_showHealthbar = false;
				}
			}
		}
		break;
		case GUIMode::INV:
		{
			if(InputHandler::Get().isInv() and m_timer.getElapsedTime().asMilliseconds() > 200)
			{
				m_mode = GUIMode::OFF;
				m_target->setBusy(false);
				m_timer.restart();
			}

			m_ginv.setPosition(m_camera);
			m_ginv.update();
		}
		break;
		case GUIMode::LOOT:
		{
			if(InputHandler::Get().isInv() and m_timer.getElapsedTime().asMilliseconds() > 200)
			{
				m_mode = GUIMode::OFF;
				m_target->setBusy(false);
				m_timer.restart();
				printf("exit\n");
			}

			m_gloot.update();
		}
		break;
		case GUIMode::READ:
		{
			if(InputHandler::Get().isInv())
			{
				m_mode = GUIMode::OFF;
			}

			vec2i pos = m_camera + m_bookPos;
			m_bookBack.setPosition(pos.getSfVecf());

			vec2i text_pos = m_camera + m_bookPos + vec2f(32,32);
			m_bookText.setPosition(text_pos.getSfVecf());

			Renderer::Get().submitOverlay(&m_bookBack);
			Renderer::Get().submitOverlay(&m_bookText);
		}
		break;
	}

	if(m_mode != GUIMode::INV and m_mode != GUIMode::READ)
	{
		m_health.setMaxValue(m_target->getAttribute(Attribute::HEALTH));
		m_health.setValue(m_target->getAttribute(Attribute::HP));
		m_health.setPosition(m_camera + vec2i(5, 600-30));
		m_health.update();

		m_magicka.setMaxValue(m_target->getAttribute(Attribute::MAGICKA));
		m_magicka.setValue(m_target->getAttribute(Attribute::MP));
		m_magicka.setPosition(m_camera + vec2i(5, 600-15));
		m_magicka.update();
	}
}

void GUI::goLoot(Inventory* inv, const vec2i& pos)
{
	m_mode = GUIMode::LOOT;
	m_gloot.setInv(inv);
	m_gloot.setPosition(pos);
	m_gloot.reset();
	m_target->setBusy(true);
}

void GUI::goRead(const std::string& content)
{
	m_mode = GUIMode::READ;
	m_bookText.setString(content);
}

void GUI::showFocusHealthbar(int val, int max, const vec2i& pos)
{
	m_showHealthbar = true;
	m_focusHealth.setValue(val);
	m_focusHealth.setMaxValue(max);
	m_focusHealth.setPosition({pos.x - 16, pos.y - 12});
}

void GUI::setFocusLabel(const std::string& label, const vec2i& pos)
{
	m_focusLabel.setString(label);
	m_focusLabel.setOrigin(static_cast<int>(m_focusLabel.getLocalBounds().width/2), 
						   static_cast<int>(m_focusLabel.getLocalBounds().height));
	m_focusLabel.setPosition(pos.getSfVecf());
	m_showLabel = true;
}

void GUI::setTarget(Living* living)
{
	m_target = living;
	m_ginv.setInv(&m_target->accessInv());
	m_ginv.setTarget(m_target);
	m_gloot.setTargetInv(&m_target->accessInv());
}

Living* GUI::getTarget()
{
	return m_target;
}