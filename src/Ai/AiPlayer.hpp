#ifndef AI_PLAYER_HPP
#define AI_PLAYER_HPP
#include "Ai.hpp"
#include <SFML/System/Clock.hpp>

enum class PlayerState
{
	MOVING = 0,
	IDLE,
	ATTACK,
	PICKING
};

class Entity;

class AIPlayer : public AI
{
	public:
		void setup() override final;
		void update(float deltaTime) override final;
		void focus();
		
		void movingState(float deltaTime);
		void idleState(float deltaTime);
		void attackState(float deltaTime);
		void pickingState(float deltaTime);

	private:
		float       m_speed = 100;
		float 	    m_runSpeed = 100;
		float 	    m_walkSpeed = 50;
		Entity*     m_focus;
		sf::Clock   m_timer;
		PlayerState m_state;
};

#endif