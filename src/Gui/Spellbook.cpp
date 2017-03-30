#include "Spellbook.hpp"
#include "../Core/Screen.hpp"
#include "../Gameplay/Spells.hpp"
#include "../Gameplay/Living.hpp"
#include "../Render/Renderer.hpp"
#include "../Resource/TextureCache.hpp"
#include "../Input/InputHandler.hpp"

constexpr int g_spellBookWidth = 256 * 1.5;
constexpr int g_spellBookHeight = Spell::NumSpells * 32 + 10;

Spellbook::Spellbook()
{
    m_background.setSize({g_spellBookWidth, g_spellBookHeight});
    m_background.setFillColor({0x20,0x20,0x20});
    m_background.setPosition({Screen::Get().halfWidth - g_spellBookWidth/2,
                              Screen::Get().halfHeight - g_spellBookHeight/2});

    m_options.push_back(SpellOption("fire_icon.png", "Fireball\nExplodes in da face!"));
    m_options.push_back(SpellOption("ice_icon.png", "Frostbite\nFreezes the shit out of enemies!"));
    // m_options.push_back(SpellOption("fire_icon.png", "Speed\nLet's you run like a horny rabbit!"));
    m_options.push_back(SpellOption("light_icon.png", "Lightning\nDoes it get more badass?"));
    m_options.push_back(SpellOption("heal_icon.png", "Heal\nBetter than touching yourself."));

    m_selection.setSize({g_spellBookWidth -12, 32});
    m_selection.setFillColor({0,0,0,0});
    m_selection.setOutlineThickness(1);
    m_selection.setOutlineColor({0x40,0x40,0x40});
}

void Spellbook::update(float deltaTime)
{
    if (InputHandler::Get().isUp() and m_timer.getElapsedTime().asMilliseconds() > 150)
    {
        if (m_chosen > 0)
            m_chosen--;
        m_timer.restart();
    }
    else if (InputHandler::Get().isDown() and m_timer.getElapsedTime().asMilliseconds() > 150)
    {
        if (m_chosen < Spell::NumSpells -1)
            m_chosen++;
        m_timer.restart();
    }
    else if (InputHandler::Get().isAction() and m_timer.getElapsedTime().asMilliseconds() > 150)
    {
        if (m_target->knowsSpell(m_chosen))
        {
            m_target->setReadySpell(m_chosen);
            m_exitFunction();
        }
        m_timer.restart();
    }

    vec2i pos = m_position + vec2i(Screen::Get().halfWidth - g_spellBookWidth/2,
                                   Screen::Get().halfHeight - g_spellBookHeight/2);
    m_background.setPosition(pos.getSfVecf());

    for (int i = 0; i < Spell::NumSpells; i++)
    {
        auto poz = pos + vec2i(5, i * 32 + 5);
        m_options[i].setPosition(poz);
        m_options[i].disable();

        if (i == m_chosen)
            m_selection.setPosition(poz.getSfVecf());

        if (m_target->knowsSpell(i))
            m_options[i].enable();
    }

    Renderer::Get().submitOverlay(&m_background);

    for (auto& i : m_options)
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

void Spellbook::setExitFunction(std::function<void ()> func)
{
    m_exitFunction = func;
}