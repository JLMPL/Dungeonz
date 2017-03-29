#include "CenterLabel.hpp"
#include "../Core/Screen.hpp"
#include "../Resource/FontCache.hpp"
#include "../Render/Renderer.hpp"

CenterLabel::CenterLabel()
{
    m_label.setFont(*FontCache::Get().getFont("Monaco_Linux.ttf"));
    m_label.setCharacterSize(20);
    m_label.setOutlineThickness(0);
    m_label.setOutlineColor({0x00,0x00,0x00});
    m_label.setFillColor({0xff,0xff,0xff});

    m_label.setString("Test String Shows Up");
    m_label.setOrigin({static_cast<int>(m_label.getLocalBounds().width/2),
                       static_cast<int>(m_label.getLocalBounds().height/2)});

    m_vertices[0] = sf::Vertex(sf::Vector2f(0,0), sf::Color(0,0,0,0));
    m_vertices[1] = sf::Vertex(sf::Vector2f(0,32), sf::Color(0,0,0,0));

    m_vertices[2] = sf::Vertex(sf::Vector2f(64,0), sf::Color(0,0,0,192));
    m_vertices[3] = sf::Vertex(sf::Vector2f(64,32), sf::Color(0,0,0,192));

    m_vertices[4] = sf::Vertex(sf::Vector2f(320,0), sf::Color(0,0,0,192));
    m_vertices[5] = sf::Vertex(sf::Vector2f(320,32), sf::Color(0,0,0,192));

    m_vertices[6] = sf::Vertex(sf::Vector2f(384,0), sf::Color(0,0,0,0));
    m_vertices[7] = sf::Vertex(sf::Vector2f(384,32), sf::Color(0,0,0,0));
}

void CenterLabel::update(float deltaTime)
{
    m_timer += 1000 * deltaTime;

    if (!m_waitingLabels.empty())
    {
        m_label.setString(m_waitingLabels.front());
        m_label.setOrigin({static_cast<int>(m_label.getLocalBounds().width/2),
                           static_cast<int>(m_label.getLocalBounds().height/2)});
        m_label.setPosition(vec2i(m_position + vec2i(Screen::Get().halfWidth,
                                  static_cast<int>(Screen::Get().height /3))).getSfVecf());
        Renderer::Get().submitOverlay(&m_label);
        Renderer::Get().submitPrimitive(m_vertices, 8, sf::TriangleStrip);

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

    vec2f backgroundPos = m_position + vec2f(Screen::Get().halfWidth - 192, Screen::Get().height/3 - 10);

    m_vertices[0].position = sf::Vector2f(0,0) + backgroundPos.getSfVecf();
    m_vertices[1].position = sf::Vector2f(0,32) + backgroundPos.getSfVecf();

    m_vertices[2].position = sf::Vector2f(64,0) + backgroundPos.getSfVecf();
    m_vertices[3].position = sf::Vector2f(64,32) + backgroundPos.getSfVecf();

    m_vertices[4].position = sf::Vector2f(320,0) + backgroundPos.getSfVecf();
    m_vertices[5].position = sf::Vector2f(320,32) + backgroundPos.getSfVecf();

    m_vertices[6].position = sf::Vector2f(384,0) + backgroundPos.getSfVecf();
    m_vertices[7].position = sf::Vector2f(384,32) + backgroundPos.getSfVecf();
}