#include "renderer.hpp"
#include "../core/error.hpp"
#include "../render/sprite.hpp"
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

void Renderer::submit(const RenderData& data, const RenderAttribute& att)
{
	switch(att)
	{
		case RenderAttribute::BACKGROUND:
			m_BackgroundData.push_back(data);
			break;
		case RenderAttribute::SORTED:
			m_SortedData.push_back(data);
			break;
		case RenderAttribute::OVERLAY:
			m_OverlayData.push_back(data);
			break;
	}
}

void Renderer::submit(sf::RectangleShape* data)
{
	m_RectData.push_back(data);
}

void Renderer::submito(sf::Sprite* data)
{
	m_SpriteData.push_back(data);
}

void Renderer::submit(sf::Text* data)
{
	m_TextData.push_back(data);
}

void Renderer::updateCamera()
{
	m_window->setView(m_camera);
}

void Renderer::sort()
{
	std::sort(begin(m_SortedData), end(m_SortedData),
	[&](const RenderData& a, const RenderData& b)
	{
		return a.z < b.z;
	});
}

void Renderer::render()
{
	for(auto& i : m_BackgroundData)
		m_window->draw(*(i.data));

	for(auto& i : m_SortedData)
		m_window->draw(*(i.data));

	for(auto& i : m_OverlayData)
		m_window->draw(*(i.data));

	for(auto& i : m_RectData)
		m_window->draw(*i);

	for(auto& i : m_SpriteData)
		m_window->draw(*i);

	for(auto& i : m_TextData)
		m_window->draw(*i);
}

void Renderer::flush()
{
	updateCamera();
	sort();
	render();
	clearAll();
}

void Renderer::clearAll()
{
	m_BackgroundData.clear();
	m_SortedData.clear();
	m_OverlayData.clear();

	m_RectData.clear();
	m_SpriteData.clear();
	m_TextData.clear();
}

void Renderer::setCameraPos(const vec2i& pos)
{
	m_camera.setCenter(pos.x, pos.y);
}

vec2i Renderer::getCameraPos() const
{
	return vec2i(m_camera.getCenter().x - 400, m_camera.getCenter().y - 300);
}