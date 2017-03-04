#ifndef SPELLBOOK_HPP
#define SPELLBOOK_HPP
#include "SpellOption.hpp"
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/System/Clock.hpp>
#include <vector>

class Living;

class Spellbook
{
	public:
		Spellbook();

		void update(float deltaTime);

		void setPosition(const vec2i& pos);
		void setTarget(Living* target);

	private:
		Living* m_target;
		vec2i m_position;

		sf::RectangleShape m_background;
		std::vector<SpellOption> m_options;

		int m_chosen = 0;
		sf::RectangleShape m_selection;
		sf::Clock m_timer;
};

#endif