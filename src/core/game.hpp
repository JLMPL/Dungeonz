#ifndef GAME_HPP
#define GAME_HPP
#include "../gameplay/level.hpp"
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
		sf::Event        Event;
		sf::Clock        Clock;
		float            deltaTime = 0;

		sf::Clock Benchmark;
		int       bench_begin = 0;
		int       bench_end = 0;

		uint start = 0;
		uint end = 0;
		uint duration = 0;

		Level level;

		sf::Text version;
};

#endif
