#ifndef SPELL_OPTION_HPP
#define SPELL_OPTION_HPP
#include "../Core/Vec2.hpp"
#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics/Sprite.hpp>

struct SpellOption
{
	sf::Sprite icon;
	sf::Text label;

	SpellOption();
	SpellOption(const std::string& _icon, const std::string& _label);

	void draw();
	void enable();
	void disable();

	void setPosition(const vec2i& pos);
};

#endif