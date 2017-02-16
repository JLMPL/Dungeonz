#ifndef GRAPHIC_LOOT_HPP
#define GRAPHIC_LOOT_HPP
#include "slot.hpp"
#include <SFML/System/Clock.hpp>

class Inventory;

class GraphicLoot
{
	public:
		GraphicLoot();

		void update();

		void reset();

		void setPosition(const vec2i& pos);
		void setInv(Inventory* inv);
		void setTargetInv(Inventory* inv);

	private:
		std::vector<Slot> m_slots;
		vec2i m_pos;
		Inventory* m_inv = nullptr;
		Inventory* m_tinv = nullptr;
		sf::Sprite m_select;
		int m_selected = 0;
		sf::Clock m_timer;
};

#endif