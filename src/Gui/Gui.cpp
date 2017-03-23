#include "Gui.hpp"
#include "../Core/Game.hpp"
#include "../Core/Screen.hpp"
#include "../Resource/FontCache.hpp"
#include "../Resource/TextureCache.hpp"
#include "../Render/Renderer.hpp"
#include "../Gameplay/Living.hpp"
#include "../Input/InputHandler.hpp"
#include "../GameState/StatePlaying.hpp"
#include "../GameState/States.hpp"

constexpr int g_BookWidth = 256*1.5;
constexpr int g_BookHeight = 512;

void GUI::init()
{
    m_mode = GUIMode::Off;
    m_focusLabel.setFont(*FontCache::Get().getFont("Monaco_Linux.ttf"));
    m_focusLabel.setCharacterSize(10);

    m_sight.setTexture(*TextureCache::Get().getTexture("sight.png"));

    m_health.init({128,10}, {192,0,0});
    m_magicka.init({128,10}, {0,0,192});

    m_focusHealth.init({32,4}, {192,0,0});

    m_bookBack.setTexture(*TextureCache::Get().getTexture("page.png"));
    m_bookPos = vec2i(Screen::Get().halfWidth - g_BookWidth/2, Screen::Get().halfHeight - g_BookHeight/2);

    m_bookText.setFont(*FontCache::Get().getFont("HarabaraHand.ttf"));
    m_bookText.setCharacterSize(21);
    m_bookText.setFillColor({0,0,0});

    m_spellbook.setExitFunction(
    [&]()
    {
        m_mode = GUIMode::Off;
        m_target->setBusy(false);
    });

    m_deathSentence.setFont(*FontCache::Get().getFont("BLKCHCRY.ttf"));
    m_deathSentence.setCharacterSize(48);
    m_deathSentence.setString("It's over");
    m_deathSentence.setOrigin(static_cast<int>(m_deathSentence.getLocalBounds().width/2),
                              static_cast<int>(m_deathSentence.getLocalBounds().height/2));

    m_deathFade.setSize({Screen::Get().width, Screen::Get().height});
    m_deathFade.setFillColor({0,0,0,128});

    m_ginv.init(Screen::Get().width, Screen::Get().height);
}

void GUI::update(float deltaTime)
{
    m_camera = Renderer::Get().getCameraPos();
    m_sight.setPosition(m_camera.getSfVecf());
    // Renderer::Get().submitForeground(&m_sight);

    switch (m_mode)
    {
        case GUIMode::Off:
        {
            if (InputHandler::Get().isInv() and m_timer.getElapsedTime().asMilliseconds() > 200)
            {
                m_mode = GUIMode::Inv;
                m_target->setBusy(true);
                m_timer.restart();
            }

            if (InputHandler::Get().isSpellbook() and m_timer.getElapsedTime().asMilliseconds() > 200)
            {
                m_mode = GUIMode::Spellbook;
                m_target->setBusy(true);
                m_timer.restart();
            }

            if (m_showLabel)
            {
                Renderer::Get().submitOverlay(&m_focusLabel);
                m_showLabel = false;

                if (m_showHealthbar)
                {
                    m_focusHealth.update();
                    m_showHealthbar = false;
                }
            }

            m_centerLabel.setPosition(m_camera);
            m_centerLabel.update(deltaTime);
        }
        break;
        case GUIMode::Inv:
        {
            if (InputHandler::Get().isInv() or InputHandler::Get().isEscape())
            if (m_timer.getElapsedTime().asMilliseconds() > 200)
            {
                m_mode = GUIMode::Off;
                m_target->setBusy(false);
                m_timer.restart();
            }

            m_ginv.setPosition(m_camera);
            m_ginv.update();

            m_centerLabel.setPosition(m_camera);
            m_centerLabel.update(deltaTime);
        }
        break;
        case GUIMode::Loot:
        {
            if (InputHandler::Get().isInv() or InputHandler::Get().isEscape())
            if (m_timer.getElapsedTime().asMilliseconds() > 200)
            {
                m_mode = GUIMode::Off;
                m_target->setBusy(false);
                m_timer.restart();
            }

            m_gloot.update();

            m_centerLabel.setPosition(m_camera);
            m_centerLabel.update(deltaTime);
        }
        break;
        case GUIMode::Read:
        {
            if (InputHandler::Get().isInv() or InputHandler::Get().isEscape())
            if (m_timer.getElapsedTime().asMilliseconds() > 200)
            {
                m_mode = GUIMode::Inv;
                m_timer.restart();
            }

            vec2i pos = m_camera + m_bookPos;
            m_bookBack.setPosition(pos.getSfVecf());

            vec2i text_pos = m_camera + m_bookPos + vec2f(32,32);
            m_bookText.setPosition(text_pos.getSfVecf());

            Renderer::Get().submitOverlay(&m_bookBack);
            Renderer::Get().submitOverlay(&m_bookText);
        }
        break;
        case GUIMode::Spellbook:
        {
            if (InputHandler::Get().isInv() or InputHandler::Get().isEscape())
            if (m_timer.getElapsedTime().asMilliseconds() > 200)
            {
                m_mode = GUIMode::Off;
                m_target->setBusy(false);
                m_timer.restart();
            }

            m_spellbook.setPosition(m_camera);
            m_spellbook.update(deltaTime);
        }
        break;
        case GUIMode::Death:
        {   
            m_deathTimer += (deltaTime /2);
            float howmuch = lerp(0, 255, m_deathTimer);

            if (howmuch < 0) howmuch = 0;
            if (howmuch > 255) howmuch = 255;

            m_deathFade.setFillColor({0,0,0, howmuch});
            m_deathSentence.setFillColor({255, 255 - howmuch, 255 - howmuch, 255});

            m_deathSentence.setPosition(m_camera.x + Screen::Get().halfWidth,
                                       (m_camera.y - 32) + Screen::Get().halfHeight);
            m_deathFade.setPosition(m_camera.getSfVecf());

            Renderer::Get().submitOverlay(&m_deathFade);
            Renderer::Get().submitOverlay(&m_deathSentence);

            if (howmuch >= 254)
            {
                howmuch = 0;
                m_backToMenuFunc();
                m_mode = GUIMode::Off;
                m_deathTimer = 0;
            }
        }
        break;
    }

    if (m_mode != GUIMode::Inv and
        m_mode != GUIMode::Read and
        m_mode != GUIMode::Death)
    {
        m_health.setMaxValue(m_target->getAttribute(Attribute::Health));
        m_health.setValue(m_target->getAttribute(Attribute::Hp));
        m_health.setPosition(m_camera + vec2i(5, Screen::Get().height -30));
        m_health.update();

        m_magicka.setMaxValue(m_target->getAttribute(Attribute::Magicka));
        m_magicka.setValue(m_target->getAttribute(Attribute::Mp));
        m_magicka.setPosition(m_camera + vec2i(5, Screen::Get().height -15));
        m_magicka.update();
    }
}

void GUI::goLoot(Inventory* inv, const vec2i& pos)
{
    m_mode = GUIMode::Loot;
    m_gloot.setInv(inv);
    m_gloot.setPosition(pos);
    m_gloot.reset();
    m_target->setBusy(true);
}

void GUI::goRead(const std::string& content)
{
    m_mode = GUIMode::Read;
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

void GUI::addLabel(const std::string& label)
{
    m_centerLabel.addLabel(label);
}

void GUI::goDead()
{
    m_mode = GUIMode::Death;
}   

void GUI::setTarget(Living* living)
{
    m_target = living;
    m_ginv.setInv(&m_target->accessInv());
    m_ginv.setTarget(m_target);
    m_gloot.setTargetInv(&m_target->accessInv());
    m_spellbook.setTarget(m_target);
}

Living* GUI::getTarget()
{
    return m_target;
}

void GUI::setPlayingState(StatePlaying* state)
{
    m_playingState = state;
}

void GUI::begForLevel(const std::string& level)
{
    m_playingState->begForLevel(level);
}

void GUI::setBackToMenuFunc(std::function<void ()> func)
{
    m_backToMenuFunc = func;
}