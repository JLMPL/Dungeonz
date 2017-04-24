#include "StateScrolling.hpp"
#include "../Resource/FontCache.hpp"
#include "../Render/Renderer.hpp"
#include "../Core/Screen.hpp"
#include <SFML/Window/Keyboard.hpp>

constexpr int g_wrap = 48;

StateScrolling::StateScrolling(bool laste)
{
    m_laste = laste;
    if (!m_laste)
        m_type = Type::Scrolling;
    else
        m_type = Type::ScrollingEnd;
}

void StateScrolling::init()
{
    m_text.setFont(*FontCache::Get().getFont("Monaco_Linux.ttf"));
    m_text.setCharacterSize(24);
    m_text.setFillColor(sf::Color::White);

    std::string content;
    std::string fixed;

    if (!m_laste)
        content = "Long time ago in a land Far Far Away there was a kingdom. It was ruled handsomely by a wise and brave king. But who would've guessed an evil poisoned the land. Ancient creature from the depths of the abyss. It was so powerful in a flick of a wrist created and army of magical creatures that swallowed the earth. The wise king had promised \"Whoever kills that damned bastard gets my throne and all my three daugters!!!\" Daugters were pretty and throne was big. Many have tried and among them... one who's story was about to begin.";
    else 
        content = "And so did the story end. Hero defeated the demon and brought peace to the land. King as promised made him the new ruler of the land. Our hero married neither of the princesess... He found himself a better option. But that's totally different story. Now everyone is happy and all. Yeah that would be all. Thanks for wasting your precious time playing this game. Bye.";

    for (std::size_t i = 0; i < content.size(); i++)
    {
        if (i % g_wrap == 1 and content[i] == ' ')
        {/*SKIP THIS SUCKER*/}
        else
            fixed += content[i];

        if (i != 0)
        if (i % g_wrap == 0)
            fixed += "\n";
    }
    
    m_text.setString(fixed);
    m_text.setOrigin(static_cast<int>(m_text.getLocalBounds().width/2), static_cast<int>(m_text.getLocalBounds().height/2));
    m_text.setPosition({Screen::Get().halfWidth, Screen::Get().halfHeight});

    m_skip.setFont(*FontCache::Get().getFont("Monaco_Linux.ttf"));
    m_skip.setCharacterSize(10);
    m_skip.setString("Press 'Esc' To Skip.");
    m_skip.setOrigin(static_cast<int>(m_skip.getLocalBounds().width/2), static_cast<int>(m_skip.getLocalBounds().height/2));
    m_skip.setPosition({Screen::Get().halfWidth, Screen::Get().height - 48});

}

void StateScrolling::update(float deltaTime)
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
    {
        m_exitFunction();
    }
    
    Renderer::Get().submitOverlay(&m_text);
    Renderer::Get().submitOverlay(&m_skip);
}

void StateScrolling::leave()
{
}
