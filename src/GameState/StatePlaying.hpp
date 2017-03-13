#ifndef STATE_PLAYING_HPP
#define STATE_PLAYING_HPP
#include "GameState.hpp"
#include "../Gameplay/Level.hpp"

enum class TheLevel
{
	First,
	Second
};

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
		Level m_levelO;
		Level m_second;

		TheLevel m_current = TheLevel::First;
		std::unique_ptr<Level> m_level;
};

#endif