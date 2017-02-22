#ifndef MISSILE_HPP
#define MISSILE_HPP
#include "Entity.hpp"

class Missile : public Entity
{
	public:
		Missile();

		void init(vec2f origin, Direction_t dir, EntityType type);
		void setOwner(Entity* owner);

		void update(float deltaTime) override final;
		void blow(Entity* ent);

	private:
		Entity*     m_owner = nullptr;
		Direction_t m_direction;
		vec2f       m_velocity;
		float       m_speed = 200;
		sf::Clock   m_warmup;
};

#endif