#ifndef STATE_SCROLLING_HPP
#define STATE_SCROLLING_HPP
#include "GameState.hpp"
#include <SFML/Graphics/Text.hpp>
#include <SFML/System/Clock.hpp>

class StateScrolling : public GameState
{
    public:
        StateScrolling(bool laste = false);

        void init() override final;
        void update(float deltaTime) override final;
        void leave() override final;

    private:
        sf::Text m_text;
        sf::Clock m_timer;
        bool m_laste = false;

        sf::Text m_skip;
};

#endif