#ifndef ai_bat_hpp
#define ai_bat_hpp
#include "ai.hpp"
#include "../core/vec2.hpp"
#include <SFML/System/Clock.hpp>

class Entity;

class AIMob : public AI
{
	public:
		virtual void setup() override final;
		virtual void update(float deltaTime) override final;
	private:
		float   m_speed = 30;
		vec2f   m_direction;
		Entity* m_focus = nullptr;
		sf::Clock m_timer;
};


#endif