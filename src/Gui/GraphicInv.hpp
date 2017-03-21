#ifndef GRAPHIC_INV_HPP
#define GRAPHIC_INV_HPP
#include "Slot.hpp"
#include "../Render/Bar.hpp"
#include <SFML/System/Clock.hpp>
#include <SFML/Graphics/Text.hpp>

class Inventory;
class Living;

class GraphicInv
{
    public:
        GraphicInv();

        void init(int _width, int _height);

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

        int m_width = 0;
        int m_height = 0;

        Living* m_player;

        vec2i m_descBackPos;
        sf::RectangleShape m_descBack;
        sf::Text m_descName;
        sf::Text m_descType;
        sf::Text m_desc;

        vec2i m_statsPos;
        sf::RectangleShape m_statsBcg;

        sf::Text m_statsLevel;
        Bar m_xpBar;

        sf::Text m_statsHealth;
        Bar m_healthBar;

        sf::Text m_statsMana;
        Bar m_manaBar;

        sf::Text m_statsDamage;
        sf::Text m_statsDefense;
};

#endif