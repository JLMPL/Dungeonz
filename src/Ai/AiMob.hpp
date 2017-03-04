#ifndef AI_BAT_HPP
#define AI_BAT_HPP
#include "Ai.hpp"
#include "../Core/Vec2.hpp"
#include <SFML/System/Clock.hpp>

class Entity;

enum class MobState
{
	Idle,
	Move,
	Attack,
	Dead
};

class AiMob : public Ai
{
	public:
		void setup() override final;
		void update(float deltaTime) override final;
		void focus();

		void idleState(float deltaTime);
		void moveState(float deltaTime);
		void attackState(float deltaTime);
		void deadState(float deltaTime);
		
	private:
		Entity*   m_focus = nullptr;
		MobState  m_state;
		float     m_speed = 30;
		vec2f     m_direction;
		sf::Clock m_timer;
};


#endif