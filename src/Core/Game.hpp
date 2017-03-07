#ifndef GAME_HPP
#define GAME_HPP
#include "../GameState/StatePlaying.hpp"
#include "../GameState/StateSplash.hpp"
#include "../GameState/StateMenu.hpp"
#include <SFML/Graphics.hpp>

class Game
{
	public:
		Game();
		~Game();

		void update();
		void mainLoop();

		void loadCfg();

	private:
		sf::RenderWindow Window;
		sf::Event		 Event;
		sf::Clock		 Clock;
		float			 deltaTime = 0;

		sf::Clock Benchmark;
		int		  bench_begin = 0;
		int		  bench_end = 0;

		uint start = 0;
		uint end = 0;
		uint duration = 0;

		sf::Text version;
		
		StateSplash m_splashState;
		StatePlaying m_playingState;
		StateMenu m_menuState;
		GameState* m_currentState;
};

#endif
