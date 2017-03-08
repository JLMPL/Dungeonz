#ifndef AI_PLAYER_HPP
#define AI_PLAYER_HPP
#include "Ai.hpp"
#include <SFML/System/Clock.hpp>

enum class PlayerState
{
	Moving = 0,
	Idle,
	Attack,
	Picking,
	Casting,
	Rolling
};

class Entity;

class AiPlayer : public Ai
{
	public:
		void setup() override final;
		void update(float deltaTime) override final;
		void focus();
		
		void movingState(float deltaTime);
		void idleState(float deltaTime);
		void attackState(float deltaTime);
		void pickingState(float deltaTime);
		void castState(float deltaTime);
		void rollState(float deltaTime);

		void castFireball();
		void castFrostbite();
		void castLightning(float deltaTime);
		void castSpeed();
		void castHeal();
		
		PlayerState getState();

	private:
		float       m_speed = 100;
		float 	    m_runSpeed = 120;
		float 	    m_walkSpeed = 50;
		Entity*     m_focus;
		sf::Clock   m_timer;
		PlayerState m_state;

		sf::Clock m_speedSpellTimer;
		bool	  m_speedSpellActive = false;

		sf::Clock m_manaRestoreTimer;
};

#endif
