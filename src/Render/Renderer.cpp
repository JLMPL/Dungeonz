#include "Renderer.hpp"
#include "Sprite.hpp"
#include "../Core/Error.hpp"
#include "../Core/Rect.hpp"
#include "../Collision/CollisionAlgorithm.hpp"
#include <SFML/Graphics.hpp>
#include <algorithm>

void Renderer::init(sf::RenderWindow* window)
{
	if(!window)
		ShowErrorBox("Failed to initialize renderer with window!");
	else
	{
		m_window = window;
		m_camera = sf::View(sf::Vector2f(0,0), sf::Vector2f(800,600));
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
	Rectf cameraRect(m_camera.getCenter().x - 400, m_camera.getCenter().y - 300, 800, 600);

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
	for(auto& i : m_backgroundData)
		m_window->draw(*i);

	for(auto& i : m_backCircleData)
		m_window->draw(*i);

	for(auto& i : m_sortedData)
		m_window->draw(*i);

	for(auto& i : m_overRectData)
		m_window->draw(*i);

	for(auto& i : m_overSpriteData)
		m_window->draw(*i);

	for(auto& i : m_overTextData)
		m_window->draw(*i);
}

void Renderer::flush()
{
	updateCamera();
	cull();
	sort();
	render();
	clearAll();
}

void Renderer::clearAll()
{
	m_backgroundData.clear();
	m_backCircleData.clear();
	m_sortedData.clear();

	m_overRectData.clear();
	m_overSpriteData.clear();
	m_overTextData.clear();
}

void Renderer::setCameraPos(const vec2i& pos)
{
	m_camera.setCenter(pos.x, pos.y);
}

vec2i Renderer::getCameraPos() const
{
	return vec2i(m_camera.getCenter().x - 400, m_camera.getCenter().y - 300);
}