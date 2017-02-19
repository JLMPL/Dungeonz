#ifndef AI_BAT_HPP
#define AI_BAT_HPP
#include "Ai.hpp"
#include "../Core/Vec2.hpp"
#include <SFML/System/Clock.hpp>

class Entity;

enum class MobState
{
	IDLE,
	MOVE,
	ATTACK,
	DEAD
};

class AIMob : public AI
{
	public:
		void setup() override final;
		void update(float deltaTime) override final;

		void focus();
		
	private:
		Entity*   m_focus = nullptr;
		MobState  m_state;
		float     m_speed = 30;
		vec2f     m_direction;
		sf::Clock m_timer;
};


#endif