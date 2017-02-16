#ifndef GRAPHIC_INV_HPP
#define GRAPHIC_INV_HPP
#include "slot.hpp"
#include "../render/bar.hpp"
#include <SFML/System/Clock.hpp>
#include <SFML/Graphics/Text.hpp>

class Inventory;
class Living;

class GraphicInv
{
	public:
		GraphicInv();

		void initDesc();
		void initStats();

		void update();
		void description();
		void stats();

		void setPosition(const vec2i& pos);
		void setInv(Inventory* inv);
		void setTarget(Living* player);

	private:
		std::vector<Slot> m_slots;
		vec2i             m_pos;
		vec2i             m_invPos;
		Inventory*        m_inv = nullptr;
		sf::Sprite        m_select;
		int               m_selected = 0;
		sf::Clock         m_timer;

		Living* m_player;

		vec2i m_desc_back_pos;
		sf::RectangleShape m_desc_back;
		sf::Text m_desc_name;
		sf::Text m_desc_type;
		sf::Text m_desc;

		vec2i m_stats_pos;
		sf::RectangleShape m_stats_bcg;

		sf::Text m_stats_level;
		Bar m_xp_bar;

		sf::Text m_stats_health;
		Bar m_health_bar;

		sf::Text m_stats_mana;
		Bar m_mana_bar;

		sf::Text m_stats_damage;
		sf::Text m_stats_defense;
};

#endif