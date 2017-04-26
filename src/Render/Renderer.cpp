#include "Renderer.hpp"
#include "Sprite.hpp"
#include "../Core/Screen.hpp"
#include "../Core/Error.hpp"
#include "../Core/Rect.hpp"
#include "../Collision/CollisionAlgorithm.hpp"
#include <SFML/Graphics.hpp>
#include <algorithm>
#include <memory>

void Renderer::init(sf::RenderWindow* window)
{
    if (!window)
        ShowErrorBox("Failed to initialize renderer with window!");
    else
    {
        m_window = window;
        m_camera = sf::View(sf::Vector2f(0,0), sf::Vector2f(Screen::Get().width, Screen::Get().height));
    }
}

void Renderer::submitBackground(sf::CircleShape* data)
{
    m_backCircleData.push_back(data);
}

void Renderer::submitBackground(sf::Sprite* data)
{
    m_backgroundData.push_back(data);
}

void Renderer::submitSorted(sf::Sprite* data)
{
    m_sortedData.push_back(data);
}

void Renderer::submitPrimitive(sf::Vertex* draw, int count, sf::PrimitiveType type)
{
    Line line;// = {draw, count, type}; <- Fuck you MinGW!
    line.verts = draw;
    line.count = count;
    line.type = type;

    m_linesData.push_back(line);
}

void Renderer::submitForeground(sf::Sprite* data)
{
    m_foregroundData.push_back(data);
}

void Renderer::submitArray(sf::VertexArray* array, const sf::RenderStates& states)
{
    m_arrayData.push_back(std::make_pair(array, states));
}

void Renderer::submitOverlay(sf::RectangleShape* data)
{
    m_overRectData.push_back(data);
}

void Renderer::submitOverlay(sf::Sprite* data)
{
    m_overSpriteData.push_back(data);
}

void Renderer::submitOverlay(sf::Text* data)
{
    m_overTextData.push_back(data);
}

void Renderer::updateCamera()
{
    m_window->setView(m_camera);
}

void Renderer::cull()
{
    Rectf cameraRect(m_camera.getCenter().x - Screen::Get().halfWidth,
                     m_camera.getCenter().y - Screen::Get().halfHeight, 
                     Screen::Get().width,
                     Screen::Get().height);

    for (auto i = m_backgroundData.begin(); i != m_backgroundData.end();)
    { 
        sf::Sprite& current = **i;
        Rectf rect(current.getPosition().x,
                   current.getPosition().y,
                   current.getLocalBounds().width,
                   current.getLocalBounds().height);
        
        if (!Collision::AABBOverlap(rect, cameraRect))
        {
            i = m_backgroundData.erase(i);
        }
        else 
            i++;
    }
}

void Renderer::sort()
{
    std::sort(begin(m_sortedData), end(m_sortedData),
    [&](sf::Sprite* a, sf::Sprite* b)
    {
        return a->getPosition().y < b->getPosition().y;
    });
}

void Renderer::render()
{
    for (auto& i : m_backgroundData)
        m_window->draw(*i);

    for (auto& i : m_arrayData)
        m_window->draw(*i.first, i.second);

    for (auto& i : m_backCircleData)
        m_window->draw(*i);

    for (auto& i : m_sortedData)
        m_window->draw(*i);

    for (auto& i : m_foregroundData)
        m_window->draw(*i);

    for (auto& i : m_linesData)
        m_window->draw(i.verts, i.count, i.type);

    for (auto& i : m_overRectData)
        m_window->draw(*i);

    for (auto& i : m_overSpriteData)
        m_window->draw(*i);

    for (auto& i : m_overTextData)
        m_window->draw(*i);
}

void Renderer::flush()
{
    m_window->clear();
    updateCamera();
    cull();
    sort();
    render();
    clearAll();
    m_window->display();
}

void Renderer::clearAll()
{
    m_backgroundData.clear();
    m_backCircleData.clear();
    m_sortedData.clear();
    m_foregroundData.clear();

    m_arrayData.clear();

    m_linesData.clear();

    m_overRectData.clear();
    m_overSpriteData.clear();
    m_overTextData.clear();
}

void Renderer::setCameraPos(const vec2i& pos)
{
    m_camera.setCenter(pos.x, pos.y);
}

void Renderer::resetCameraPos()
{
    int hw = Screen::Get().halfWidth;
    int hh = Screen::Get().halfHeight;
    m_camera.setCenter(m_window->getSize().x/2, m_window->getSize().y/2);

    printf("%d %d\n", hw, hh);
}

vec2i Renderer::getCameraPos() const
{
    return vec2i(m_camera.getCenter().x - Screen::Get().halfWidth, m_camera.getCenter().y - Screen::Get().halfHeight);
}