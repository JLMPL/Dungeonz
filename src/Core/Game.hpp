#ifndef GAME_HPP
#define GAME_HPP
#include "../GameState/GameState.hpp"
#include <SFML/Graphics.hpp>

#ifdef _WIN32
#include <memory>
using uint = unsigned int;
#endif

class Game
{
    public:
        Game();
        ~Game();

        void update();
        void mainLoop();

        void loadCfg();

        void setState(GameState* state);
        void begForState(GameState* state);

    private:
        sf::RenderWindow Window;
        sf::Event        Event;
        sf::Clock        Clock;
        float            deltaTime = 0;

        sf::Clock Benchmark;
        int       bench_begin = 0;
        int       bench_end = 0;

        uint start = 0;
        uint end = 0;
        uint duration = 0;

        sf::Text version;
        
        // StateSplash m_splashState;
        // StatePlaying m_playingState;
        // StateMenu m_menuState;
        std::unique_ptr<GameState> m_currentState = nullptr;
        GameState* m_nextState = nullptr;
};

#endif
