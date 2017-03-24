#ifndef STATE_SPLASH_HPP
#define STATE_SPLASH_HPP
#include "GameState.hpp"
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/System/Clock.hpp>

class StateSplash : public GameState
{
    public:
        StateSplash();

        void init() override final;
        void update(float deltaTime) override final;
        void leave() override final;

    private:
        sf::Sprite m_sfmlLogo;
        sf::Sprite m_luaLogo;
        sf::Clock m_timer;

        int m_stage = 0;
};

#endif