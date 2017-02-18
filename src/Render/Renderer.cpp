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
	m_BackCircleData.push_back(data);
}

void Renderer::submitBackground(sf::Sprite* data)
{
	m_BackgroundData.push_back(data);
}

void Renderer::submitSorted(sf::Sprite* data)
{
	m_SortedData.push_back(data);
}

void Renderer::submitOverlay(sf::RectangleShape* data)
{
	m_OverRectData.push_back(data);
}

void Renderer::submitOverlay(sf::Sprite* data)
{
	m_OverSpriteData.push_back(data);
}

void Renderer::submitOverlay(sf::Text* data)
{
	m_OverTextData.push_back(data);
}

void Renderer::updateCamera()
{
	m_window->setView(m_camera);
}

void Renderer::cull()
{
	Rectf cameraRect(m_camera.getCenter().x - 400, m_camera.getCenter().y - 300, 800, 600);

	for (auto i = m_BackgroundData.begin(); i != m_BackgroundData.end();)
	{ 
		sf::Sprite& current = **i;
		Rectf rect(current.getPosition().x,
				   current.getPosition().y,
				   current.getLocalBounds().width,
				   current.getLocalBounds().height);
		
		if (!Collision::AABBOverlap(rect, cameraRect))
		{
			i = m_BackgroundData.erase(i);
		}
		else 
			i++;
	}
}

void Renderer::sort()
{
	std::sort(begin(m_SortedData), end(m_SortedData),
	[&](sf::Sprite* a, sf::Sprite* b)
	{
		return a->getPosition().y < b->getPosition().y;
	});
}

void Renderer::render()
{
	for(auto& i : m_BackgroundData)
		m_window->draw(*i);

	for(auto& i : m_BackCircleData)
		m_window->draw(*i);

	for(auto& i : m_SortedData)
		m_window->draw(*i);

	for(auto& i : m_OverRectData)
		m_window->draw(*i);

	for(auto& i : m_OverSpriteData)
		m_window->draw(*i);

	for(auto& i : m_OverTextData)
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
	m_BackgroundData.clear();
	m_BackCircleData.clear();
	m_SortedData.clear();

	m_OverRectData.clear();
	m_OverSpriteData.clear();
	m_OverTextData.clear();
}

void Renderer::setCameraPos(const vec2i& pos)
{
	m_camera.setCenter(pos.x, pos.y);
}

vec2i Renderer::getCameraPos() const
{
	return vec2i(m_camera.getCenter().x - 400, m_camera.getCenter().y - 300);
}