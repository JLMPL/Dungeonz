#ifndef GAME_HPP
#define GAME_HPP
#include "../GameState/StatePlaying.hpp"
#include <SFML/Graphics.hpp>

class Game
{
	public:
		Game();
		~Game();

		void update();
		void mainLoop();

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
		
		StatePlaying m_playingState;
		GameState* m_currentState;
};

#endif
