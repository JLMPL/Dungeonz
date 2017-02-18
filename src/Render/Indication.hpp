#ifndef INDICATION_HPP
#define INDICATION_HPP
#include "Renderer.hpp"
#include "../Core/Vec2.hpp"
#include <SFML/Graphics/Text.hpp>

struct Indication
{
	sf::Text text;
	sf::Color color;
	float transparency = 255;

	Indication();
	Indication(const std::string& message, const sf::Color& col, const vec2f& pos);

	void draw();
};

#endif