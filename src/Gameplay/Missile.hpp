#ifndef MISSILE_HPP
#define MISSILE_HPP
#include "Entity.hpp"

class Missile : public Entity
{
	public:
		Missile();

		void init(vec2f origin, Direction_t dir, EntityType type);

		void update(float deltaTime) override final;
		void blow();

	private:
		Direction_t m_direction;
		vec2f m_velocity;
		float m_speed = 100;
};

#endif