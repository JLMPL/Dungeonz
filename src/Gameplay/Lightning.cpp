#include "Lightning.hpp"
#include "../Core/Dice.hpp"
#include "../Render/Renderer.hpp"

Lightning::Lightning()
{
}

void Lightning::init(const vec2f& start, const vec2f& end)
{
	m_start = start;
	m_end = end;

	sf::Color first(128, Dice::roll(192,255), 255);
	sf::Color second(128, Dice::roll(192,255), 255);

	for(int i = 0; i < 10; i++)
	{
		m_line[i].color = first;
		m_secLine[i].color = second;
	}

	compute();
}

void Lightning::update(float deltaTime)
{
	if (m_life.getElapsedTime().asMilliseconds() >= 200)
		destroy();

	if (m_timer.getElapsedTime().asMilliseconds() >= 100)
	{
		compute();
		m_timer.restart();
	}

	Renderer::Get().submitLine(m_line, 10, sf::LineStrip);
	Renderer::Get().submitLine(m_secLine, 10, sf::LineStrip);
}

void Lightning::compute()
{
	float what = 0;
	for(int i = 0; i < 10; i++)
	{
		m_line[i].position = lerp(m_start, m_end, what).getSfVecf();
		m_secLine[i].position = lerp(m_start, m_end + vec2f(0, Dice::roll(0, 8)), what).getSfVecf();
		what += 0.1;
	}

	for(int i = 1; i < 9; i++)
	{
		m_line[i].position += sf::Vector2f(Dice::roll(0,10) - 5, Dice::roll(0,10) - 5);
		m_secLine[i].position += sf::Vector2f(Dice::roll(0,10) - 5, Dice::roll(0,10) - 5);
	}
}