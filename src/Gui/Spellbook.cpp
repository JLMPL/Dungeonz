#include "Spellbook.hpp"
#include "../Gameplay/Spells.hpp"
#include "../Render/Renderer.hpp"
#include "../Resource/TextureCache.hpp"

constexpr int g_spellBookWidth = 256 * 1.5;
constexpr int g_spellBookHeight = Spell::NUM_SPELLS * 32 + 10;

Spellbook::Spellbook()
{
	m_background.setSize({g_spellBookWidth, g_spellBookHeight});
	m_background.setFillColor({0x20,0x20,0x20});
	m_background.setPosition({400 - g_spellBookWidth/2, 300 - g_spellBookHeight/2});

	for(int i = 0; i < Spell::NUM_SPELLS; i++)
	{
		m_options.push_back(SpellOption("fire_icon.png", "Test Spell\nThis another line has nice potential!"));
	}

	m_selection.setSize({g_spellBookWidth -12, 32});
	m_selection.setFillColor({0,0,0,0});
	m_selection.setOutlineThickness(1);
	m_selection.setOutlineColor({0x40,0x40,0x40});
}

void Spellbook::update(float deltaTime)
{
	vec2i pos = m_position + vec2i(400 - g_spellBookWidth/2, 300 - g_spellBookHeight/2);
	m_background.setPosition(pos.getSfVecf());

	for(int i = 0; i < Spell::NUM_SPELLS; i++)
	{
		auto poz = pos + vec2i(5, i * 32 + 5);
		m_options[i].setPosition(poz);

		if(i == m_chosen)
		{
			m_selection.setPosition(poz.getSfVecf());
		}
	}

	Renderer::Get().submitOverlay(&m_background);

	for(auto& i : m_options)
		i.draw();

	Renderer::Get().submitOverlay(&m_selection);
}

void Spellbook::setPosition(const vec2i& pos)
{
	m_position = pos;
}

void Spellbook::setTarget(Living* target)
{
	m_target = target;
}
