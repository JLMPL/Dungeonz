#include "IndicationHandler.hpp"
#include "Renderer.hpp"

void IndicationHandler::init()
{
}

void IndicationHandler::update(float deltaTime)
{
    if (!m_inds.empty())
    for (auto i = m_inds.begin(); i != m_inds.end();)
    {
        if ((*i).transparency <= 0)
            i = m_inds.erase(i);
        else i++;
    }

    for (int i = 0; i < m_inds.size(); i++)
    {
        float& opq = m_inds[i].transparency;
        opq -= 250 * deltaTime;
        
        if (opq <= 1) opq = 0;

        m_inds[i].color.a = opq;
        m_inds[i].text.setColor(m_inds[i].color);
        m_inds[i].text.move(0, -25 * deltaTime);
    }

    for (int i = 0; i < m_inds.size(); i++)
    {
        m_inds[i].draw();
    }
}

void IndicationHandler::addIndication(const std::string& message, const sf::Color& col, const vec2f& pos)
{
    m_inds.push_back(Indication(message, col, pos));
}
