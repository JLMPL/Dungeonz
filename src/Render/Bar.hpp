#ifndef BAR_HPP
#define BAR_HPP
#include "../Core/Vec2.hpp"
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/Text.hpp>

class Bar
{
    public:
        void init(const vec2i& size, const sf::Color& color);

        void update();

        void setPosition(const vec2i& pos);
        void setMaxValue(int max);
        void setValue(int val);
        void setShowStats(bool show);

        int getMaxValue();
        int getValue();
        vec2i getPosition();

    private:
        sf::RectangleShape m_bar;
        sf::RectangleShape m_bcg;
        vec2i m_position;

        int m_max = 0;
        int m_value = 0;

        bool m_showStats = false;
        sf::Text m_stats;
};

#endif
