#ifndef STATE_PLAYING_HPP
#define STATE_PLAYING_HPP
#include "GameState.hpp"
#include "../Gameplay/Level.hpp"

class Level;

class StatePlaying : public GameState
{
	public:
		StatePlaying();

		void init() override final;
		void update(float deltaTime) override final;
		void leave() override final;

		void setLevel(const std::string& level);

	private:
		Level m_level;

		std::unique_ptr<Level> m_currLevel;
};

#endif